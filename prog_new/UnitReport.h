//---------------------------------------------------------------------------

#ifndef UnitReportH
#define UnitReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFormReport : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditSearchPIP;
	TADOConnection *ADOConnectionReport;
	TADOQuery *ADOQuerySearch;
	TButton *ButtonReportClick;
	TButton *Button1;
	void __fastcall ButtonReportClickClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReport *FormReport;
//---------------------------------------------------------------------------
#endif
