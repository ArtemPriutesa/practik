//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAutor.h"
#include "UnitReg.h"
#include "UnitOffice.h"
#include "UnitOfficeAdmin.h"
#include "Global.h"
#include <Vcl.Graphics.hpp> // Для TBitmap
#include <Vcl.Imaging.jpeg.hpp> // Може знадобитися, якщо працюєте з JPG
#include <Vcl.Imaging.pngimage.hpp> // Може знадобитися, якщо працюєте з PNG
#include <System.Math.hpp>  // Для випадкових чисел
#include <System.SysUtils.hpp> // Для RandomString
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
        ShowMessage("Будь ласка, введіть логін та пароль.");
		return;
	}
    try
	{
		if (ADOQuery1->Active) {
            ADOQuery1->Close();
		}
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT * FROM [User] WHERE Логін = :Логін AND Пароль = :Пароль");
		ADOQuery1->Parameters->ParamByName("Логін")->Value = username;
		ADOQuery1->Parameters->ParamByName("Пароль")->Value = password;
		ADOQuery1->Open();
		if (!ADOQuery1->Eof) {
			UserID = ADOQuery1->FieldByName("КодКористувача")->AsInteger;
			Username = ADOQuery1->FieldByName("ПІП")->AsString;
			AnsiString role = ADOQuery1->FieldByName("Роль")->AsString.LowerCase();
			ShowMessage("Ласкаво просимо, " + Username + "!");
			if (role == "адміністратор") {
				FormOfficeAdmin = new TFormOfficeAdmin(this);
				FormOfficeAdmin->Show();
			} else {
				FormOffice = new TFormOffice(this);
				FormOffice->Show();
			}
			Hide();
		} else {
			ShowMessage("Невірний логін або пароль.");
		}
	}
	catch (Exception &E)
	{
		ShowMessage("Сталася помилка: " + E.Message);
	}
	if (ADOQuery1->Active) {
		ADOQuery1->Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormAutor::FormCreate(TObject *Sender)
{
	ApplyStyle();
	try
	{
		ADOConnection1->Connected = true;
	}
	catch (Exception &E)
	{
		ShowMessage("Помилка підключення до БД: " + E.Message + "\nПеревірте шлях до users_db.accdb та налаштування ADOConnection.");
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

