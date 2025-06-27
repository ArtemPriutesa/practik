//---------------------------------------------------------------------------

#ifndef UnitNewPolH
#define UnitNewPolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TFormNewPol : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Button1;
	TDateTimePicker *DateTimePickerStart;
	TSpinEdit *SpinEditTerm;
	TComboBox *ComboBoxType;
	TEdit *Edit1;
	TLabel *Label5;
	TButton *Button2;
	TADOQuery *ADOQuery1;
	TADOConnection *ADOConnection1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall DateTimePickerStartChange(TObject *Sender);
	void __fastcall SpinEditTermChange(TObject *Sender);
	void __fastcall ComboBoxTypeChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	int FUserID; // Для зберігання ID авторизованого користувача
	TDateTime FEndDate;
	double __fastcall CalculateBaseRate();
	void __fastcall UpdateBaseRateDisplay(); // Оновлює Edit1 (базову ставку)
	void __fastcall UpdateEndDateAndRate();
public:		// User declarations
	__fastcall TFormNewPol(TComponent* Owner);
   //	void __fastcall SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewPol *FormNewPol;
//---------------------------------------------------------------------------
#endif
