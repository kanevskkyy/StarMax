//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableFilms.h"
#include "CustomerConection.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
    String FilmName = Edit1->Text;
    String GenreNameStr = Edit4->Text;
	String MovieLength = Edit6->Text;
	String AgeThreshold = Edit7->Text;
	String YearEdition = Edit8->Text;
	String Country = Edit9->Text;
	if (FilmName.IsEmpty() || GenreNameStr.IsEmpty() || MovieLength.IsEmpty() ||
		AgeThreshold.IsEmpty() || YearEdition.IsEmpty() || Country.IsEmpty())
	{
		ShowMessage("Please fill in all the fields!");
		return;
	}
	int GenreID = -1;
    try
    {
        GenreID = StrToInt(GenreNameStr);
    }
    catch (EConvertError &e)
    {
		ShowMessage("Please enter a numeric value for the genre code");
        return;
	}
    TADOQuery *query = new TADOQuery(NULL);
    try
    {
        query->Connection = ADOConnection3;
        query->SQL->Text = "SELECT [Genre code] FROM Genres WHERE [Genre code] = :GenreCode";
        query->Parameters->ParamByName("GenreCode")->Value = GenreID;
		query->Open();
        if (query->Eof)
		{
			ShowMessage("Genre not found!");
            delete query;
            return;
        }
    }
    __finally
    {
        delete query;
	}
    try
    {
        ADOTFilms->Append();
        ADOTFilms->FieldByName("Movie title")->AsString = FilmName;
        ADOTFilms->FieldByName("Film genre")->AsInteger = GenreID;
        ADOTFilms->FieldByName("Length of the film")->AsString = MovieLength;
        ADOTFilms->FieldByName("Film age threshold")->AsString = AgeThreshold;
        ADOTFilms->FieldByName("Year of release")->AsString = YearEdition;
		ADOTFilms->FieldByName("Country")->AsString = Country;
        try
		{
			ADOTFilms->Post();
			Application->MessageBox(L"The entry has been successfully added!", L"Rezult", MB_OK);
			ADOTFilms->Active=false;
			ADOTFilms->Active = true;
			DBGrid1->Refresh();
			Edit1->Clear();
			Edit4->Clear();
			Edit6->Clear();
			Edit7->Clear();
			Edit8->Clear();
			Edit9->Clear();
        }
		catch (Exception &e)
        {
			ADOTFilms->Cancel();
			ShowMessage("Error adding a record: " + e.Message);
		}
	}
    catch (Exception &e)
	{
		ShowMessage("Error: " + e.Message);
	}
}

