//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ADMINISTRATION.h"
#include "Table_Customer.h"
#include "TableEmployees.h"
#include "TableFilms.h"
#include "TableGenres.h"
#include "TableTickets.h"
#include "TableAccess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	TDateTime today = Date();
	UnicodeString todayStr = DateToStr(today);
	Label1->Caption = todayStr;
    MediaPlayer1->FileName = "D:\\Проект\\admin.mp3";
	MediaPlayer1->Open();
	MediaPlayer1->Notify = true;
	MediaPlayer1->Play();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
	Label2->Caption = TimeToStr(Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
	MediaPlayer1->Stop();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
  MediaPlayer1->Stop();
  this->Hide();
  TForm5 *form2 = new TForm5(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
  MediaPlayer1->Stop();
  this->Hide();
  TForm6 *form2 = new TForm6(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
  MediaPlayer1->Stop();
  this->Hide();
  TForm7 *form2 = new TForm7(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
  MediaPlayer1->Stop();
  this->Hide();
  TForm8 *form2 = new TForm8(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
   MediaPlayer1->Stop();
  this->Hide();
  TForm9 *form2 = new TForm9(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button8Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
    MediaPlayer1->Stop();
  this->Hide();
  TForm13 *form2 = new TForm13(this);
  form2->ShowModal();
  delete form2;
  this->Show();
}
//---------------------------------------------------------------------------

