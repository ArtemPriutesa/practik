#ifndef UnitMyPoliciesH
#define UnitMyPoliciesH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBGrids.hpp>

//---------------------------------------------------------------------------
class TFormMyPolicies : public TForm
{
__published:	// IDE-managed Components
    TADOConnection *ADOConnectionMyPolicies;
    TADOQuery *ADOQueryMyPolicies;
    TDBGrid *DBGridMyPolicies;
	TDataSource *DataSourceMyPolicies;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	int FUserID;
public:		// User declarations
	__fastcall TFormMyPolicies(TComponent* Owner);
    void SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMyPolicies *FormMyPolicies;
//---------------------------------------------------------------------------
#endif
