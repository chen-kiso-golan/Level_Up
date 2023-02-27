#pragma once
#include <Windows.h>
#include "log.h"

struct HeaderOfFile {
	int Version;
	int CounterOfHeads;
	char Extra[100];
};

struct HeadOfSnapshotsList {
	int CounterOfProcess;
	unsigned long SumOfDll;
	unsigned long AverageOfMemoryWorkingSet;
	struct OneProcessInfo* HighestWorkingsetProcess;
	struct OneProcessInfo* HeadOfSnapshot;
	struct HeadOfSnapshotsList* HeadListNext;
	struct HeadOfSnapshotsList* HeadListPrev;
};

struct DllList {
	//single dll info:
	char dllName[MAX_PATH];
	//dll linked list info:
	struct DllList* DllListNext;
	struct DllList* DllListPrev;
};

struct OneProcessInfo {
	int CounterOfDll;
	//snapshot info:
	int CounterOfSnapshots;
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
	//unsigned int DllCount;
	struct DllList* CurrentDll;
	//process linked list info:
	struct OneProcessInfo* ProcessListNext;
	struct OneProcessInfo* ProcessListPrev;
};

struct Dic_Dll {
	char Dic_dllName[MAX_PATH];
	int Dic_counterOfProcess;
	struct Dic_Process* Dic_currProcess;
	struct Dic_Process* Dic_previtemProcess;
	struct Dic_Dll* DD_prev;
	struct Dic_Dll* DD_next;
};

struct Dic_Process {
	char Dic_ProcessName[MAX_PATH];
	struct Dic_Process* DP_prev;
	struct Dic_Process* DP_next;
};

