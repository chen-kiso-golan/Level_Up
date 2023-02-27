#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "file.h"

#define clear() printf("\033[H\033[J")
//https://stackoverflow.com/questions/26423537/how-to-position-the-input-text-cursor-in-c


int main()
{

	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);


	char Log_Name[100];
	sprintf(Log_Name, "LOG_%d-%d-%d_%d-%d-%d.log", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	Log_init(Log_Name);

	Event_Log("program started");




	char User= 0;

	while (User != 8) {
		Sleep(1000);
		clear();
		printf("\n~ Type Option Number For Execution ~\n1.Take One SnapShot.\n2.Take 20 Seconds SnapShot.\n3.Start Long SnapShot.\n4.Generate HTML Report.\n5.Reset Collections.\n6.Save in File.\n7.Load from File.\n8.Quit\ntype here:");
		User = getch();
		printf("\n\n\n");
		clear();

		switch (User)
		{
		case '1':
			Error_Log("*******Start SnapShot*****");
			GetProcessesInfo();
			printf("\n\n you took one SnapShot successfully!!!\n\n");
			Error_Log("*******End SnapShot*******");
			break;
		case '2':
			Error_Log("*******Start 20_SnapShot*****");
			printf("\nStart to take 20 SnapShots\n\n");
			GetProcessesInfo_20version();
			printf("\n\n you took 20 SnapShots successfully!!!\n\n");
			Error_Log("*******End 20_SnapShot*****");
			break;
		case '3':
			Error_Log("*******Start Long_SnapShot*****");
			printf("\nprese 'E' to End the Long SnapShot\n\n");
			GetProcessesInfo_UserVersion();
			printf("\n\n you took a Long SnapShot successfully!!!\n\n");
			Error_Log("*******End Long_SnapShot****");
			break;
		case '4':
			Error_Log("*****Start Generate HTML Report****");
			GenerateHtmlReport();
			printf("\n\n you Created HTML Report successfully!!!\n\n");
			Error_Log("*****End Gnerate HTML Report****");
			break;
		case '5':
			Error_Log("*******Reset Collections*****");
			ResetCollections();
			printf("\n\nThe Reset was successfull!!!\n\n");
			Error_Log("*******End Reset Collections*****");
			break;
		case '6':
			Error_Log("*******Save in File*******");
			SaveSnapshotsToFile();
			printf("\n\n you saved the file successfully!!!\n\n");
			Error_Log("*******End Save in File*******");
			break;
		case '7':
			Error_Log("***Load_Collections_From_File****");
			LoadSnapshotsFromFile("projectAfile.bin");
			printf("\n\n you loded the file successfully!!!\n\n");
			Error_Log("***End Load_Collections_From_File******");
			break;
		case '8':
			return;
		default:
			printf("invalid number");
			printf("\n\n");
			break;
		}
	}
	return 0;
}