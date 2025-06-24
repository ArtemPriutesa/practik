#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyPolicies *FormMyPolicies;
//---------------------------------------------------------------------------
__fastcall TFormMyPolicies::TFormMyPolicies(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1; // Ініціалізуємо ID
}
//---------------------------------------------------------------------------

void TFormMyPolicies::SetUserID(int UserID)
{
    FUserID = UserID;
}
//---------------------------------------------------------------------------

void __fastcall TFormMyPolicies::FormCreate(TObject *Sender)
{
	 try
	{

		if (FUserID != -1) {

			ADOQueryMyPolicies->Parameters->ParamByName("UserID")->Value = FUserID;

			//  Відкриваємо запит
			ADOQueryMyPolicies->Open();

			// Після ADOQueryMyPolicies->Open(), TDBGrid автоматично відобразить дані,
			// оскільки він пов'язаний через DataSourceMyPolicies.
		} else {
			ShowMessage("Помилка: Код користувача не був переданий для відображення договорів.");
			// Можливо, закрити форму або приховати DBGrid
			ModalResult = mrCancel; // Закрити форму, якщо немає ID користувача
		}
	}
	catch (Exception &E)
	{
		// Обробка помилок підключення або SQL-запиту
		ShowMessage("Помилка при завантаженні моїх договорів: " + E.Message);
		// Додатково можна вивести SQL-запит для налагодження:
		// ShowMessage("SQL: " + ADOQueryMyPolicies->SQL->Text);
		// Якщо виникає помилка, закрити запит
		if (ADOQueryMyPolicies->Active) {
			ADOQueryMyPolicies->Close();
		}
		ModalResult = mrAbort; // Вказати, що форма закривається через помилку
	}


}
//---------------------------------------------------------------------------

void __fastcall TFormMyPolicies::FormClose(TObject *Sender, TCloseAction &Action)
{
	// Важливо: закривайте запити та з'єднання при закритті форми
	if (ADOQueryMyPolicies->Active) {
		ADOQueryMyPolicies->Close();
	}
	if (ADOConnectionMyPolicies->Connected) {
		ADOConnectionMyPolicies->Close();
	}
}
//---------------------------------------------------------------------------
