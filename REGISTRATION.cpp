//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "REGISTRATION.h"
#include "USER.h"
#include "CustomerConection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	String login=Edit2->Text;
	String password_first=Edit1->Text;
	String password_second=Edit3->Text;

	if ( login.IsEmpty() || password_first.IsEmpty() || password_second.IsEmpty())
	{
		Application->MessageBox(L"Please fill in all fields!", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	if(password_first!=password_second)
	{
		Application->MessageBox(L"Oops... passwords do not match. Please try again.", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	ADOTAccess->Append();
	ADOTAccess->FieldByName("Login")->AsString = login;
	ADOTAccess->FieldByName("Password")->AsString = password_first;
	ADOTAccess->FieldByName("Type of access")->AsString = "user";
	try
	{

		ADOTAccess->Post();
		ADOTAccess->Active = false;
		ADOTAccess->Active = true;
		Application->MessageBox(L"You are registered! Congratulations!", L"Result", MB_OK);
	}

	catch (Exception &e)
	{
		ADOTAccess->Cancel();
		ShowMessage("Error adding a record: " + e.Message);
	}

	this->Hide();
	TForm3 *form3 = new TForm3(this);
	form3->ShowModal();
	delete form3;
	this->Close();
}
//---------------------------------------------------------------------------

