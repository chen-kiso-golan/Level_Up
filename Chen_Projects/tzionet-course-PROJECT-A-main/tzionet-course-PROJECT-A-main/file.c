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

int err;
char* strE;


//***save in to file functions : -----------------------------------------------------------------------------------

void SaveSnapshotsToFile()
{
	FILE* f1 = fopen("projectAfile.bin", "wb");
	if (f1) {
		struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
		HeaderOfSnapshots->CounterOfHeads = CounterOfHeads;
		HeaderOfSnapshots->Version = 1;

		int write = fwrite(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
		if (write == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}
		fclose(f1);
	}
	else {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//log error
	}


	struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
	HeaderOfSnapshots->CounterOfHeads = CounterOfHeads;
	HeaderOfSnapshots->Version = 1;

	struct HeadOfSnapshotsList* CurrH = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
	struct OneProcessInfo* CurrP = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
	struct DllList* CurrD = (struct DllList*)malloc(sizeof(struct DllList));

	f1 = fopen("projectAfile.bin", "ab");
	if (f1) {

		CurrH = HeadListHead;

		for (int i = 0; i < HeaderOfSnapshots->CounterOfHeads; i++)
		{
			int write = fwrite(CurrH, sizeof(struct HeadOfSnapshotsList), 1, f1);
			if (!write) {
				err = GetLastError();
				strE = strerror(err);
				Error_Log(strE);
				//error
			}

			CurrP = CurrH->HeadOfSnapshot;

			for (int i = 0; i < CurrH->CounterOfProcess; i++)
			{
				write = fwrite(CurrP, sizeof(struct OneProcessInfo), 1, f1);
				if (!write) {
					err = GetLastError();
					strE = strerror(err);
					Error_Log(strE);
					//error
				}

				CurrD = CurrP->CurrentDll;

				for (int i = 0; i < CurrP->CounterOfDll; i++)
				{
					write = fwrite(CurrD, sizeof(struct DllList), 1, f1);
					if (!write) {
						err = GetLastError();
						strE = strerror(err);
						Error_Log(strE);
						//error
					}

					CurrD = CurrD->DllListPrev;
				}

				CurrP = CurrP->ProcessListNext;
			}

			CurrH = CurrH->HeadListNext;
		}

		fclose(f1);
		free(HeaderOfSnapshots);
		free(CurrH);
		free(CurrP);
		free(CurrD);
	}
	else
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error
	}
}

//----------------------------------------------------------------------------------------------------------------





//***load from file functions : -----------------------------------------------------------------------------------

void LoadSnapshotsFromFile(char FileName[100])
{
	struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
	struct HeadOfSnapshotsList* CurrH = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
	struct OneProcessInfo* CurrP = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
	struct DllList* CurrD = (struct DllList*)malloc(sizeof(struct DllList));
	//CounterOfSnapshots = 0;
	CounterOfHeads = 0;
	CounterOfProcess = 0;
	CounterOfDll = 0;
	SumOfDll = 0;
	SumOfMemoryWorkingSet = 0;
	HeadListHead = NULL;
	HeadListTail = NULL;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	DllListHead = NULL;
	DllListTail = NULL;

	FILE* f1 = fopen(FileName, "rb");
	if (f1) {
		int read = fread(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
		if (read == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}

		for (int i = 0; i < HeaderOfSnapshots->CounterOfHeads; i++)
		{
			read = fread(CurrH, sizeof(struct HeadOfSnapshotsList), 1, f1);
			if (!read) {
				err = GetLastError();
				strE = strerror(err);
				Error_Log(strE);
				//error
			}
			struct HeadOfSnapshotsList* CurrH1 = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
			CurrH1->HeadOfSnapshot = CurrH->HeadOfSnapshot;
			CurrH1->SumOfDll = CurrH->SumOfDll;
			CurrH1->AverageOfMemoryWorkingSet = CurrH->AverageOfMemoryWorkingSet;

			AddHeadToLinkedlist(CurrH1);
			CurrP = CurrH->HeadOfSnapshot;

			for (int i = 0; i < CurrH->CounterOfProcess; i++)
			{
				read = fread(CurrP, sizeof(struct OneProcessInfo), 1, f1);
				if (!read) {
					err = GetLastError();
					strE = strerror(err);
					Error_Log(strE);
					//error
				}
				struct OneProcessInfo* CurrP1 = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
				CurrP1->CounterOfSnapshots = CurrP->CounterOfSnapshots;
				CurrP1->CurrentDll = CurrP->CurrentDll;
				CurrP1->MemoryPageFaultCount = CurrP->MemoryPageFaultCount;
				CurrP1->MemoryPagefileUsage = CurrP->MemoryPagefileUsage;
				CurrP1->MemoryQuotaPagedPoolUsage = CurrP->MemoryQuotaPagedPoolUsage;
				CurrP1->MemoryQuotaPeakPagedPoolUsage = CurrP->MemoryQuotaPeakPagedPoolUsage;
				CurrP1->MemoryWorkingSetSize = CurrP->MemoryWorkingSetSize;
				CurrP1->ProcessId = CurrP->ProcessId;
				strcpy(CurrP1->ProcessName, CurrP->ProcessName);
				strcpy(CurrP1->TimeOfSnapshot, CurrP->TimeOfSnapshot);

				AddProscessToLinkedlist(CurrP1);
				CurrD = CurrP->CurrentDll;

				for (int i = 0; i < CurrP->CounterOfDll; i++)
				{
					read = fread(CurrD, sizeof(struct DllList), 1, f1);
					if (!read) {
						err = GetLastError();
						strE = strerror(err);
						Error_Log(strE);
						//error
					}

					struct DllList* CurrD1 = (struct DllList*)malloc(sizeof(struct DllList));
					strcpy(CurrD1->dllName, CurrD->dllName);

					AddDllToLinkedlist(CurrD1);

					CurrD = CurrD->DllListPrev;
				}
				DllListHead = NULL;
				DllListTail = NULL;
				CurrP1->CounterOfDll = CounterOfDll;
				CounterOfDll = 0;

				CurrP = CurrP->ProcessListNext;
			}
			ProcessListHead = NULL;
			ProcessListTail = NULL;
			CurrH1->CounterOfProcess = CounterOfProcess;
			CounterOfProcess = 0;

			CurrH = CurrH->HeadListNext;
		}

		fclose(f1);
		//free(HeaderOfSnapshots);
		free(CurrH);
		free(CurrP);
		free(CurrD);

	}
	else
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error
	}
}

//----------------------------------------------------------------------------------------------------------------