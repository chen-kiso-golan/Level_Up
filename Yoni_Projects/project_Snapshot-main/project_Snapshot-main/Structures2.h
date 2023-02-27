#pragma once

#include <windows.h>

//#include "Log1.h"
#include "yoni_Utilities.h"

typedef struct HeadOfSnapshotsList_Header
{
	int version;
	int Head_Of_Snapshots_Head_List_Counter;
	char Reserved[1000];
}t_HeadOfSnapshotsList_Header;

typedef struct HeadOfSnapshotsList {
	struct ProcessData* HeadOfSnapshot;
	struct ProcessData* HighestWorkingSetSize_In_One_p;
	int prosesCountOfEachHead;
	long int sum_of_Dll;//*************For generata HTML****************
	unsigned long Average_of_MemoryWorkingSetSize;//*************For generata HTML  //log int- because the number is very big****************
	struct HeadOfSnapshotsList* HeadListNext;
	struct HeadOfSnapshotsList* HeadListPrev;
}t_HeadOfSnapshotsList;

typedef struct DllList {
	//single dll info:
	char dllName[MAX_PATH];
	struct DllList* DllListNext;
	struct DllList* DllListPrev;
}t_DllList;


typedef struct ProcessData {
	//snapshot info:
	unsigned int CounterOfSnapshots;
	char TimeOfSnapshot[100];
	//process info:
	char ProcessName[MAX_PATH];
	DWORD ProcessId;
	//process memory use info:
	DWORD MemoryPageFaultCount;
	SIZE_T MemoryWorkingSetSize;
	SIZE_T MemoryQuotaPeakPagedPoolUsage;
	SIZE_T MemoryQuotaPagedPoolUsage;
	SIZE_T MemoryPagefileUsage;
	//dll list info:
	unsigned int DllCount;
	struct DllList* CurrentDll;
	//process linked list info:
	struct ProcessData* ProcessListNext;
	struct ProcessData* ProcessListPrev;
} t_ProcessData;


typedef struct Dic_Dll {
	char Dic_dllName[MAX_PATH];
	int Dic_counterOfProcess;
	struct Dic_Process* Dic_currProcess;
	struct Dic_Process* Dic_previtemProcess;
	struct Dic_Dll* DD_prev;
	struct Dic_Dll* DD_next;
}t_Dic_Dll;


typedef struct Dic_Process {
	char Dic_ProcessName[MAX_PATH];
	struct Dic_Process* DP_prev;
	struct Dic_Process* DP_next;
}t_Dic_Process;
