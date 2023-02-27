#pragma once

#include "Structures2.h"


extern t_HeadOfSnapshotsList* HeadListHead;
extern t_HeadOfSnapshotsList* HeadListTail;
extern t_HeadOfSnapshotsList* CurrentHead;
extern t_HeadOfSnapshotsList* PrevItemHead;


extern t_DllList* DllListHead;
extern t_DllList* DllListTail;
extern t_DllList* CurrentDll;
extern t_DllList* PrevItemDll;


extern t_ProcessData* ProcessListHead;
extern t_ProcessData* ProcessListTail;
extern t_ProcessData* Current;
extern t_ProcessData* PrevItem;



extern t_Dic_Dll* DD_head;
extern t_Dic_Dll* DD_tail;
extern t_Dic_Dll* DD_prevItem;


extern t_Dic_Process* DP_tail;



extern int CounterOfSnapshots;
extern int Head_Of_Snapshots_Head_List_Counter;
extern int sum_of_Dll; //*************For generata HTML****************
extern unsigned long long sum_of_MemoryWorkingSetSize; //*************For generata HTML****************
extern int prosesCount;




//---------------------------------------------------snapshot-------------------------------------------------------------
void AddHeadToLinkedlist(t_HeadOfSnapshotsList* CurrentHead);
void AddProscessToLinkedlist(t_ProcessData* Current);
void AddDllToLinkedlist(t_DllList* CurrentDll);
void GetMemoryAndDllInfo(DWORD processID, char strTime[100], int CounterOfSnapshots);
void GetProcessesInfo();
//---------------------------------------------------snapshot-------------------------------------------------------------




//-------------------------------------20 snapshot------------------------------------------

t_ProcessData* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryPagefileUsage);
void searchDll(char keyDLL[MAX_PATH], t_ProcessData* currproses);
void GetProcessesInfo_WithoutNULL();
void GetMemoryAndDllInfo_20(DWORD processID);
void GetProcessesInfo_20();

//-------------------------------------20 snapshot------------------------------------------




//---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------

void GetProcessesInfo_Long_SnapShot();

//---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------





//---------------------------------------reset collection functions---------------------------------------------

void ResetCollections();

//---------------------------------------reset collection functions---------------------------------------------