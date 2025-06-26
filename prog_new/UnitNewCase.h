//---------------------------------------------------------------------------

#ifndef UnitNewCaseH
#define UnitNewCaseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFormNewCase : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TDateTimePicker *DateTimePickerCase;
	TEdit *EditDescription;
	TADOConnection *ADOConnectionNewCase;
	TADOQuery *ADOQueryNewCase;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label4;
	TComboBox *ComboBoxPol;
	TADOQuery *ADOQueryPol;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);

private:	// User declarations
	int FUserId;
    int idPol;
public:		// User declarations
	__fastcall TFormNewCase(TComponent* Owner);
	void __fastcall LoadPolicies();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewCase *FormNewCase;
//---------------------------------------------------------------------------
#endif
