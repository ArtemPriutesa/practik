//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMyPol.h"
#include "UnitReg.h"
#include "UnitAutor.h"
#include "UnitOffice.h"
#include "UnitNewPol.h"
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyPol *FormMyPol;
//---------------------------------------------------------------------------
__fastcall TFormMyPol::TFormMyPol(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormMyPol::FormCreate(TObject *Sender)
{
		FUserID = UserID;
		for (int i = 0; i < DBGrid1->Columns->Count; i++) {
			DBGrid1->Columns->Items[i]->Width = 112;
		}
		try {
		if (FUserID == -1) {
			//ShowMessage("Помилка: Код користувача не передано.");
			ModalResult = mrCancel;
			return;
		}

		if (ADOQuery1->Active) ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->Parameters->Clear();

		ADOQuery1->SQL->Add("SELECT КодДоговору, Тип, ДатаПочатку, ДатаКінця, БазоваСтавка, СтатусДоговору ");
		ADOQuery1->SQL->Add("FROM Policy ");
		ADOQuery1->SQL->Add("WHERE КодКористувача = :UserID");

		ADOQuery1->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQuery1->Open();
	}
	catch (Exception &E) {
		ShowMessage("Помилка при завантаженні моїх договорів: " + E.Message);
		if (ADOQuery1->Active) ADOQuery1->Close();
		ModalResult = mrAbort;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMyPol::Button1Click(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

