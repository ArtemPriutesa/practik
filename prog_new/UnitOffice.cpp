//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOffice *FormOffice;
//---------------------------------------------------------------------------
__fastcall TFormOffice::TFormOffice(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::ButtonNewPolClick(TObject *Sender)
{
	if (AuthenticatedUserID != -1)
	{
		TFormNewPol *CreatePolicyForm = new TFormNewPol(this);
		try
		{
			if (CreatePolicyForm->ShowModal() == mrOk) {
			}
		}
		__finally
		{
			delete CreatePolicyForm;
		}
	}
	else
	{
		ShowMessage("Для створення нового договору необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::N3Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::ButtonMyPolyClick(TObject *Sender)
{
	if (AuthenticatedUserID != -1)
	{
		TFormMyPol *myPoliForm = new TFormMyPol(this);
		try
		{
			if (myPoliForm->ShowModal() == mrOk) {
			}
		}
		__finally
		{
			delete myPoliForm;
		}
	}
	else
	{
		ShowMessage("Для перегляду договорів необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::Button5Click(TObject *Sender)
{
	if (UserID != -1)
	{
		TFormMyCase *MyCasesForm = new TFormMyCase(this);
		try
		{
			MyCasesForm->ShowModal();
		}
		__finally
		{
			delete MyCasesForm;
		}
	}
	else
	{
		ShowMessage("Для перегляду страхових випадків необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::ButtonProfClick(TObject *Sender)
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
void __fastcall TFormOffice::ButtonHistClick(TObject *Sender)
{
	 if (UserID != -1)
	{
		TFormMyPay *MyPayForm = new TFormMyPay(this);
		try
		{
			MyPayForm->ShowModal();
		}
		__finally
		{
			delete MyPayForm;
		}
	}
	else
	{
		ShowMessage("Для перегляду історії необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::N2Click(TObject *Sender)
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
void __fastcall TFormOffice::FormCreate(TObject *Sender)
{
	ApplyStyle();
}
//---------------------------------------------------------------------------
void __fastcall TFormOffice::ButtonNoMyCaseClick(TObject *Sender)
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
void __fastcall TFormOffice::N1Click(TObject *Sender)
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

