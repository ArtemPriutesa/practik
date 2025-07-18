//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSave.h"
#include "UnitAutor.h"
#include "Global.h"
#include <mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProgres *FormProgres;
//---------------------------------------------------------------------------
__fastcall TFormProgres::TFormProgres(TComponent* Owner)
	: TForm(Owner)
{
    ProgressBar1->Min = 0;
	ProgressBar1->Max = 100;
	ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormProgres::FormCreate(TObject *Sender)
{
    LoadSettings();
	ApplyStyle();
}
//---------------------------------------------------------------------------
void __fastcall TFormProgres::FormShow(TObject *Sender)
{
    Timer1->Enabled = true;
	ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormProgres::Timer1Timer(TObject *Sender)
{
	ProgressBar1->Position = ProgressBar1->Position + 2;
	if (ProgressBar1->Position >= ProgressBar1->Max)
	{

		Timer1->Enabled = false;
		Hide();
		TFormAutor *AutorForm = new TFormAutor(this);
		try
		{
			AutorForm->ShowModal();

		}
		__finally
		{
			delete AutorForm;
		}
		Close();
	}
}
//---------------------------------------------------------------------------
