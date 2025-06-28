//---------------------------------------------------------------------------

#ifndef UnitAutorH
#define UnitAutorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAutor : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label4;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	AnsiString FGeneratedCaptchaText;
	void __fastcall GenerateCaptcha();
public:		// User declarations
	int AuthenticatedUserID;
	AnsiString AuthenticatedUsername;
	__fastcall TFormAutor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAutor *FormAutor;
//---------------------------------------------------------------------------
#endif
