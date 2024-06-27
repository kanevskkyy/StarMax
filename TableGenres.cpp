//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableGenres.h"
#include "CustomerConection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	String GenreName = Edit1->Text;
	if (GenreName.IsEmpty())
	{
		ShowMessage("Please fill in all the fields!");
		return;
	}
	ADOTGenres->Append();
	ADOTGenres->FieldByName("Genre name")->AsString = GenreName;
	try
	{
		ADOTGenres->Post();
		Application->MessageBox(L"The entry has been successfully added!", L"Rezult", MB_OK);
		ADOTGenres->Active=false;
		ADOTGenres->Active = true;
		DBGrid1->Refresh();
		Edit1->Clear();
	}
	catch (Exception &e)
	{
		ADOTGenres->Cancel();
		ShowMessage("Error adding a record: " + e.Message);
	}
}
//---------------------------------------------------------------------------
