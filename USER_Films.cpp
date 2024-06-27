//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USER_Films.h"
#include "USER.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button1Click(TObject *Sender)
{
   this->Hide();
   TForm3 *form2 = new TForm3(this);
   form2->ShowModal();
   delete form2;
   this->Show();
}
//---------------------------------------------------------------------------

