//---------------------------------------------------------------------------

#ifndef UnitMyCaseH
#define UnitMyCaseH
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
class TFormMyCase : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridCases;
	TADOConnection *ADOConnectionMyCases;
	TADOQuery *ADOQueryMyCases;
	TDataSource *DataSourceMyCases;
	TButton *ButtonNewCase;
	TButton *ButtonClose;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	//void __fastcall ButtonNewCaseClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations
	int FUserID; // Для зберігання ID авторизованого користувача
	void __fastcall LoadUserCases(); // Завантажує страхові випадки поточного користувача
	void __fastcall SetDBGridColumnWidths();
public:		// User declarations
	__fastcall TFormMyCase(TComponent* Owner);
	void __fastcall SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMyCase *FormMyCase;
//---------------------------------------------------------------------------
#endif
