//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitAutor.cpp", FormAutor);
USEFORM("UnitReg.cpp", FormReg);
USEFORM("UnitOffice.cpp", FormOffice);
USEFORM("UnitNewPol.cpp", FormNewPol);
USEFORM("UnitMyPol.cpp", FormMyPol);
USEFORM("UnitMyCase.cpp", FormMyCase);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormAutor), &FormAutor);
		Application->CreateForm(__classid(TFormReg), &FormReg);
		Application->CreateForm(__classid(TFormOffice), &FormOffice);
		Application->CreateForm(__classid(TFormNewPol), &FormNewPol);
		Application->CreateForm(__classid(TFormMyPol), &FormMyPol);
		Application->CreateForm(__classid(TFormMyCase), &FormMyCase);
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
