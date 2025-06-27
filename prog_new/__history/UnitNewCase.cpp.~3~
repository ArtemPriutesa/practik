//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitNewCase.h"
#include "Global.h"
#include "UnitMyCase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewCase *FormNewCase;
//---------------------------------------------------------------------------
__fastcall TFormNewCase::TFormNewCase(TComponent* Owner)
	: TForm(Owner)
{
	FUserId=-1;
	idPol=-1;
}
//---------------------------------------------------------------------------
void __fastcall TFormNewCase::FormCreate(TObject *Sender)
{
	FUserId=UserID;
	DateTimePickerCase->Date = Date();

	ComboBoxPol->Items->Clear();
	ADOQueryPol->Close();
	ADOQueryPol->SQL->Clear();
	ADOQueryPol->Parameters->Clear();

	ADOQueryPol->SQL->Add("SELECT КодДоговору, ДатаПочатку FROM Policy WHERE КодКористувача = :UserID");
	ADOQueryPol->Parameters->ParamByName("UserID")->Value = UserID;

	try {
		ADOQueryPol->Open();

		while (!ADOQueryPol->Eof) {
			idPol = ADOQueryPol->FieldByName("КодДоговору")->AsInteger;
			TDateTime date = ADOQueryPol->FieldByName("ДатаПочатку")->AsDateTime;
			AnsiString display = "Договір #" + IntToStr(idPol) + " від " + DateToStr(date);

			ComboBoxPol->Items->AddObject(display, reinterpret_cast<TObject*>(idPol));

			ADOQueryPol->Next();
		}
	}
	catch (Exception &E) {
		ShowMessage("Помилка при завантаженні: " + E.Message);
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormNewCase::Button1Click(TObject *Sender)
{
	if (EditDescription->Text.Trim().IsEmpty()) {
		ShowMessage("Введіть опис страхового випадку.");
		return;
	}

	TDateTime date = DateTimePickerCase->Date;
	AnsiString desc = EditDescription->Text.Trim();

	try {
		if (ADOQueryNewCase->Active) ADOQueryNewCase->Close();
		ADOQueryNewCase->SQL->Clear();
		ADOQueryNewCase->Parameters->Clear();

		ADOQueryNewCase->SQL->Add(
			"INSERT INTO [Case] (КодДоговору, ДатаВипадку, Опис, СтатусВипадку) "
			"VALUES (:PolId, :Date, :Desc, 'Очікує розгляд')"
		);

		ADOQueryNewCase->Parameters->ParamByName("PolId")->Value = idPol;
		ADOQueryNewCase->Parameters->ParamByName("Date")->Value = date;
		ADOQueryNewCase->Parameters->ParamByName("Desc")->Value = desc;

		ADOQueryNewCase->ExecSQL();

		ShowMessage("Страховий випадок успішно подано!");
		Close();
	}
	catch (Exception &E) {
		ShowMessage("Помилка при збереженні: " + E.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormNewCase::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

