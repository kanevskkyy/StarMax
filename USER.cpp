#include <vcl.h>
#pragma hdrstop

#include "USER.h"
#include "USER_Employees.h"
#include "USER_Films.h"
#include "USER_Genres.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
TForm10 *Form10;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	TDateTime today = Date();
	UnicodeString todayStr = DateToStr(today);
	Label2->Caption = todayStr;
	MediaPlayer1->FileName = "D:\\Проект\\audio.mp3";
	MediaPlayer1->Open();
	MediaPlayer1->Notify = true;
	MediaPlayer1->Play();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	Label1->Caption = TimeToStr(Now());
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm3::Button6Click(TObject *Sender)
{
	MediaPlayer1->Stop();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	MediaPlayer1->Stop();
	this->Hide();
	TForm10 *form12 = new TForm10(this);
	form12->ShowModal();
	delete form12;
	this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	MediaPlayer1->Stop();
	this->Hide();
	TForm11 *form12 = new TForm11(this);
	form12->ShowModal();
	delete form12;
	this->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	MediaPlayer1->Stop();
	this->Hide();
	TForm12 *form12 = new TForm12(this);
	form12->ShowModal();
	delete form12;
	this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

