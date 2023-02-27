#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

#include "yoni_Utilities.h"


//----------------------------------------------log----------------------------------------------------
char Log_File_Name[100];

void Log(char massage[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);


	char str[100];
	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);

	FILE* f = fopen("New_Log_Pro.log", "a");
	fputs("\n\n", f);
	fputs(str, f);
	fputs("\n\n", f);


	fclose(f);
}

void Error_Log(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", message);
	Log(newMessage);
}

void Event_Log(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", message);
	Log(newMessage);
}

void Warning_Log(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Warning - %s", message);
	Log(newMessage);
}

void Log_init(char Log_Name[100])
{
	strcpy(Log_File_Name, Log_Name);
}
//----------------------------------------------log----------------------------------------------------


