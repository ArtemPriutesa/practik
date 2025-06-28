//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitReport.h"
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReport *FormReport;
//---------------------------------------------------------------------------
__fastcall TFormReport::TFormReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormReport::ButtonReportClickClick(TObject *Sender)
{
    AnsiString pip = EditSearchPIP->Text.Trim();
	if (pip.IsEmpty()) {
		ShowMessage("ПІП не введено.");
		return;
	}
	ADOQuerySearch->Close();
	ADOQuerySearch->SQL->Clear();
	ADOQuerySearch->SQL->Add("SELECT * FROM [User] WHERE ПІП = :FIO");
	ADOQuerySearch->Parameters->ParamByName("FIO")->Value = pip;
	ADOQuerySearch->Open();
	if (ADOQuerySearch->IsEmpty()) {
		ShowMessage("Користувача з таким ПІП не знайдено.");
		return;
	}
	AnsiString report = "Інформація про користувача\r\n";
	report += "-----------------------------\r\n";
	for (int i = 0; i < ADOQuerySearch->FieldCount; i++) {
		report += ADOQuerySearch->Fields->Fields[i]->FieldName + ": ";
		report += ADOQuerySearch->Fields->Fields[i]->AsString + "\r\n";
	}
	std::unique_ptr<TSaveDialog> dlg(new TSaveDialog(this));
	dlg->Filter = "Текстові файли (*.txt)|*.txt";
	dlg->FileName = "Звіт_" + pip + ".txt";
	if (dlg->Execute()) {
		try {
			TFile::WriteAllText(dlg->FileName, report, TEncoding::UTF8);
			ShowMessage("Звіт збережено успішно:\n" + dlg->FileName);
		} catch (const Exception &e) {
			ShowMessage("Помилка при збереженні: " + e.Message);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormReport::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

