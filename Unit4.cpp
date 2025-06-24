#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyPolicies *FormMyPolicies;
//---------------------------------------------------------------------------
__fastcall TFormMyPolicies::TFormMyPolicies(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = -1;
}
//---------------------------------------------------------------------------

void TFormMyPolicies::SetUserID(int UserID)
{
    FUserID = UserID;
}
//---------------------------------------------------------------------------

void __fastcall TFormMyPolicies::FormCreate(TObject *Sender)
{
	 try
	{

		if (FUserID != -1) {

			ADOQueryMyPolicies->Parameters->ParamByName("UserID")->Value = FUserID;

			ADOQueryMyPolicies->Open();


		} else {
			ShowMessage("Помилка: Код користувача не був переданий для відображення договорів.");

			ModalResult = mrCancel;
		}
	}
	catch (Exception &E)
	{

		ShowMessage("Помилка при завантаженні моїх договорів: " + E.Message);
		if (ADOQueryMyPolicies->Active) {
			ADOQueryMyPolicies->Close();
		}
		ModalResult = mrAbort;
	}


}
//---------------------------------------------------------------------------

void __fastcall TFormMyPolicies::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ADOQueryMyPolicies->Active) {
		ADOQueryMyPolicies->Close();
	}
	if (ADOConnectionMyPolicies->Connected) {
		ADOConnectionMyPolicies->Close();
	}
}
//---------------------------------------------------------------------------
