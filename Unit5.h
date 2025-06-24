//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <ADODB.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>

//---------------------------------------------------------------------------
class TFormCreatePolicy : public TForm
{
__published:
	TADOConnection *ADOConnectionCreatePolicy;
	TADOQuery *ADOQueryCreatePolicy;
	TComboBox *ComboBoxType;
	TDateTimePicker *DTPStartDate;
	TEdit *EditTermYears;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *ButtonCreate;
	TButton *ButtonCancel;
	TEdit *EditBaseRate;
	TLabel *Label7;
	TEdit *EditEndDate;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DTPStartDateChange(TObject *Sender);
	void __fastcall EditTermYearsChange(TObject *Sender);
	void __fastcall ComboBoxTypeChange(TObject *Sender);
	void __fastcall ButtonCreateClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);

private:	// User declarations
	int FUserID;
	TDateTime FEndDate;
	void __fastcall UpdateEndDateDisplay();
	double __fastcall CalculateBaseRate();
	void __fastcall UpdateBaseRate();
public:		// User declarations
	__fastcall TFormCreatePolicy(TComponent* Owner);
	void SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCreatePolicy *FormCreatePolicy;
//---------------------------------------------------------------------------
#endif
