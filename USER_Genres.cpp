//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USER_Genres.h"
#include "USER.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm12::Button1Click(TObject *Sender)
{
   this->Hide();
   TForm3 *form2 = new TForm3(this);
   form2->ShowModal();
   delete form2;
   this->Show();
}
//---------------------------------------------------------------------------

