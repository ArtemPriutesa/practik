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
	FUserID = -1; // ���������� UserID �� �������������
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
	TDateTime endDate = FEndDate; // ������������� ����������� ���� � ���������� ����
	AnsiString status = "������������"; // ������ ������� ������

	// ����������� ������ ������ ������������� ����� INSERT
	double baseRate = CalculateBaseRate();

	if (type.IsEmpty() || SpinEditTerm->Value <= 0) {
		ShowMessage("���� �����, �������� �� ����'����� ���� (��� �������� �� ����� �� ���� ����� 0).");
		return;
	}

	if (FUserID == -1) {
		ShowMessage("�������: ��� ����������� �� ��� ����������. ���� �����, �������������.");
		ModalResult = mrCancel;
		return;
	}

	if (endDate < startDate) {
		ShowMessage("���� ���� �� ���� ���� ����� ���� �������.");
		return;
	}

	if (baseRate <= 0 && SpinEditTerm->Value > 0) {
		ShowMessage("�� ������� ����������� ������ ������. �������� ��� �������� �� �����.");
		return;
	}

	try
	{
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}

		ADOQuery1->SQL->Clear();
		// �������: �������������, �� ����� ������� 'Policy' ����� � �������� �����,
		// ���� ���� � �������������� ������ � MS Access.
		ADOQuery1->SQL->Add("INSERT INTO [Policy] (��������������, ���, �����������, ����ʳ���, ������������, ��������������) VALUES (:UserID, :Type, :StartDate, :EndDate, :BaseRate, :Status)");

		ADOQuery1->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQuery1->Parameters->ParamByName("Type")->Value = type;
		ADOQuery1->Parameters->ParamByName("StartDate")->Value = startDate;
		ADOQuery1->Parameters->ParamByName("EndDate")->Value = endDate;
		ADOQuery1->Parameters->ParamByName("BaseRate")->Value = baseRate;
		ADOQuery1->Parameters->ParamByName("Status")->Value = status;

		ADOQuery1->ExecSQL();

		ShowMessage("������ ������ ��������!");
		ModalResult = mrOk; // ������������ ModalResult, ��� ���������� ����� ����� ��� ����
	}
	catch (Exception &E)
	{
		ShowMessage("������� �� ��� ��������� ��������: " + E.Message);
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
    ComboBoxType->ItemIndex = 0; // �� ������������� ������ �������
	DateTimePickerStart->Date = Date(); // ������� ����
	SpinEditTerm->Value = 1; // ����� �� ������������� 1 ��

	// ��������� ���� ��������� �� ������ ������ �� ����� ���������� �������
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
    Edit1->Text = FormatFloat("0.00", rate) + " ���"; // ��������� ��� �����������
}

double __fastcall TFormNewPol::CalculateBaseRate()
{
	AnsiString selectedType = ComboBoxType->Text;
	int years = SpinEditTerm->Value; // TSpinEdit �� ���������� Value ���� int

	double calculatedRate = 0;

	if (selectedType == "���������������") {
		calculatedRate = 1000.0 * years;
	} else if (selectedType == "����������� �����") {
		calculatedRate = 2000.0 * years;
	} else {
		// ���� ��� �� ���������, ������ ������ 0
		calculatedRate = 0;
	}
	return calculatedRate;
}