//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAutor.h"
#include "UnitReg.h"
#include "UnitOffice.h"
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAutor *FormAutor;
//---------------------------------------------------------------------------
__fastcall TFormAutor::TFormAutor(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAutor::Button1Click(TObject *Sender)
{
    AnsiString username = Edit1->Text.Trim();
	AnsiString password = Edit2->Text;

	if (username.IsEmpty() || password.IsEmpty()) {
        ShowMessage("���� �����, ������ ���� �� ������.");
		return;
    }

    try
    {

        if (ADOQuery1->Active) {
            ADOQuery1->Close();
		}


		ADOQuery1->SQL->Clear();

		ADOQuery1->SQL->Add("SELECT ��������������,���� FROM [User] WHERE ���� = :���� AND ������ = :������");
		ADOQuery1->Parameters->ParamByName("����")->Value = username;
		ADOQuery1->Parameters->ParamByName("������")->Value = password;
		ADOQuery1->Open();


		if (!ADOQuery1->Eof) {

			AnsiString loggedInUsername = ADOQuery1->Fields->FieldByName("����")->AsString;
			ShowMessage("������� �������, " + loggedInUsername + "!");
			UserID = ADOQuery1->Fields->FieldByName("��������������")->AsInteger;
			Username = loggedInUsername;
			FormOffice->Show();
			Hide();
		} else {
			ShowMessage("������� ���� ��� ������.");
		}
	}
	catch (Exception &E)
	{
		ShowMessage("������� �������: " + E.Message);
    }

	if (ADOQuery1->Active) {
		ADOQuery1->Close();
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormAutor::FormCreate(TObject *Sender)
{
	LoadSettings();
	ApplyStyle();
	try
	{
		ADOConnection1->Connected = true;
	}
		catch (Exception &E)
	{
		ShowMessage("������� ���������� �� ��: " + E.Message + "\n�������� ���� �� users_db.accdb �� ������������ ADOConnection.");
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAutor::FormClose(TObject *Sender, TCloseAction &Action)

{
    if (ADOQuery1->Active) {
		ADOQuery1->Close();
	}
	if (ADOConnection1->Connected) {
		ADOConnection1->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAutor::Button2Click(TObject *Sender)
{
	FormReg->Show();
	Hide();
}
//---------------------------------------------------------------------------

