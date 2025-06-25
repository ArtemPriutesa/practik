//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMyPol.h"
#include "UnitReg.h"
#include "UnitAutor.h"
#include "UnitOffice.h"
#include "UnitNewPol.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMyPol *FormMyPol;
//---------------------------------------------------------------------------
__fastcall TFormMyPol::TFormMyPol(TComponent* Owner)
	: TForm(Owner)
{
	FUserID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormMyPol::SetUserID(int UserID)
{
	FUserID = FormAutor->AuthenticatedUserID;
}

void __fastcall TFormMyPol::FormCreate(TObject *Sender)
{
		for(int i=0;i<6;i++){
		DBGrid1->Columns->Items[i]->Width=90;
		}
		try
		{

			if (FUserID == 0) {

				ADOQuery1->Parameters->ParamByName("UserID")->Value = FUserID;

				ADOQuery1->Open();


		} else {
				ShowMessage("Помилка: Код користувача не був переданий для відображення договорів.");

				ModalResult = mrCancel;
			}
		}
		catch (Exception &E)
		{

			ShowMessage("Помилка при завантаженні моїх договорів: " + E.Message);
				if (ADOQuery1->Active) {
					ADOQuery1->Close();
				}
				ModalResult = mrAbort;
		}
}
//---------------------------------------------------------------------------
