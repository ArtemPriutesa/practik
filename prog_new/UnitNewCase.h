//---------------------------------------------------------------------------

#ifndef UnitNewCaseH
#define UnitNewCaseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormNewCase : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TDateTimePicker *DateTimePicker1;
	TMemo *Memo1;
private:	// User declarations
public:		// User declarations
	__fastcall TFormNewCase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewCase *FormNewCase;
//---------------------------------------------------------------------------
#endif
