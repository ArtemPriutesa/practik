//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMyCase.h"
//#include "UnitNewCase.h"
#include "UnitAutor.h"
#include <Data.DB.hpp>
#include "Global.h"
#include "UnitNewCase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyCase *FormMyCase;
//---------------------------------------------------------------------------
__fastcall TFormMyCase::TFormMyCase(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormMyCase::SetDBGridColumnWidths()
{
	FUserID = UserID;
	if (!ADOQueryMyCases->Active) {
		try {
			ADOQueryMyCases->Open();
			ADOQueryMyCases->Close();
		} catch (Exception &E) {
			ShowMessage("Помилка при попередньому відкритті запиту для налаштування стовпців DBGrid: " + E.Message);
		}
	}
}
void __fastcall TFormMyCase::LoadUserCases()
{
	try {
		if (ADOQueryMyCases->Active) {
			ADOQueryMyCases->Close();
		}
		ADOQueryMyCases->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQueryMyCases->Open();

	} catch (Exception &E) {
		ShowMessage("Помилка завантаження страхових випадків: " + E.Message);
	}
}
void __fastcall TFormMyCase::FormCreate(TObject *Sender)
{
    try
	{
		ADOConnectionMyCases->Connected = true;
	}
	catch (Exception &E)
	{
		ShowMessage("Помилка підключення до БД для 'Мої страхові випадки': " + E.Message + "\nПеревірте шлях до бази даних та налаштування ADOConnectionMyCases.");
		ModalResult = mrCancel;
		return;
	}


	DataSourceMyCases->DataSet = ADOQueryMyCases;
	DBGridCases->DataSource = DataSourceMyCases;
	SetDBGridColumnWidths();
}
//---------------------------------------------------------------------------
void __fastcall TFormMyCase::FormClose(TObject *Sender, TCloseAction &Action)
{
    ApplyStyle();
	if (ADOQueryMyCases->Active) {
		ADOQueryMyCases->Close();
	}
	if (ADOConnectionMyCases->Connected) {
		ADOConnectionMyCases->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMyCase::FormShow(TObject *Sender)
{
	if (FUserID != -1) {
		LoadUserCases();
	} else {
		ShowMessage("Користувач не авторизований. Неможливо завантажити страхові випадки.");
		ModalResult = mrCancel;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMyCase::ButtonCloseClick(TObject *Sender)
{
		Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMyCase::ButtonNewCaseClick(TObject *Sender)
{
	TFormNewCase *NewCaseForm = new TFormNewCase(this);
	try
	{
		if (NewCaseForm->ShowModal() == mrOk)
		{
			ShowMessage("Страховий випадок успішно подано!");
			LoadUserCases();
		}
	}
	__finally
	{
		delete NewCaseForm;
	}
}
//---------------------------------------------------------------------------

