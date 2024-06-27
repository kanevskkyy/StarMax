//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "AVTORISATION.h"
#include "REGISTRATION.h"
#include "ADMINISTRATION.h"
#include "CustomerConection.h"
#include "USER.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	BackgroundImage = new TImage(this);
	BackgroundImage->Parent = this;
	BackgroundImage->Align = alClient;
	BackgroundImage->Stretch = true;
	BackgroundImage->Picture->LoadFromFile("D:\\Проект\\convert.jpg");
	BackgroundImage->SendToBack();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label6Click(TObject *Sender)
{
   ShellExecute(0, L"open", L"https://starmax.me/pravyla/", NULL, NULL, SW_SHOWNORMAL);
}//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)	Button1->Enabled = true;
	else Button1->Enabled=false;
}
//----------------------------------------------------------------------------
void __fastcall TForm1::Label5Click(TObject *Sender)
{
   if(CheckBox1->Checked==true) CheckBox1->Checked=false;
   else CheckBox1->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label8Click(TObject *Sender)
{
   this->Hide();
  TForm2 *form2 = new TForm2(this);
  form2->ShowModal();
  delete form2;
  this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	String login = Edit2->Text.Trim();
	String password = Edit1->Text.Trim();

	if (login.IsEmpty() || password.IsEmpty())
	{
		Application->MessageBox(L"Please fill in all fields! ", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	bool isValid = false;
	String accessType;
	TADOQuery *query = new TADOQuery(NULL);
	try
	{

		query->Connection = ADOConnection1;
		query->SQL->Text = "SELECT [Type of access] FROM Access WHERE [Login] = :Login AND [Password] = :Password";
		query->Parameters->ParamByName("Login")->Value = login;
		query->Parameters->ParamByName("Password")->Value = password;
		query->Open();
		if (!query->Eof)
		{
			isValid = true;
			accessType = query->FieldByName("Type of access")->AsString;
		}
	}

	__finally
    {
		delete query;
	}
	if (isValid)
	{

		this->Hide();
        if (accessType == "admin")
		{
			this->Hide();
			TForm4 *form4 = new TForm4(this);
			form4->ShowModal();
			delete form4;
			this->Close();
		}

		else if (accessType == "user")
		{
			this->Hide();
			TForm3 *form300 = new TForm3(this);
			form300->ShowModal();
			delete form300;
			this->Close();
		}
		this->Close();
	}

	else
	{
		Application->MessageBox(L"The password/login is incorrect. Please try again.", L"Error", MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

