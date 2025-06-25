//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	try
	{
		ADOConnection1->Connected = true;
    }
	catch (Exception &E)
    {
        ShowMessage("Помилка підключення до БД для реєстрації: " + E.Message);
		Application->Terminate();
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	if (ADOConnection1->Connected) {
        ADOConnection1->Close();
	}
}
//---------------------------------------------------------------------------
 bool TForm1::IsLoginExists(const AnsiString& login)
{
	bool exists = false;
	if (!ADOConnection1->Connected) {
		ShowMessage("Помилка: З'єднання з базою даних відсутнє.");
		return true;
	}

	try
	{
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}

		ADOQuery1->SQL->Clear();

		ADOQuery1->SQL->Add("SELECT COUNT(*) FROM [User] WHERE Логін = :Логін");

		ADOQuery1->Parameters->ParamByName("Логін")->Value = login;

		ADOQuery1->Open();

		if (!ADOQuery1->Eof) {

			if (ADOQuery1->Fields->Fields[0]->AsInteger > 0) {
				exists = true;
			}
		}
	}
	catch (Exception &E)
    {
		ShowMessage("Помилка перевірки логіна: " + E.Message);
		exists = true;
	}

	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	return exists;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString pip = EditPIP->Text.Trim();
	AnsiString login = EditLog->Text.Trim();
	AnsiString password = EditPas->Text;
	AnsiString confirmPassword = EditPas2->Text;
    AnsiString role = "клієнт";

    if (pip.IsEmpty() || login.IsEmpty() || password.IsEmpty() || confirmPassword.IsEmpty()) {
		ShowMessage("Будь ласка, заповніть всі обов'язкові поля .");
        return;
    }

	if (password != confirmPassword) {
		ShowMessage("Паролі не співпадають.");
		EditPas->Clear();
		EditPas2->Clear();
		EditPas->SetFocus();
		return;
	}

	if (password.Length() < 4) {
		ShowMessage("Пароль має бути не менше 4 символів.");
		return;
    }

    if (IsLoginExists(login)) {
		ShowMessage("Користувач з таким логіном вже існує.");
		EditLog->Clear();
		EditLog->SetFocus();
		return;
    }

    try
    {
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO [User] (ПІП, Логін, Пароль, Роль) VALUES (:PIP, :Login, :Password, :Role)");

		ADOQuery1->Parameters->ParamByName("PIP")->Value = pip;
		ADOQuery1->Parameters->ParamByName("Login")->Value = login;
		ADOQuery1->Parameters->ParamByName("Password")->Value = password;
		ADOQuery1->Parameters->ParamByName("Role")->Value = role;

		ADOQuery1->ExecSQL();

        ShowMessage("Реєстрація успішна! Ласкаво просимо, " + login + "!");

        ModalResult = mrOk;
    }
    catch (Exception &E)
    {
        ShowMessage("Помилка під час реєстрації: " + E.Message);
    }
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
}




void __fastcall TForm1::Button2Click(TObject *Sender)
{
	FormAuthorization->Show();
	Hide();
}
//---------------------------------------------------------------------------

