//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSett.h"
#include "Global.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSett *FormSett;
//---------------------------------------------------------------------------
__fastcall TFormSett::TFormSett(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSett::ButtonApplyClick(TObject *Sender)
{
	if (RadioLight->Checked)
		CurrentTheme = "Light";
	else if (RadioDark->Checked)
		CurrentTheme = "Dark";
	else if (RadioNight->Checked)
		CurrentTheme = "Night";

	SaveSettings();
	ApplyStyle(); // одразу застосувати

	// Оновлюємо всі форми, якщо відкриті
	for (int i = 0; i < Screen->FormCount; i++) {
		Screen->Forms[i]->Refresh();
	}
	ShellExecute(NULL, L"open", Application->ExeName.w_str(), NULL, NULL, SW_SHOWNORMAL);
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TFormSett::FormCreate(TObject *Sender)
{
	ApplyStyle();
}
//---------------------------------------------------------------------------
void __fastcall TFormSett::ButtonCancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

