//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include <System.DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCreatePolicy *FormCreatePolicy;
//---------------------------------------------------------------------------
__fastcall TFormCreatePolicy::TFormCreatePolicy(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
double __fastcall TFormCreatePolicy::CalculateBaseRate()
{
	AnsiString selectedType = ComboBoxType->Text;
    int years = 0;
	try {
        years = StrToInt(EditTermYears->Text);
        if (years < 0) years = 0;
	} catch (Exception &E) {
        years = 0;
    }

    double calculatedRate = 0;

    if (selectedType == "Автострахування") {
        calculatedRate = 1000.0 * years;
    } else if (selectedType == "Страхування життя") {
        calculatedRate = 2000.0 * years;
    }
    return calculatedRate;
}
void __fastcall TFormCreatePolicy::FormCreate(TObject *Sender)
{
	try
    {
        ADOConnectionCreatePolicy->Connected = true;

        // Встановлюємо значення за замовчуванням
		ComboBoxType->ItemIndex = 0; // За замовчуванням "Автострахування" (перший елемент)
        DTPStartDate->Date = Date(); // Поточна дата
        EditTermYears->Text = "1"; // Термін за замовчуванням 1 рік

        // Оновлюємо дату закінчення на основі початкових значень
        UpdateEndDate();
        // Базова ставка тепер не відображається, її розрахунок буде в ButtonCreateClick
    }
    catch (Exception &E)
	{
        ShowMessage("Помилка підключення до БД для створення договору: " + E.Message);
        Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (ADOQueryCreatePolicy->Active) {
        ADOQueryCreatePolicy->Close();
    }
    if (ADOConnectionCreatePolicy->Connected) {
        ADOConnectionCreatePolicy->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCreatePolicy::UpdateEndDate()
{
    try {
		int years = StrToInt(EditTermYears->Text);
        if (years < 0) {
            years = 0;
            EditTermYears->Text = "0";
        }
		DTPEndDate->Date = IncYear(DTPStartDate->Date, years);
		// Базова ставка тут більше не оновлюється візуально
	} catch (Exception &E) {
		DTPEndDate->Date = DTPStartDate->Date;
	}
}

void __fastcall TFormCreatePolicy::DTPStartDateChange(TObject *Sender)
{
    UpdateEndDate();
}
void __fastcall TFormCreatePolicy::EditTermYearsChange(TObject *Sender)
{
    if (!EditTermYears->Text.IsEmpty()) {
        UpdateEndDate();
    } else {
        DTPEndDate->Date = DTPStartDate->Date;
    }
}
void __fastcall TFormCreatePolicy::ComboBoxTypeChange(TObject *Sender)
{
	UpdateBaseRate(); // Оновлюємо базову ставку при зміні типу
}
void __fastcall TFormCreatePolicy::ButtonCreateClick(TObject *Sender)
{
	AnsiString type = ComboBoxType->Text.Trim();
	TDateTime startDate = DTPStartDate->Date;
    TDateTime endDate = DTPEndDate->Date;
	double baseRate = EditTermYears->Value;
	AnsiString status = "Розглядається"; // Статус жорстко задано

    if (type.IsEmpty() || EditTermYears->Text.IsEmpty()) {
        ShowMessage("Будь ласка, заповніть всі обов'язкові поля.");
        return;
    }

    if (FUserID == -1) {
        ShowMessage("Помилка: Код користувача не був визначений.");
        ModalResult = mrCancel;
        return;
    }

    if (endDate < startDate) {
        ShowMessage("Дата кінця не може бути раніше дати початку.");
        return;
    }

    try
    {
        if (ADOQueryCreatePolicy->Active) {
            ADOQueryCreatePolicy->Close();
        }

        ADOQueryCreatePolicy->SQL->Clear();
		ADOQueryCreatePolicy->SQL->Add("INSERT INTO [Policy] (КодКористувача, Тип, ДатаПочатку, ДатаКінця, БазоваСтавка, СтатусДоговору) VALUES (:UserID, :Type, :StartDate, :EndDate, :BaseRate, :Status)");

        ADOQueryCreatePolicy->Parameters->ParamByName("UserID")->Value = FUserID;
        ADOQueryCreatePolicy->Parameters->ParamByName("Type")->Value = type;
        ADOQueryCreatePolicy->Parameters->ParamByName("StartDate")->Value = startDate;
        ADOQueryCreatePolicy->Parameters->ParamByName("EndDate")->Value = endDate;
        ADOQueryCreatePolicy->Parameters->ParamByName("BaseRate")->Value = baseRate;
        ADOQueryCreatePolicy->Parameters->ParamByName("Status")->Value = status;

        ADOQueryCreatePolicy->ExecSQL();

        ShowMessage("Договір успішно створено!");

        ModalResult = mrOk;
    }
    catch (Exception &E)
    {
        ShowMessage("Помилка під час створення договору: " + E.Message);
    }
    if (ADOQueryCreatePolicy->Active) {
        ADOQueryCreatePolicy->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::Button2Click(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------


