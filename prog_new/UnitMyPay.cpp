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
	ApplyStyle();
	ADOQueryPay->Close();
	ADOQueryPay->SQL->Clear();
	ADOQueryPay->Parameters->Clear();

	ADOQueryPay->SQL->Add(
		"SELECT W.����������, W.����������, W.�����������, W.����������� "
		"FROM ([Payout] AS W "
		"INNER JOIN [Case] AS C ON W.���������� = C.����������) "
		"INNER JOIN [Policy] AS P ON C.����������� = P.����������� "
		"WHERE P.�������������� = :UserID "
		"ORDER BY W.����������� DESC"
		);


	ADOQueryPay->Parameters->ParamByName("UserID")->Value = UserID;

	try {
		ADOQueryPay->Open();
	}
	catch (Exception &E) {
		ShowMessage("������� ��� ����������� ����� ������: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMyPay::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

