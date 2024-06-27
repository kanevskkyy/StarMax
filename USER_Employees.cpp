//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USER_Employees.h"
#include "CustomerConection.h"
#include "USER.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3Instance;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button1Click(TObject *Sender)
{
	this->Hide();
	Form3->Show();
}
//---------------------------------------------------------------------------

