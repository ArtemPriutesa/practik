//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMyPay.h"
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyPay *FormMyPay;
//---------------------------------------------------------------------------
__fastcall TFormMyPay::TFormMyPay(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMyPay::FormCreate(TObject *Sender)
{
	ADOQueryPay->Close();
	ADOQueryPay->SQL->Clear();
	ADOQueryPay->Parameters->Clear();

	ADOQueryPay->SQL->Add(
		"SELECT W.КодВиплати, W.КодВипадку, W.ДатаВиплати, W.СумаВиплати "
		"FROM [Payout] AS W "
		"JOIN [Policy] AS P ON W.КодДоговору = P.КодДоговору "
		"WHERE P.КодКористувача = :UserID "
		"ORDER BY W.ДатаВиплати DESC"
	);

	ADOQueryPay->Parameters->ParamByName("UserID")->Value = UserID;

	try {
		ADOQueryPay->Open();
	}
	catch (Exception &E) {
		ShowMessage("Помилка при завантаженні історії виплат: " + E.Message);
	}
}
//---------------------------------------------------------------------------
