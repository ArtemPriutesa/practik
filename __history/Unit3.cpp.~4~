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
if (FormAuthorization->AuthenticatedUserID != -1)
	{
		// Створюємо екземпляр форми "Мої договори"
		TFormMyPolicies *MyPoliciesForm = new TFormMyPolicies(this);
		try
        {
            // Передаємо КодКористувача до форми "Мої договори"
			MyPoliciesForm->SetUserID(FormAuthorization->AuthenticatedUserID);

			// Показуємо форму "Мої договори" модально
            // Це означає, що користувач не зможе взаємодіяти з "Особистим кабінетом",
            // доки не закриє форму "Мої договори".
            MyPoliciesForm->ShowModal();

            // Після закриття MyPoliciesForm (за потреби):
            // if (MyPoliciesForm->ModalResult == mrOk) { ... }
        }
        __finally
        {
            delete MyPoliciesForm; // Завжди звільняємо пам'ять, якщо створювали з 'new'
        }
    }
    else
    {
        ShowMessage("Для перегляду договорів необхідно авторизуватися.");
        // Можливо, показати форму авторизації знову:
        // Form2->ShowModal();
	}
}
//---------------------------------------------------------------------------


