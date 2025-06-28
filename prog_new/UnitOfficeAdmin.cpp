//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitOfficeAdmin.h"
#include "UnitOffice.h"
#include "UnitReg.h"
#include "UnitAutor.h"
#include "UnitNewPol.h"
#include "UnitMyPol.h"
#include "UnitMyCase.h"
#include "UnitProf.h"
#include "Global.h"
#include "UnitMyPay.h"
#include "UnitSett.h"
#include "UnitCaseAdmin.h"
#include "UnitReport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOfficeAdmin *FormOfficeAdmin;
//---------------------------------------------------------------------------
__fastcall TFormOfficeAdmin::TFormOfficeAdmin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficeAdmin::Button1Click(TObject *Sender)
{
    if (FormAutor->AuthenticatedUserID != -1)
	{
		TFormProf *ProfileForm = new TFormProf(this);
        try
		{
            ProfileForm->ShowModal();
		}
		__finally
		{
			delete ProfileForm;
		}
    }
    else
	{
        ShowMessage("Для перегляду профілю необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficeAdmin::Button3Click(TObject *Sender)
{
	if (UserID != -1)
	{
		TFormCasesAdmin *AdmForm = new TFormCasesAdmin(this);
		try
		{
			AdmForm->ShowModal();
		}
		__finally
		{
			delete AdmForm;
		}
	}
	else
	{
		ShowMessage("Для перегляду необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficeAdmin::Button2Click(TObject *Sender)
{
	FormReport = new TFormReport(this);
	FormReport->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficeAdmin::Button4Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TFormOfficeAdmin::FormCreate(TObject *Sender)
{
	 ApplyStyle();
}
//---------------------------------------------------------------------------

void __fastcall TFormOfficeAdmin::N1Click(TObject *Sender)
{
    if (UserID != -1)
	{
		TFormSett *SetForm = new TFormSett(this);
		try
		{
			SetForm->ShowModal();
		}
		__finally
		{
			delete SetForm;
		}
	}
	else
	{
		ShowMessage("Для перегляду налаштувань необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------

