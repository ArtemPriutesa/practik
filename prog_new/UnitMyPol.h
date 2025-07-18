//---------------------------------------------------------------------------

#ifndef UnitMyPolH
#define UnitMyPolH
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
class TFormMyPol : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	int FUserID;
public:		// User declarations
	__fastcall TFormMyPol(TComponent* Owner);
	//void __fastcall SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMyPol *FormMyPol;
//---------------------------------------------------------------------------
#endif
