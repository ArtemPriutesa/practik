//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
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
if (FormAuthorization->AuthenticatedUserID != -1) // Перевіряємо, чи користувач авторизований
    {
        TFormMyPolicies *MyPoliciesForm = new TFormMyPolicies(this);
        try
        {
			MyPoliciesForm->SetUserID(FormAuthorization->AuthenticatedUserID); // Передаємо ID користувача
            MyPoliciesForm->ShowModal(); // Показуємо форму модально
		}
        __finally
        {
            delete MyPoliciesForm; // Завжди видаляємо об'єкт форми після використання
        }
	}
    else
    {
        ShowMessage("Для перегляду договорів необхідно авторизуватися.");
	}
}
//---------------------------------------------------------------------------


