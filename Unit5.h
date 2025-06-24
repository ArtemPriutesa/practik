//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFormCreatePolicy : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TDateTimePicker *DTPStartDate;
	TEdit *EditTermYears;
	TDateTimePicker *DTPEndDate;
	TLabel *Label5;
	TEdit *EditBaseRate;
	TButton *ButtonCreate;
	TButton *Button2;
	TADOQuery *ADOQueryCreatePolicy;
	TADOConnection *ADOConnectionCreatePolicy;
	TComboBox *ComboBoxType;
	void __fastcall Label3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonCreateClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
    void __fastcall DTPStartDateChange(TObject *Sender);
	void __fastcall EditTermYearsChange(TObject *Sender);
	void __fastcall ComboBoxTypeChange(TObject *Sender);
	void __fastcall ComboBox1TypeChange(TObject *Sender);
private:	// User declarations
	int FUserID;
    void __fastcall UpdateEndDate();
	double __fastcall CalculateBaseRate();
public:		// User declarations
	__fastcall TFormCreatePolicy(TComponent* Owner);
	void SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCreatePolicy *FormCreatePolicy;
//---------------------------------------------------------------------------
#endif
