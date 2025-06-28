//---------------------------------------------------------------------------

#ifndef UnitSaveH
#define UnitSaveH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TFormProgres : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormProgres(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProgres *FormProgres;
//---------------------------------------------------------------------------
#endif
