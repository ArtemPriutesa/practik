//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include <System.DateUtils.hpp>
#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCreatePolicy *FormCreatePolicy;
//---------------------------------------------------------------------------
__fastcall TFormCreatePolicy::TFormCreatePolicy(TComponent* Owner)
	: TForm(Owner)
{
    FUserID = -1;
    FEndDate = Date();
}

// Метод для встановлення UserID
void TFormCreatePolicy::SetUserID(int UserID)
{
    FUserID = UserID;
}

//---------------------------------------------------------------------------
double __fastcall TFormCreatePolicy::CalculateBaseRate()
{
	AnsiString selectedType = ComboBoxType->Text;
 	int years = 0;
	try {
 		years = StrToIntDef(EditTermYears->Text, 0);
 		if (years < 0) years = 0;
	} catch (Exception &E) {
 		years = 0;
 	}

 	double calculatedRate = 0;

	if (selectedType == "Автострахування") {
 		calculatedRate = 1000.0 * years;
 	} else if (selectedType == "Страхування життя") {
 		calculatedRate = 2000.0 * years;
 	} else {

		calculatedRate = 0;
	}
 	return calculatedRate;
}

//---------------------------------------------------------------------------
void __fastcall TFormCreatePolicy::UpdateBaseRate()
{
	double rate = CalculateBaseRate();
	EditBaseRate->Text = FormatFloat("0.00", rate) + " грн";
}
void __fastcall TFormCreatePolicy::UpdateEndDateDisplay()
{
 	try {
		int years = StrToIntDef(EditTermYears->Text, 0);
 		if (years < 0) {
 			years = 0;
 			EditTermYears->Text = "0";
 
		FEndDate = IncYear(DTPStartDate->Date, years);

		EditEndDate->Text = FormatDateTime("dd.mm.yyyy", FEndDate);
	}
	} catch (Exception &E) {
		FEndDate = DTPStartDate->Date;
		EditEndDate->Text = FormatDateTime("dd.mm.yyyy", FEndDate);
	}
	UpdateBaseRate();
}
//---------------------------------------------------------------------------
void __fastcall TFormCreatePolicy::FormCreate(TObject *Sender)
{
	try
 	{
 		ADOConnectionCreatePolicy->Connected = true;

 
		ComboBoxType->ItemIndex = 0;
		DTPStartDate->Date = Date();
		EditTermYears->Text = "1";


		UpdateEndDateDisplay();
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

//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::DTPStartDateChange(TObject *Sender)
{
    UpdateEndDateDisplay();
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::EditTermYearsChange(TObject *Sender)
{
    UpdateEndDateDisplay();
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::ComboBoxTypeChange(TObject *Sender)
{
	UpdateBaseRate();
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::ButtonCreateClick(TObject *Sender)
{
	AnsiString type = ComboBoxType->Text.Trim();
	TDateTime startDate = DTPStartDate->Date;
 
	TDateTime endDate = FEndDate;
	AnsiString status = "Розглядається";

   
    double baseRate = CalculateBaseRate();


 	if (type.IsEmpty() || EditTermYears->Text.IsEmpty()) {
 		ShowMessage("Будь ласка, заповніть всі обов'язкові поля (тип договору та термін).");
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

    if (baseRate <= 0 && StrToIntDef(EditTermYears->Text, 0) > 0) {
        ShowMessage("Не вдалося розрахувати базову ставку. Перевірте тип договору та термін.");
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
 	if (ADOQueryCreatePolicy->Active)
	{
 		ADOQueryCreatePolicy->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCreatePolicy::ButtonCancelClick(TObject *Sender)
{
     ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
