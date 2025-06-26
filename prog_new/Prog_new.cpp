//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitNewPol.cpp", FormNewPol);
USEFORM("UnitNewCase.cpp", FormNewCase);
USEFORM("UnitMyPol.cpp", FormMyPol);
USEFORM("UnitReg.cpp", FormReg);
USEFORM("UnitProf.cpp", FormProf);
USEFORM("UnitOffice.cpp", FormOffice);
USEFORM("UnitMyCase.cpp", FormMyCase);
USEFORM("UnitAutor.cpp", FormAutor);
USEFORM("UnitMyPay.cpp", FormMyPay);
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
		Application->CreateForm(__classid(TFormMyPay), &FormMyPay);
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
