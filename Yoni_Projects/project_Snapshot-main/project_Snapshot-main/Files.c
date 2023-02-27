#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "Files5.h"




int err;
char* strE;


//---------------------------------------Save in File---------------------------------------------

void Save_Collections_In_File(char FileName[100]) {

	// malloc to Header of File + placement
	t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
	if (currHeader == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}
	currHeader->version = 1;
	currHeader->Head_Of_Snapshots_Head_List_Counter = Head_Of_Snapshots_Head_List_Counter;
	strcpy(currHeader->Reserved, "the File was Saved");



	t_HeadOfSnapshotsList* CurrHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
	t_ProcessData* CurrProcess = (t_ProcessData*)malloc(sizeof(t_ProcessData));
	t_DllList* CurrDll = (t_DllList*)malloc(sizeof(t_DllList));
	if (CurrHead == NULL || CurrProcess == NULL || CurrDll==NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}


	FILE* f = fopen(FileName, "wb");
	if (f) {

		int write = fwrite(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
		if (write == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}
		fclose(f);
	}
	else
	{	
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error
	}

	f = fopen(FileName, "ab");
	if (f) {

		CurrHead = HeadListHead;

		for (int i = 0; i < currHeader->Head_Of_Snapshots_Head_List_Counter; i++)
		{
			int write = fwrite(CurrHead, sizeof(t_HeadOfSnapshotsList), 1, f);
			if (!write) { //!write = if its not null its true 1=true    0=Fales
				err = GetLastError();
				strE = strerror(err);
				Error_Log(strE);
			}

			CurrProcess = CurrHead->HeadOfSnapshot;

			for (int i = 0; i < CurrHead->prosesCountOfEachHead; i++)
			{
				write = fwrite(CurrProcess, sizeof(t_ProcessData), 1, f);
				if (!write) {  //!write = if its not null its true 1=true    0=Fales
					err = GetLastError();
					strE = strerror(err);
					Error_Log(strE);
					//error
				}

				CurrDll = CurrProcess->CurrentDll;

				for (int i = 0; i < CurrProcess->DllCount; i++)
				{
					write = fwrite(CurrDll, sizeof(t_DllList), 1, f);
					if (!write) {  //!write = if its not null its true 1=true    0=Fales
						err = GetLastError();
						strE = strerror(err);
						Error_Log(strE);
						//error
					}
					CurrDll = CurrDll->DllListPrev;
				}
				CurrProcess = CurrProcess->ProcessListNext;
			}
			CurrHead = CurrHead->HeadListNext;
		}

		fclose(f);
		free(currHeader);
		free(CurrHead);
		free(CurrProcess);
		free(CurrDll);
	}
}

//---------------------------------------Save in File---------------------------------------------





//---------------------------------------Load From File-----------------------------------------------------------

void Load_Collections_From_File(char FileName[100]) {

	// malloc to Header of File + placement
	t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
	if (currHeader == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	Head_Of_Snapshots_Head_List_Counter = 0;
	prosesCount = 0;

	//// it is alredy "0" , - double check
	//sum_of_Dll = 0; //*************For generata HTML****************
	//sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************


	HeadListHead = NULL;
	HeadListTail = NULL;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	DllListHead = NULL;
	DllListTail = NULL;

	t_HeadOfSnapshotsList* CurrHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
	t_ProcessData* CurrProcess = (t_ProcessData*)malloc(sizeof(t_ProcessData));
	t_DllList* CurrDll = (t_DllList*)malloc(sizeof(t_DllList));
	if (CurrHead == NULL || CurrProcess == NULL || CurrDll == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	FILE* f = fopen(FileName, "rb");
	if (f) {

		int read = fread(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
		printf("Heder:: version:%d Itemcount:%d massege:%s\n\n", currHeader->version, currHeader->Head_Of_Snapshots_Head_List_Counter, currHeader->Reserved);
		if (read == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}


		for (int i = 0; i < currHeader->Head_Of_Snapshots_Head_List_Counter; i++)
		{
			read = fread(CurrHead, sizeof(t_HeadOfSnapshotsList), 1, f);
			if (!read) { //!write = if its not null its true 1=true    0=Fales
				err = GetLastError();
				strE = strerror(err);
				Error_Log(strE);
				//error
			}
			t_HeadOfSnapshotsList* Curr_Save_Head = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
			if (Curr_Save_Head == NULL) {
				err = GetLastError();
				strE = strerror(err);
				Error_Log(strE);
				return;
			}
			Curr_Save_Head->HeadOfSnapshot = CurrHead->HeadOfSnapshot;
			Curr_Save_Head->sum_of_Dll = CurrHead->sum_of_Dll;
			Curr_Save_Head->Average_of_MemoryWorkingSetSize = CurrHead->Average_of_MemoryWorkingSetSize;
			AddHeadToLinkedlist(Curr_Save_Head);

			CurrProcess = CurrHead->HeadOfSnapshot;

			for (int i = 0; i < CurrHead->prosesCountOfEachHead; i++)
			{
				read = fread(CurrProcess, sizeof(t_ProcessData), 1, f);
				if (!read) {  //!write = if its not null its true 1=true    0=Fales
					err = GetLastError();
					strE = strerror(err);
					Error_Log(strE);
					//error
				}
				t_ProcessData* Curr_save_Process = (t_ProcessData*)malloc(sizeof(t_ProcessData));
				if (Curr_save_Process == NULL) {
					err = GetLastError();
					strE = strerror(err);
					Error_Log(strE);
					return;
				}

				strcpy(Curr_save_Process->ProcessName, CurrProcess->ProcessName);
				strcpy(Curr_save_Process->TimeOfSnapshot, CurrProcess->TimeOfSnapshot);
				Curr_save_Process->CounterOfSnapshots = CurrProcess->CounterOfSnapshots;
				Curr_save_Process->CurrentDll = CurrProcess->CurrentDll;
				Curr_save_Process->DllCount = CurrProcess->DllCount;
				Curr_save_Process->MemoryPageFaultCount = CurrProcess->MemoryPageFaultCount;
				Curr_save_Process->MemoryPagefileUsage = CurrProcess->MemoryPagefileUsage;
				Curr_save_Process->MemoryQuotaPagedPoolUsage = CurrProcess->MemoryQuotaPagedPoolUsage;
				Curr_save_Process->MemoryQuotaPeakPagedPoolUsage = CurrProcess->MemoryQuotaPeakPagedPoolUsage;
				Curr_save_Process->MemoryWorkingSetSize = CurrProcess->MemoryWorkingSetSize;
				Curr_save_Process->ProcessId = CurrProcess->ProcessId;

				AddProscessToLinkedlist(Curr_save_Process);
				CurrDll = CurrProcess->CurrentDll;

				for (int i = 0; i < CurrProcess->DllCount; i++)
				{
					read = fread(CurrDll, sizeof(t_DllList), 1, f);
					if (!read) {  //!write = if its not null its true 1=true    0=Fales
						err = GetLastError();
						strE = strerror(err);
						Error_Log(strE);
						//error
					}
					t_DllList* Curr_save_Dll = (t_DllList*)malloc(sizeof(t_DllList));
					if (Curr_save_Dll == NULL) {
						err = GetLastError();
						strE = strerror(err);
						Error_Log(strE);
						return;
					}

					strcpy(Curr_save_Dll->dllName, CurrDll->dllName);
					AddDllToLinkedlist(Curr_save_Dll);
					CurrDll = CurrDll->DllListPrev;
				}
				DllListHead = NULL;
				DllListTail = NULL;
				CurrProcess = CurrProcess->ProcessListNext;
			}
			ProcessListHead = NULL;
			ProcessListTail = NULL;
			Curr_Save_Head->prosesCountOfEachHead = prosesCount;
			prosesCount = 0;
			CurrHead = CurrHead->HeadListNext;
		}

		fclose(f);
		free(CurrHead);
		free(CurrProcess);
		free(CurrDll);
	}
	else
	{
		//error
	}
}

//---------------------------------------Load From File-----------------------------------------------------------


