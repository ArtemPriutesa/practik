#ifndef GlobalsH
#define GlobalsH

#include <System.hpp> // AnsiString
#include <Vcl.Forms.hpp>

extern int UserID;
extern AnsiString Username;

// Нове:
extern AnsiString CurrentTheme;

void LoadSettings();
void SaveSettings();
void ApplyStyle();;

#endif

