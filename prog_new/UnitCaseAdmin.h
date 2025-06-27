//---------------------------------------------------------------------------

#ifndef UnitCaseAdminH
#define UnitCaseAdminH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormCasesAdmin : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TADOQuery *ADOQueryCases;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TComboBox *ComboBoxStatus;
	TButton *ButtonApply;
	TLabel *Label1;
	TADOQuery *ADOQueryPay;
	TButton *Button1;
	TLabel *Label2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall ButtonApplyClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormCasesAdmin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCasesAdmin *FormCasesAdmin;
//---------------------------------------------------------------------------
#endif
