#pragma once

#include "Data_Base_SnapShot3.h"



//---------------------------------------Generate_HTML_Report---------------------------------------------

void Html_SaveIntoFile(char* fileName, char* buff);
char* ReadAllFile(char* fileName);
void HomePgaeGenerator();
void SamplePgaeGenerator(t_HeadOfSnapshotsList* currentH);
void SamplePgaeGeneratorLoop();
void DllPgaeGenerator(t_Dic_Dll* currentD, unsigned int counter);
void DllPgaeGeneratorLoop();

//---------------------------------------Generate_HTML_Report---------------------------------------------