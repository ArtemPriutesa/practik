//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UnitReg.h"
#include "UnitAutor.h"
#include "UnitOffice.h"
#include "UnitNewPol.h"
#include <System.DateUtils.hpp>
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormNewPol *FormNewPol;
//---------------------------------------------------------------------------
__fastcall TFormNewPol::TFormNewPol(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1; // Ініціалізуємо UserID за замовчуванням
	FEndDate = Date();
}
//---------------------------------------------------------------------------
/*void __fastcall TFormNewPol::SetUserID(int UserID)
{
	//FUserID = FormAutor->AuthenticatedUserID;
} */

void __fastcall TFormNewPol::UpdateEndDateAndRate()
{
	FUserID = UserID;
    try {
        int years = SpinEditTerm->Value;
        if (years < 0) {
            years = 0;
            SpinEditTerm->Value = 0;
        }

		FEndDate = IncYear(DateTimePickerStart->Date, years);

	} catch (Exception &E) {
		FEndDate = DateTimePickerStart->Date;
		UpdateBaseRateDisplay();
	}
}
void __fastcall TFormNewPol::Button1Click(TObject *Sender)
{
	AnsiString type = ComboBoxType->Text.Trim();
	TDateTime startDate = DateTimePickerStart->Date;
	TDateTime endDate = FEndDate; // Використовуємо розраховану дату з приватного поля
	AnsiString status = "Розглядається"; // Статус жорстко задано

	// Розраховуємо базову ставку безпосередньо перед INSERT
	double baseRate = CalculateBaseRate();

	if (type.IsEmpty() || SpinEditTerm->Value <= 0) {
		ShowMessage("Будь ласка, заповніть всі обов'язкові поля (тип договору та термін має бути більше 0).");
		return;
	}

	if (FUserID == -1) {
		ShowMessage("Помилка: Код користувача не був визначений. Будь ласка, авторизуйтесь.");
		ModalResult = mrCancel;
		return;
	}

	if (endDate < startDate) {
		ShowMessage("Дата кінця не може бути раніше дати початку.");
		return;
	}

	if (baseRate <= 0 && SpinEditTerm->Value > 0) {
		ShowMessage("Не вдалося розрахувати базову ставку. Перевірте тип договору та термін.");
		return;
	}

	try
	{
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}

		ADOQuery1->SQL->Clear();
		// Важливо: переконайтесь, що назва таблиці 'Policy' взята в квадратні дужки,
		// якщо вона є зарезервованим словом у MS Access.
		ADOQuery1->SQL->Add("INSERT INTO [Policy] (КодКористувача, Тип, ДатаПочатку, ДатаКінця, БазоваСтавка, СтатусДоговору) VALUES (:UserID, :Type, :StartDate, :EndDate, :BaseRate, :Status)");

		ADOQuery1->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQuery1->Parameters->ParamByName("Type")->Value = type;
		ADOQuery1->Parameters->ParamByName("StartDate")->Value = startDate;
		ADOQuery1->Parameters->ParamByName("EndDate")->Value = endDate;
		ADOQuery1->Parameters->ParamByName("BaseRate")->Value = baseRate;
		ADOQuery1->Parameters->ParamByName("Status")->Value = status;

		ADOQuery1->ExecSQL();

		ShowMessage("Договір успішно створено!");
		ModalResult = mrOk; // Встановлюємо ModalResult, щоб батьківська форма знала про успіх
	}
	catch (Exception &E)
	{
		ShowMessage("Помилка під час створення договору: " + E.Message);
	}
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormNewPol::Button2Click(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::DateTimePickerStartChange(TObject *Sender)
{
    UpdateEndDateAndRate();
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::SpinEditTermChange(TObject *Sender)
{
	UpdateEndDateAndRate();
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::ComboBoxTypeChange(TObject *Sender)
{
    UpdateBaseRateDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::FormCreate(TObject *Sender)
{
    ComboBoxType->ItemIndex = 0; // За замовчуванням перший елемент
	DateTimePickerStart->Date = Date(); // Поточна дата
	SpinEditTerm->Value = 1; // Термін за замовчуванням 1 рік

	// Оновлюємо дату закінчення та базову ставку на основі початкових значень
	UpdateEndDateAndRate();
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	if (ADOConnection1->Connected) {
		ADOConnection1->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPol::UpdateBaseRateDisplay()
{
    double rate = CalculateBaseRate();
    Edit1->Text = FormatFloat("0.00", rate) + " грн"; // Форматуємо для відображення
}

double __fastcall TFormNewPol::CalculateBaseRate()
{
	AnsiString selectedType = ComboBoxType->Text;
	int years = SpinEditTerm->Value; // TSpinEdit має властивість Value типу int

	double calculatedRate = 0;

	if (selectedType == "Автострахування") {
		calculatedRate = 1000.0 * years;
	} else if (selectedType == "Страхування життя") {
		calculatedRate = 2000.0 * years;
	} else {
		// Якщо тип не розпізнано, базова ставка 0
		calculatedRate = 0;
	}
	return calculatedRate;
}