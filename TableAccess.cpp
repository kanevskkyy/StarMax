//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableAccess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button1Click(TObject *Sender)
{
	String Login = Edit1->Text;
	String Password = Edit2->Text;
	if (Login.IsEmpty() || Password.IsEmpty())
	{
		ShowMessage("Please fill in all the fields!");
        return;
	}
	ADOTAccess->Append();
	ADOTAccess->FieldByName("Login")->AsString = Login;
	ADOTAccess->FieldByName("Password")->AsString = Password;
	ADOTAccess->FieldByName("Type of access")->AsString = "admin";
	try
	{
		ADOTAccess->Post();
		ADOTAccess->Active=false;
		ADOTAccess->Active = true;
		DBGrid1->Refresh();
		Application->MessageBox(L"The entry has been successfully added!", L"Rezult", MB_OK);
	}
	catch (Exception &e)
	{
		ADOTAccess->Cancel();
		ShowMessage("Error adding a record: " + e.Message);
	}
}
//---------------------------------------------------------------------------
