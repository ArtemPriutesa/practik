//---------------------------------------------------------------------------

#ifndef UnitOfficeH
#define UnitOfficeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormOffice : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TGroupBox *GroupBox1;
	TButton *ButtonProf;
	TButton *ButtonNewPol;
	TButton *ButtonHist;
	TButton *ButtonMyPoly;
	TButton *Button5;
	TLabel *Label1;
	TImage *Image1;
	void __fastcall ButtonNewPolClick(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall ButtonMyPolyClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ButtonProfClick(TObject *Sender);
	void __fastcall ButtonHistClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonNoMyCaseClick(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormOffice(TComponent* Owner);
    int AuthenticatedUserID;
	AnsiString AuthenticatedUsername;
	void SetUserID(int UserID);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOffice *FormOffice;
//---------------------------------------------------------------------------
#endif
