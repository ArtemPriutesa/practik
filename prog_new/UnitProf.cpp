//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitProf.h"
#include "UnitAutor.h"
#include <Vcl.Dialogs.hpp>
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProf *FormProf;
//---------------------------------------------------------------------------
__fastcall TFormProf::TFormProf(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::LoadUserProfile()
{
	FUserID = UserID;
		if (FUserID == -1) {
		ShowMessage("�������: ID ����������� �� �����������. ��������� ����������� �������.");
		return;
	}
	try {
		if (ADOQueryProf->Active) {
			ADOQueryProf->Close();
		}
        ADOQueryProf->SQL->Clear();
		ADOQueryProf->Parameters->Clear();
		ADOQueryProf->SQL->Add("SELECT U.ϲ�, U.����, COUNT(P.�����������) AS ʳ�������������� ");
		ADOQueryProf->SQL->Add("FROM [User] AS U ");
		ADOQueryProf->SQL->Add("LEFT JOIN [Policy] AS P ON U.�������������� = P.�������������� ");
		ADOQueryProf->SQL->Add("WHERE U.�������������� = :UserID ");
		ADOQueryProf->SQL->Add("GROUP BY U.ϲ�, U.����");

		ADOQueryProf->Parameters->ParamByName("UserID")->Value = FUserID;
		ADOQueryProf->Open();

		if (!ADOQueryProf->Eof) {
			EditName->Text = ADOQueryProf->Fields->FieldByName("ϲ�")->AsString;
			EditStatus->Text = ADOQueryProf->Fields->FieldByName("����")->AsString;
			EditPolCount->Text = ADOQueryProf->Fields->FieldByName("ʳ��������������")->AsString;
		} else {
			ShowMessage("��� ��� ����������� � ID " + IntToStr(FUserID) + " �� ��������.");
			EditName->Text = "";
			EditStatus->Text = "";
			EditPolCount->Text = "0";
		}
	} catch (Exception &E) {
		ShowMessage("������� ������������ ������� �����������: " + E.Message);
	}
}
void __fastcall TFormProf::FormCreate(TObject *Sender)
{
	ApplyStyle();
    try
	{
		ADOConnectionProf->Connected = true;
        EditName->ReadOnly = true;
        EditStatus->ReadOnly = true;
		EditPolCount->ReadOnly = true;
	}
	catch (Exception &E)
	{
		ShowMessage("������� ���������� �� �� ��� '�������': " + E.Message + "\n�������� ���� �� ���� ����� �� ������������ ADOConnectionProf.");
		ModalResult = mrCancel;
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQueryProf->Active) {
		ADOQueryProf->Close();
	}
	if (ADOConnectionProf->Connected) {
		ADOConnectionProf->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormProf::FormShow(TObject *Sender)
{
	LoadUserProfile();
}
//---------------------------------------------------------------------------
