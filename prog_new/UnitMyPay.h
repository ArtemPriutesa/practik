//---------------------------------------------------------------------------

#ifndef UnitMyPayH
#define UnitMyPayH
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
class TFormMyPay : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridPay;
	TADOConnection *ADOConnectionPay;
	TADOQuery *ADOQueryPay;
	TDataSource *DataSourcePay;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMyPay(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMyPay *FormMyPay;
//---------------------------------------------------------------------------
#endif
