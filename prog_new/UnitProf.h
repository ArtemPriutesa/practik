//---------------------------------------------------------------------------

#ifndef UnitProfH
#define UnitProfH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFormProf : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TEdit *EditName;
	TLabel *Label3;
	TEdit *EditStatus;
	TLabel *Label4;
	TEdit *EditPolCount;
	TADOConnection *ADOConnectionProf;
	TADOQuery *ADOQueryProf;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    int FUserID; // ��� ��������� ID �������������� �����������
	void __fastcall LoadUserProfile();
public:		// User declarations
	__fastcall TFormProf(TComponent* Owner);
	//void __fastcall SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProf *FormProf;
//---------------------------------------------------------------------------
#endif
