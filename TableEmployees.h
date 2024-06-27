//---------------------------------------------------------------------------

#ifndef TableEmployeesH
#define TableEmployeesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TEdit *Edit1;
	TEdit *Edit3;
	TLabel *Label3;
	TADOConnection *ADOConnection2;
	TADOTable *ADOTEmployees;
	TDataSource *DataSource1;
	TButton *Button1;
	TLabel *Label2;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
