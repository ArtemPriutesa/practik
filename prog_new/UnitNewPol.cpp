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
	FUserID = -1;
	FEndDate = Date();
}
//---------------------------------------------------------------------------

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
	TDateTime endDate = FEndDate;
	AnsiString status = "Розглядається";
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
	ADOQuery1->SQL->Add("INSERT INTO [Policy] (КодКористувача, Тип, ДатаПочатку, ДатаКінця, БазоваСтавка, СтатусДоговору) "
						"VALUES (:UserID, :Type, :StartDate, :EndDate, :BaseRate, :Status)");
	ADOQuery1->Parameters->ParamByName("UserID")->Value = FUserID;
	ADOQuery1->Parameters->ParamByName("Type")->Value = type;
	ADOQuery1->Parameters->ParamByName("StartDate")->Value = startDate;
	ADOQuery1->Parameters->ParamByName("EndDate")->Value = endDate;
	ADOQuery1->Parameters->ParamByName("BaseRate")->Value = baseRate;
	ADOQuery1->Parameters->ParamByName("Status")->Value = status;
	ADOQuery1->ExecSQL();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT MAX(КодДоговору) AS LastID FROM [Policy]");
	ADOQuery1->Open();
	int newPolicyID = ADOQuery1->FieldByName("LastID")->AsInteger;
	ADOQueryPay->Close();
	ADOQueryPay->SQL->Clear();
	ADOQueryPay->SQL->Add("INSERT INTO [Payment] (КодДоговору, ДатаПлатежу, СумаПлатежу) "
						"VALUES (:PolicyID, :PayDate, :Amount)");
	ADOQueryPay->Parameters->ParamByName("PolicyID")->Value = newPolicyID;
	ADOQueryPay->Parameters->ParamByName("PayDate")->Value = Date();
	ADOQueryPay->Parameters->ParamByName("Amount")->Value = baseRate;
	ADOQueryPay->ExecSQL();
	ShowMessage("Договір і перший платіж успішно створено!");
	ModalResult = mrOk;
	}
	catch (Exception &E)
	{
		ShowMessage("Помилка під час створення: " + E.Message);
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
	ApplyStyle();
	ComboBoxType->ItemIndex = 0;
	DateTimePickerStart->Date = Date();
	SpinEditTerm->Value = 1;
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
	Edit1->Text = FormatFloat("0.00", rate) + " грн";
}
double __fastcall TFormNewPol::CalculateBaseRate()
{
	AnsiString selectedType = ComboBoxType->Text;
	int years = SpinEditTerm->Value;
	double calculatedRate = 0;
	if (selectedType == "Автострахування") {
		calculatedRate = 1000.0 ;
	} else if (selectedType == "Страхування життя") {
		calculatedRate = 2000.0 ;
	} else {
		calculatedRate = 0;
	}
	return calculatedRate;
}