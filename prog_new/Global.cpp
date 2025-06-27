#include <vcl.h>
#include <IniFiles.hpp>
#include "Global.h" // ��� "Globals.h"

int UserID = -1;
AnsiString Username = "";
AnsiString CurrentTheme = "Light";  // ���� �� �������������

void LoadSettings() {
	TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName) + "Settings.ini");
	CurrentTheme = ini->ReadString("Appearance", "Theme", "Light");
	delete ini;
}

void SaveSettings() {
	TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName) + "Settings.ini");
	ini->WriteString("Appearance", "Theme", CurrentTheme);
	delete ini;
}


void ApplyStyle() {
	if (CurrentTheme == "Dark")
		TStyleManager::TrySetStyle("Carbon");
	else if (CurrentTheme == "Night")
		TStyleManager::TrySetStyle("Tablet Dark");
	else
		TStyleManager::TrySetStyle("Windows10");
}





