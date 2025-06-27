//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitCaseAdmin.h"
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCasesAdmin *FormCasesAdmin;
//---------------------------------------------------------------------------
__fastcall TFormCasesAdmin::TFormCasesAdmin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::FormCreate(TObject *Sender)
{
	ADOConnection1->Connected = true;
	ADOQueryCases->Close();
	ADOQueryCases->SQL->Clear();
	ADOQueryCases->SQL->Add("SELECT * FROM [Case]");
	ADOQueryCases->Open();

	ComboBoxStatus->Items->Clear();
	ComboBoxStatus->Items->Add("Очікує");
	ComboBoxStatus->Items->Add("Схвалено");
	ComboBoxStatus->Items->Add("Відхилено");
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::DBGrid1CellClick(TColumn *Column)
{
	if (!ADOQueryCases->Active || ADOQueryCases->IsEmpty()) {
		ShowMessage("Немає вибраного запису.");
		return;
	}

	try {
		AnsiString currentStatus = ADOQueryCases->FieldByName("СтатусВипадку")->AsString;
		ComboBoxStatus->Text = currentStatus;
	}
	catch (Exception &E) {
		ShowMessage("Помилка при завантаженні статусу: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::ButtonApplyClick(TObject *Sender)
{
if (!ADOQueryCases->Active || ADOQueryCases->IsEmpty())
	{
		ShowMessage("Немає обраного запису.");
		return;
	}

	if (ComboBoxStatus->Text.Trim().IsEmpty())
	{
		ShowMessage("Оберіть новий статус.");
		return;
	}

	try {
		// Збереження нового статусу
		ADOQueryCases->Edit();
		AnsiString newStatus = ComboBoxStatus->Text;
		ADOQueryCases->FieldByName("СтатусВипадку")->AsString = newStatus;
		ADOQueryCases->Post();
		int contractID;
		int caseID;
		if (newStatus == "Схвалено") {




			float payoutAmount = 4000;


			// Вставка в Payout
			ADOQueryPay->Close();
			ADOQueryPay->SQL->Clear();
			ADOQueryPay->SQL->Add(
				"INSERT INTO Payout (КодВипадку,  ДатаВиплати, СумаВиплати) "
				"VALUES (:CID, :Date, :Sum)"
			);
			ADOQueryPay->Parameters->ParamByName("CID")->Value = caseID;
			ADOQueryPay->Parameters->ParamByName("Date")->Value = Now();
			ADOQueryPay->Parameters->ParamByName("Sum")->Value = payoutAmount;
			ADOQueryPay->ExecSQL();

			ShowMessage("Статус оновлено, виплату проведено.");
		}
		else {
			ShowMessage("Статус оновлено.");
		}
	}
	catch (Exception &E) {
		ShowMessage("Помилка оновлення: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
