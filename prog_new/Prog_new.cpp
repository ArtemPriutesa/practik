//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitNewPol.cpp", FormNewPol);
USEFORM("UnitOffice.cpp", FormOffice);
USEFORM("UnitProf.cpp", FormProf);
USEFORM("UnitReg.cpp", FormReg);
USEFORM("UnitMyPol.cpp", FormMyPol);
USEFORM("UnitAutor.cpp", FormAutor);
USEFORM("UnitMyCase.cpp", FormMyCase);
USEFORM("UnitNewCase.cpp", FormNewCase);
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
		Application->CreateForm(__classid(TFormProf), &FormProf);
		Application->CreateForm(__classid(TFormNewCase), &FormNewCase);
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
