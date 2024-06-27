//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableTickets.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject *Sender)
{
	String PurchaseDate = Edit2->Text;
	String EmployeeCode = Edit3->Text;
	String ClientCode = Edit4->Text;
	String FilmCode = Edit5->Text;
	String TicketPrice = Edit7->Text;
	String SeatNumber = Edit6->Text;


	TDateTime Date;
	try
	{
		Date = StrToDate(PurchaseDate);
	}
	catch (Exception &e)
	{
		ShowMessage("Incorrect date format. Use the format DD.ÌÌ.ÐÐÐÐÐÐ.");
		return;
	}

    if (PurchaseDate.IsEmpty() || EmployeeCode.IsEmpty() || ClientCode.IsEmpty() ||
        FilmCode.IsEmpty() || TicketPrice.IsEmpty() || SeatNumber.IsEmpty())
    {
		ShowMessage("Please fill in all the fields!");
        return;
    }

    TADOQuery *query = new TADOQuery(NULL);
    try
    {
        query->Connection = ADOConnection3;
        int EmployeeID = -1;
        int ClientID = -1;
        int MovieID = -1;


        query->SQL->Text = "SELECT [Employee code] FROM Employees WHERE [Employee code] = :EmployeeCode";
        query->Parameters->ParamByName("EmployeeCode")->Value = EmployeeCode;
        query->Open();
        if (!query->Eof)
        {
            EmployeeID = query->FieldByName("Employee code")->AsInteger;
        }
        else
        {
			ShowMessage("Employee not found!");
            delete query;
            return;
        }
        query->Close();


        query->SQL->Text = "SELECT [Client code] FROM Customers WHERE [Client code] = :ClientCode";
        query->Parameters->ParamByName("ClientCode")->Value = ClientCode;
        query->Open();
        if (!query->Eof)
        {
            ClientID = query->FieldByName("Client code")->AsInteger;
        }
        else
        {
			ShowMessage("Client not found!");
            delete query;
            return;
        }
        query->Close();


        query->SQL->Text = "SELECT [Movie code] FROM Films WHERE [Movie code] = :FilmCode";
        query->Parameters->ParamByName("FilmCode")->Value = FilmCode;
        query->Open();
        if (!query->Eof)
        {
            MovieID = query->FieldByName("Movie code")->AsInteger;
        }
        else
        {
			ShowMessage("Movie not found!");
			delete query;
            return;
        }
        query->Close();

        if (!ADOTTickets->Active)
        {
            ADOTTickets->Open();
        }


		ADOTTickets->Append();
        ADOTTickets->FieldByName("Date of ticket purchase")->AsString = PurchaseDate;
		ADOTTickets->FieldByName("Employee code")->AsString = EmployeeCode;
		ADOTTickets->FieldByName("Client code")->AsString = ClientCode;
		ADOTTickets->FieldByName("Movie code")->AsString = FilmCode;
		ADOTTickets->FieldByName("Ticket price")->AsString = TicketPrice;
        ADOTTickets->FieldByName("Seat in the hall")->AsString = SeatNumber;

        try
        {
			ADOTTickets->Post();
			Application->MessageBox(L"The entry has been successfully added!", L"Rezult", MB_OK);
			ADOTTickets->Active=false;
			ADOTTickets->Active=true;
			DBGrid1->Refresh();
			Edit2->Clear();
			Edit3->Clear();
			Edit4->Clear();
			Edit5->Clear();
			Edit6->Clear();
			Edit7->Clear();
        }
		catch (Exception &e)
        {
            ADOTTickets->Cancel();
			ShowMessage("Error adding a record: " + e.Message);
        }
	}
    catch (Exception &e)
    {
        ShowMessage("Error: " + e.Message);
	}
}


