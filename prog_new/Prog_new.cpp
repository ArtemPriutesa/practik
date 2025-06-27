//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UnitNewPol.cpp", FormNewPol);
USEFORM("UnitNewCase.cpp", FormNewCase);
USEFORM("UnitMyPol.cpp", FormMyPol);
USEFORM("UnitOffice.cpp", FormOffice);
USEFORM("UnitSett.cpp", FormSett);
USEFORM("UnitReg.cpp", FormReg);
USEFORM("UnitProf.cpp", FormProf);
USEFORM("UnitMyPay.cpp", FormMyPay);
USEFORM("UnitMyCase.cpp", FormMyCase);
USEFORM("UnitAutor.cpp", FormAutor);
USEFORM("UnitCaseAdmin.cpp", FormCasesAdmin);
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
		Application->CreateForm(__classid(TFormSett), &FormSett);
		Application->CreateForm(__classid(TFormCasesAdmin), &FormCasesAdmin);
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
