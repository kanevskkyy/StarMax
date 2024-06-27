//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Table_Customer.cpp", Form5);
USEFORM("TableTickets.cpp", Form9);
USEFORM("TableGenres.cpp", Form8);
USEFORM("USER.cpp", Form3);
USEFORM("USER_Genres.cpp", Form12);
USEFORM("USER_Films.cpp", Form11);
USEFORM("USER_Employees.cpp", Form10);
USEFORM("TableFilms.cpp", Form7);
USEFORM("CustomerConection.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("AVTORISATION.cpp", Form1);
USEFORM("ADMINISTRATION.cpp", Form4);
USEFORM("TableEmployees.cpp", Form6);
USEFORM("REGISTRATION.cpp", Form2);
USEFORM("TableAccess.cpp", Form13);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Ruby Graphite");
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
