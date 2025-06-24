//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma resource "*.dfm"
TForm�ffice *Form�ffice;
//---------------------------------------------------------------------------
__fastcall TForm�ffice::TForm�ffice(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm�ffice::Button1Click(TObject *Sender)
{
if (FormAuthorization->AuthenticatedUserID != -1)
	{
		// ��������� ��������� ����� "�� ��������"
		TFormMyPolicies *MyPoliciesForm = new TFormMyPolicies(this);
		try
        {
            // �������� �������������� �� ����� "�� ��������"
			MyPoliciesForm->SetUserID(FormAuthorization->AuthenticatedUserID);

			// �������� ����� "�� ��������" ��������
            // �� ������, �� ���������� �� ����� ��������� � "��������� ��������",
            // ���� �� ����� ����� "�� ��������".
            MyPoliciesForm->ShowModal();

            // ϳ��� �������� MyPoliciesForm (�� �������):
            // if (MyPoliciesForm->ModalResult == mrOk) { ... }
        }
        __finally
        {
            delete MyPoliciesForm; // ������ ��������� ���'���, ���� ���������� � 'new'
        }
    }
    else
    {
        ShowMessage("��� ��������� �������� ��������� ��������������.");
        // �������, �������� ����� ����������� �����:
        // Form2->ShowModal();
	}
}
//---------------------------------------------------------------------------


