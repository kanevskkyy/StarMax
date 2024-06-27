//---------------------------------------------------------------------------

#ifndef TableFilmsH
#define TableFilmsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TEdit *Edit1;
	TLabel *Label5;
	TLabel *Label7;
	TEdit *Edit6;
	TLabel *Label8;
	TEdit *Edit7;
	TLabel *Label9;
	TEdit *Edit8;
	TLabel *Label10;
	TEdit *Edit9;
	TEdit *Edit4;
	TButton *Button2;
	TADOConnection *ADOConnection3;
	TADOTable *ADOTFilms;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label11;
	TLabel *Label12;

	void __fastcall Button2Click(TObject *Sender);
private:	AnsiString selectedPhotoPath;
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
