// Unit1.h
//---------------------------------------------------------------------------

#ifndef AVTORISATIONH
#define AVTORISATIONH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.MPlayer.hpp> // Додаємо цей заголовок для TImage
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit2;
	TEdit *Edit1;
	TCheckBox *CheckBox1;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button1;
	TLabel *Label7;
	TLabel *Label8;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTAccess;
	TDataSource *DataSource1;
	void __fastcall Label6Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall Label8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	TImage *BackgroundImage; // Додаємо оголошення компонента TImage

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
