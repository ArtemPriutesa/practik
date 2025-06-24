//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\Unit4.cpp", FormMyPolicies);
USEFORM("..\Unit5.cpp", FormCreatePolicy);
USEFORM("..\Unit3.cpp", FormÎffice);
USEFORM("..\Unit1.cpp", Form1);
USEFORM("..\Unit2.cpp", FormAuthorization);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormAuthorization), &FormAuthorization);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFormÎffice), &FormÎffice);
		Application->CreateForm(__classid(TFormMyPolicies), &FormMyPolicies);
		Application->CreateForm(__classid(TFormCreatePolicy), &FormCreatePolicy);
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
