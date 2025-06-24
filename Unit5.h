//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TTFormCreatePolicy : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
private:	// User declarations
public:		// User declarations
	__fastcall TTFormCreatePolicy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTFormCreatePolicy *TFormCreatePolicy;
//---------------------------------------------------------------------------
#endif
