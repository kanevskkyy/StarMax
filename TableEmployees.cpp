//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableEmployees.h"
#include "CustomerConection.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{

	String EmployeesName = Edit3->Text;
	String Position_of_worker = Edit1->Text;

	if ( EmployeesName.IsEmpty() || Position_of_worker.IsEmpty())
	{
		ShowMessage("Please fill in all the fields!");
		return;
	}

	ADOTEmployees->Append();
	ADOTEmployees->FieldByName("Employee's full name")->AsString = EmployeesName;
	ADOTEmployees->FieldByName("Employee's position")->AsString = Position_of_worker;
	try
	{
		ADOTEmployees->Post();
		Application->MessageBox(L"The entry has been successfully added!", L"Rezult", MB_OK);
        ADOTEmployees->Active = false;
		ADOTEmployees->Active = true;
		DBGrid1->Refresh();
		Edit1->Clear();
		Edit3->Clear();
	}
	catch (Exception &e)
	{
		ADOTEmployees->Cancel();
		ShowMessage("Error adding a record: " + e.Message);
	}
}
//---------------------------------------------------------------------------
