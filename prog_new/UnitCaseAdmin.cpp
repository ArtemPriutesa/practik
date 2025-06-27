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
	ComboBoxStatus->Items->Add("�����");
	ComboBoxStatus->Items->Add("��������");
	ComboBoxStatus->Items->Add("³�������");
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::DBGrid1CellClick(TColumn *Column)
{
	if (!ADOQueryCases->Active || ADOQueryCases->IsEmpty()) {
		ShowMessage("���� ��������� ������.");
		return;
	}

	try {
		AnsiString currentStatus = ADOQueryCases->FieldByName("�������������")->AsString;
		ComboBoxStatus->Text = currentStatus;
	}
	catch (Exception &E) {
		ShowMessage("������� ��� ����������� �������: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::ButtonApplyClick(TObject *Sender)
{
if (!ADOQueryCases->Active || ADOQueryCases->IsEmpty())
	{
		ShowMessage("���� �������� ������.");
		return;
	}

	if (ComboBoxStatus->Text.Trim().IsEmpty())
	{
		ShowMessage("������ ����� ������.");
		return;
	}

	try {
		// ���������� ������ �������
		ADOQueryCases->Edit();
		AnsiString newStatus = ComboBoxStatus->Text;
		ADOQueryCases->FieldByName("�������������")->AsString = newStatus;
		ADOQueryCases->Post();
		int contractID;
		int caseID;
		if (newStatus == "��������") {




			float payoutAmount = 4000;


			// ������� � Payout
			ADOQueryPay->Close();
			ADOQueryPay->SQL->Clear();
			ADOQueryPay->SQL->Add(
				"INSERT INTO Payout (����������,  �����������, �����������) "
				"VALUES (:CID, :Date, :Sum)"
			);
			ADOQueryPay->Parameters->ParamByName("CID")->Value = caseID;
			ADOQueryPay->Parameters->ParamByName("Date")->Value = Now();
			ADOQueryPay->Parameters->ParamByName("Sum")->Value = payoutAmount;
			ADOQueryPay->ExecSQL();

			ShowMessage("������ ��������, ������� ���������.");
		}
		else {
			ShowMessage("������ ��������.");
		}
	}
	catch (Exception &E) {
		ShowMessage("������� ���������: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormCasesAdmin::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
