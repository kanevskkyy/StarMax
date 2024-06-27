//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Table_Customer.h"
#include "CustomerConection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
	String ClientName = Edit1->Text;
	String DateOfBirthStr = Edit3->Text;
	String PhoneNumber = Edit4->Text;
	TDateTime DateOfBirth;
	try
	{
		DateOfBirth = StrToDate(DateOfBirthStr);
	}
	catch (Exception &e)
	{
		ShowMessage("Incorrect date format. Use the format DD.ÌÌ.ÐÐÐÐÐÐ.");
		return;
	}
	if (ClientName.IsEmpty() || PhoneNumber.IsEmpty())
	{
		ShowMessage("Please fill in all the fields!");
		return;
	}
	ADOTCustomers->Append();
	ADOTCustomers->FieldByName("Client's full name")->AsString = ClientName;
	ADOTCustomers->FieldByName("Date of birth")->AsDateTime = DateOfBirth;
	ADOTCustomers->FieldByName("Phone number")->AsString = PhoneNumber;
	try
	{
		ADOTCustomers->Post();
		ShowMessage("The entry has been successfully added!");
		ADOTCustomers->Active=false;
		ADOTCustomers->Active=true;
		DBGrid1->Refresh();
		Edit1->Clear();
		Edit3->Clear();
		Edit4->Clear();
	}
	catch (Exception &e)
	{
		ADOTCustomers->Cancel();
		ShowMessage("Error adding a record: " + e.Message);
	}
}
//---------------------------------------------------------------------------

