#pragma once

#include "snapshots.h"

//***creating html from the data: -----------------------------------------------------------------------------------

int SaveHTMLIntoFile(char* fileName, char* buff);
char* ReadAllHTMLFile(char* fileName);
void HTML_HomePgae();
void HTML_SnapshotPage(struct HeadOfSnapshotsList* currentHead);
void HTML_SnapshotPageLoop();
void HTML_DllPgae(struct Dic_Dll* currentDll, unsigned int counter);
void HTML_DllPgaeLoop();
void GenerateHtmlReport();
