//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitProf.h"
#include "UnitAutor.h"
#include <Vcl.Dialogs.hpp>
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProf *FormProf;
//---------------------------------------------------------------------------
__fastcall TFormProf::TFormProf(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::LoadUserProfile()
{
	FUserID = UserID;
		if (FUserID == -1) {
		ShowMessage("Помилка: ID користувача не встановлено. Неможливо завантажити профіль.");
		return;
	}
	try {
		if (ADOQueryProf->Active) {
			ADOQueryProf->Close();
		}
        ADOQueryProf->SQL->Clear();
		ADOQueryProf->Parameters->Clear();
		ADOQueryProf->SQL->Add("SELECT U.ПІП, U.Роль, COUNT(P.КодДоговору) AS КількістьДоговорів ");
		ADOQueryProf->SQL->Add("FROM [User] AS U ");
		ADOQueryProf->SQL->Add("LEFT JOIN [Policy] AS P ON U.КодКористувача = P.КодКористувача ");
		ADOQueryProf->SQL->Add("WHERE U.КодКористувача = :UserID ");
		ADOQueryProf->SQL->Add("GROUP BY U.ПІП, U.Роль");

		ADOQueryProf->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQueryProf->Open();

		if (!ADOQueryProf->Eof) {
			EditName->Text = ADOQueryProf->Fields->FieldByName("ПІП")->AsString;
			EditStatus->Text = ADOQueryProf->Fields->FieldByName("Роль")->AsString;
			EditPolCount->Text = ADOQueryProf->Fields->FieldByName("КількістьДоговорів")->AsString;
		} else {
			ShowMessage("Дані про користувача з ID " + IntToStr(FUserID) + " не знайдено.");
			EditName->Text = "";
			EditStatus->Text = "";
			EditPolCount->Text = "0";
		}
	} catch (Exception &E) {
		ShowMessage("Помилка завантаження профілю користувача: " + E.Message);
	}
}
void __fastcall TFormProf::FormCreate(TObject *Sender)
{
	ApplyStyle();
    try
	{
		ADOConnectionProf->Connected = true;
        EditName->ReadOnly = true;
        EditStatus->ReadOnly = true;
		EditPolCount->ReadOnly = true;
	}
	catch (Exception &E)
	{
		ShowMessage("Помилка підключення до БД для 'Профілю': " + E.Message + "\nПеревірте шлях до бази даних та налаштування ADOConnectionProf.");
		ModalResult = mrCancel;
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQueryProf->Active) {
		ADOQueryProf->Close();
	}
	if (ADOConnectionProf->Connected) {
		ADOConnectionProf->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::FormShow(TObject *Sender)
{
	LoadUserProfile();
}
//---------------------------------------------------------------------------
