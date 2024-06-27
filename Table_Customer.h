//---------------------------------------------------------------------------

#ifndef Table_CustomerH
#define Table_CustomerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:
	TDBGrid *DBGrid1;
	TEdit *Edit1;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTCustomers;
	TDataSource *DataSource1;
	TImage *Image1;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label3;
	void __fastcall Button1Click(TObject *Sender);
private:
public:
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
