//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma resource "*.dfm"
TFormОffice *FormОffice;
//---------------------------------------------------------------------------
__fastcall TFormОffice::TFormОffice(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormОffice::Button1Click(TObject *Sender)
{
if (FormAuthorization->AuthenticatedUserID != -1)
    {
        TFormMyPolicies *MyPoliciesForm = new TFormMyPolicies(this);
        try
        {
			MyPoliciesForm->SetUserID(FormAuthorization->AuthenticatedUserID);
			MyPoliciesForm->ShowModal();
		}
        __finally
        {
			delete MyPoliciesForm;
        }
	}
    else
    {
        ShowMessage("Для перегляду договорів необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormОffice::Button2Click(TObject *Sender)
{

	if (AuthenticatedUserID != -1)
	{

		TFormCreatePolicy *CreatePolicyForm = new TFormCreatePolicy(this);
        try
        {

			CreatePolicyForm->SetUserID(AuthenticatedUserID);


            if (CreatePolicyForm->ShowModal() == mrOk) {

                ShowMessage("Новий договір успішно створено!");

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

