#pragma once
#include "structers.h"

//take one snepshot structrs : -----------------------------------------------------------------------------------

extern int CounterOfSnapshots;

extern int CounterOfHeads;

extern int CounterOfProcess;
extern unsigned long SumOfDll;
extern unsigned long long SumOfMemoryWorkingSet;
extern struct HeadOfSnapshotsList* HeadListHead;
extern struct HeadOfSnapshotsList* HeadListTail;
extern struct HeadOfSnapshotsList* CurrentHead;
extern struct HeadOfSnapshotsList* PrevItemHead;

extern struct DllList* DllListHead;
extern struct DllList* DllListTail;
extern struct DllList* CurrentDll;
extern struct DllList* PrevItemDll;

extern unsigned long long CounterOfDll;
extern struct OneProcessInfo* ProcessListHead;
extern struct OneProcessInfo* ProcessListTail;
extern struct OneProcessInfo* Current;
extern struct OneProcessInfo* PrevItem;


//DLL list: ---------------------------------------------------------------------------------------------------

extern struct Dic_Dll* DD_head;
extern struct Dic_Dll* DD_tail;
extern struct Dic_Dll* DD_prevItem;

extern struct Dic_Process* DP_tail;


void AddDllToLinkedlist_Dictionary(struct Dic_Dll* DD_current);
struct Dic_Process* AddProcessToLinkedlist_Dictionary(struct Dic_Process* DP_current, struct Dic_process* DP_head, struct Dic_Process* DP_prevItem);
void CreatDictionary_DP(struct Dic_Dll* DD_NewDll, char Dic_ProcessName[MAX_PATH]);
void CreatDictionary_DD(char Dic_dllName[MAX_PATH], char Dic_ProcessName[MAX_PATH]);

//sorted snapshot: -----------------------------------------------------------------------------------------------

void Replace(struct OneProcessInfo* item);
void snapshot_Shaiker_BubleSort();

//highest workingset icon: ---------------------------------------------------------------------------------------

void SearchHighestWorkingsetProcess(struct HeadOfSnapshotsList* headOfSnapshot);

//***take one snepshot functions : --------------------------------------------------------------------------------

void AddHeadToLinkedlist(struct HeadOfSnapshotsList* CurrentHead);
void AddProscessToLinkedlist(struct OneProcessInfo* Current);
void AddDllToLinkedlist(struct DllList* CurrentDll);
void GetMemoryAndDllInfo(DWORD processID, char strTime[100], int CounterOfSnapshots);
void GetProcessesInfo();

//***take 20 snepshots functions : -----------------------------------------------------------------------------------

void SearchDll(char KeyDll[MAX_PATH], struct OneProcessInfo* KeyAdress);
struct OneProcessInfo* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryPagefileUsage);
void GetMemoryAndDllInfo_20version(DWORD processID);
void GetProcessesInfo_noNull();
void GetProcessesInfo_20version();


//***take long snepshots functions : -----------------------------------------------------------------------------------

void GetProcessesInfo_UserVersion();

//***reset collection functions : -----------------------------------------------------------------------------------

void ResetCollections();