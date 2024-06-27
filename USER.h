//---------------------------------------------------------------------------

#ifndef USERH
#define USERH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.MPlayer.hpp>
#include "USER_Employees.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTimer *Timer1;
	TLabel *Label1;
	TLabel *Label2;
	TMediaPlayer *MediaPlayer1;
	TButton *Button6;
	TButton *Button4;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	TImage *BackgroundImage;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
extern TForm10 *Form10Instance;
//---------------------------------------------------------------------------
#endif
