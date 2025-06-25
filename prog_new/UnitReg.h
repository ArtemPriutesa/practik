//---------------------------------------------------------------------------

#ifndef UnitRegH
#define UnitRegH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFormReg : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditPIP;
	TEdit *EditLog;
	TEdit *EditPas;
	TEdit *EditPas2;
	TButton *Button1;
	TButton *Button2;
	TADOQuery *ADOQuery1;
	TADOConnection *ADOConnection1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	bool IsLoginExists(const AnsiString& login);
public:		// User declarations
	__fastcall TFormReg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReg *FormReg;
//---------------------------------------------------------------------------
#endif
