//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitReg.h"
#include "UnitAutor.h"
#include "UnitOffice.h"
#include "Global.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReg *FormReg;
//---------------------------------------------------------------------------
__fastcall TFormReg::TFormReg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormReg::IsLoginExists(const AnsiString& login)
{
	bool exists = false;
	if (!ADOConnection1->Connected) {
		ShowMessage("�������: �'������� � ����� ����� ������.");
		return true;
	}
	try
	{
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT COUNT(*) FROM [User] WHERE ���� = :����");
		ADOQuery1->Parameters->ParamByName("����")->Value = login;
		ADOQuery1->Open();
		if (!ADOQuery1->Eof) {
			if (ADOQuery1->Fields->Fields[0]->AsInteger > 0) {
				exists = true;
			}
		}
	}
	catch (Exception &E)
    {
		ShowMessage("������� �������� �����: " + E.Message);
		exists = true;
	}
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	return exists;
}

void __fastcall TFormReg::Button1Click(TObject *Sender)
{
    AnsiString pip = EditPIP->Text.Trim();
	AnsiString login = EditLog->Text.Trim();
	AnsiString password = EditPas->Text;
	AnsiString confirmPassword = EditPas2->Text;
	AnsiString role = "�볺��";
    if (pip.IsEmpty() || login.IsEmpty() || password.IsEmpty() || confirmPassword.IsEmpty()) {
		ShowMessage("���� �����, �������� �� ����'����� ���� .");
        return;
	}
	if (password != confirmPassword) {
		ShowMessage("����� �� ����������.");
		EditPas->Clear();
		EditPas2->Clear();
		EditPas->SetFocus();
		return;
	}
	if (password.Length() < 4) {
		ShowMessage("������ �� ���� �� ����� 4 �������.");
		return;
	}
    if (IsLoginExists(login)) {
		ShowMessage("���������� � ����� ������ ��� ����.");
		EditLog->Clear();
		EditLog->SetFocus();
		return;
	}
    try
    {
		if (ADOQuery1->Active) {
			ADOQuery1->Close();
		}

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO [User] (ϲ�, ����, ������, ����) VALUES (:PIP, :Login, :Password, :Role)");

		ADOQuery1->Parameters->ParamByName("PIP")->Value = pip;
		ADOQuery1->Parameters->ParamByName("Login")->Value = login;
		ADOQuery1->Parameters->ParamByName("Password")->Value = password;
		ADOQuery1->Parameters->ParamByName("Role")->Value = role;

		ADOQuery1->ExecSQL();

        ShowMessage("��������� ������! ������� �������, " + login + "!");

        ModalResult = mrOk;
    }
    catch (Exception &E)
    {
        ShowMessage("������� �� ��� ���������: " + E.Message);
    }
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormReg::Button2Click(TObject *Sender)
{
	FormAutor->Show();
	Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormReg::FormCreate(TObject *Sender)
{
	ApplyStyle();
    try
	{
		ADOConnection1->Connected = true;
    }
	catch (Exception &E)
    {
        ShowMessage("������� ���������� �� �� ��� ���������: " + E.Message);
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormReg::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	if (ADOConnection1->Connected) {
        ADOConnection1->Close();
	}
}
//---------------------------------------------------------------------------
