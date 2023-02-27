#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "snapshots.h"


int err;
char* strE;

//take one snepshot structrs : -----------------------------------------------------------------------------------

int CounterOfSnapshots = 0;

int CounterOfHeads = 0;

int CounterOfProcess = 0;
unsigned long SumOfDll = 0;
unsigned long long SumOfMemoryWorkingSet = 0;
struct HeadOfSnapshotsList* HeadListHead = NULL;
struct HeadOfSnapshotsList* HeadListTail = NULL;
struct HeadOfSnapshotsList* CurrentHead;
struct HeadOfSnapshotsList* PrevItemHead;

struct DllList* DllListHead = NULL;
struct DllList* DllListTail = NULL;
struct DllList* CurrentDll;
struct DllList* PrevItemDll;

unsigned long long CounterOfDll = 0;
struct OneProcessInfo* ProcessListHead = NULL;
struct OneProcessInfo* ProcessListTail = NULL;
struct OneProcessInfo* Current;
struct OneProcessInfo* PrevItem;


//DLL list: ---------------------------------------------------------------------------------------------------

struct Dic_Dll* DD_head = NULL;
struct Dic_Dll* DD_tail = NULL;
struct Dic_Dll* DD_prevItem;

struct Dic_Process* DP_tail = NULL;




void AddDllToLinkedlist_Dictionary(struct Dic_Dll* DD_current)
{


	if (DD_head == NULL) {
		DD_head = DD_current;
		DD_tail = DD_head;
		DD_current->DD_next = NULL;
		DD_current->DD_prev = NULL;
		DD_prevItem = DD_current;

	}
	else
	{
		DD_tail = DD_current;
		DD_tail->DD_prev = DD_prevItem;
		DD_tail->DD_next = NULL;
		DD_prevItem->DD_next = DD_tail;
		DD_prevItem = DD_current;
	}

	DD_current->Dic_counterOfProcess = 0;
	SumOfDll++;
}

struct Dic_Process* AddProcessToLinkedlist_Dictionary(struct Dic_Process* DP_current, struct Dic_process* DP_head, struct Dic_Process* DP_prevItem)
{

	if (DP_head == NULL) {
		DP_head = DP_current;
		DP_tail = DP_head;
		DP_current->DP_next = NULL;
		DP_current->DP_prev = NULL;
		DP_prevItem = DP_current;
	}
	else
	{
		DP_tail = DP_current;
		DP_tail->DP_prev = DP_prevItem;
		DP_tail->DP_next = NULL;
		DP_prevItem->DP_next = DP_tail;
		DP_prevItem = DP_current;
	}

	//Dic_counterOfProcess++;
	return DP_prevItem;
}

void CreatDictionary_DP(struct Dic_Dll* DD_NewDll, char Dic_ProcessName[MAX_PATH]) {


	struct Dic_Process* Dic_CurrentProcessKey = DD_NewDll->Dic_currProcess;

	while (Dic_CurrentProcessKey != NULL) {
		if (!(strcmp(Dic_CurrentProcessKey->Dic_ProcessName, Dic_ProcessName))) {
			return;
		}
		else {
			Dic_CurrentProcessKey = Dic_CurrentProcessKey->DP_next;
		}
	}

	struct Dic_Process* DP_NewProcess = (struct Dic_Process*)malloc(sizeof(struct Dic_Process));
	strcpy(DP_NewProcess->Dic_ProcessName, Dic_ProcessName);
	DD_NewDll->Dic_previtemProcess = AddProcessToLinkedlist_Dictionary(DP_NewProcess, DD_NewDll->Dic_currProcess, DD_NewDll->Dic_previtemProcess);
	DD_NewDll->Dic_counterOfProcess++;
}

void CreatDictionary_DD(char Dic_dllName[MAX_PATH], char Dic_ProcessName[MAX_PATH]) {

	struct Dic_Dll* Dic_CurrentDllKey = DD_head;

	while (Dic_CurrentDllKey != NULL) {
		if (!(strcmp(Dic_CurrentDllKey->Dic_dllName, Dic_dllName))) {
			CreatDictionary_DP(Dic_CurrentDllKey, Dic_ProcessName);
			return;
		}
		else {
			Dic_CurrentDllKey = Dic_CurrentDllKey->DD_next;
		}
	}

	struct Dic_Dll* DD_NewDll = (struct Dic_Dll*)malloc(sizeof(struct Dic_Dll));
	strcpy(DD_NewDll->Dic_dllName, Dic_dllName);
	AddDllToLinkedlist_Dictionary(DD_NewDll);
	DD_NewDll->Dic_currProcess = NULL;
	DD_NewDll->Dic_previtemProcess = NULL;


	struct Dic_Process* DP_NewProcess = (struct Dic_Process*)malloc(sizeof(struct Dic_Process));
	strcpy(DP_NewProcess->Dic_ProcessName, Dic_ProcessName);
	DD_NewDll->Dic_previtemProcess = AddProcessToLinkedlist_Dictionary(DP_NewProcess, DD_NewDll->Dic_currProcess, DD_NewDll->Dic_previtemProcess);
	DD_NewDll->Dic_counterOfProcess++;
	DD_NewDll->Dic_currProcess = DP_NewProcess;
}





//sorted snapshot: -----------------------------------------------------------------------------------------------

void Replace(struct OneProcessInfo* item)
{
	if (item == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//EventLogval("No need to swap", 0);
		return;
	}

	struct OneProcessInfo CopyList;
	struct OneProcessInfo* NextItem;
	struct OneProcessInfo* List;

	List = item;
	CopyList.ProcessListNext = item->ProcessListNext;
	CopyList.ProcessListPrev = item->ProcessListPrev;
	NextItem = item->ProcessListNext;

	if (item == ProcessListHead) {
		List->ProcessListPrev = NextItem;
		List->ProcessListNext = NextItem->ProcessListNext;
		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
		NextItem->ProcessListNext = List;
		List->ProcessListNext->ProcessListPrev = List;
		ProcessListHead = NextItem;
	}
	else if (item == ProcessListTail->ProcessListPrev)
	{
		List->ProcessListPrev = NextItem;
		List->ProcessListNext = NextItem->ProcessListNext;
		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
		NextItem->ProcessListNext = List;
		NextItem->ProcessListPrev->ProcessListNext = NextItem;
		if (ProcessListTail == NextItem) {
			ProcessListTail = List;
		}
	}
	else
	{
		List->ProcessListPrev = NextItem;
		List->ProcessListNext = NextItem->ProcessListNext;
		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
		NextItem->ProcessListNext = List;
		NextItem->ProcessListPrev->ProcessListNext = NextItem;
		List->ProcessListNext->ProcessListPrev = List;
	}
}

void snapshot_Shaiker_BubleSort()
{

	int Bublecounter = 1;

	struct OneProcessInfo* curr = ProcessListHead;
	struct OneProcessInfo* CheckItem = ProcessListHead->ProcessListNext;
	struct OneProcessInfo* CopyHead = NULL;
	struct OneProcessInfo* CopyTail = NULL;

	if (curr == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//EventLog("the list is empty");
		return;
	}

	while (Bublecounter != 0)
	{
		Bublecounter = 0;

		while (CheckItem != NULL && curr->ProcessListNext != CopyTail)
		{
			if (curr->CounterOfDll < CheckItem->CounterOfDll) {
				Replace(curr);
				CheckItem = curr->ProcessListNext;
				Bublecounter++;
			}
			else
			{
				curr = curr->ProcessListNext;
				CheckItem = CheckItem->ProcessListNext;
			}
		}
		CopyTail = curr;
		curr = curr->ProcessListPrev;
		CheckItem = curr->ProcessListPrev;


		while (CheckItem != NULL && curr->ProcessListPrev != CopyHead)
		{
			if (curr->CounterOfDll > CheckItem->CounterOfDll) {
				Replace(CheckItem);
				CheckItem = curr->ProcessListPrev;
				Bublecounter++;
			}
			else
			{
				curr = curr->ProcessListPrev;
				CheckItem = CheckItem->ProcessListPrev;
			}
		}
		CopyHead = curr;
		curr = curr->ProcessListNext;
		CheckItem = curr->ProcessListNext;

	}
	
}



//highest workingset icon: ---------------------------------------------------------------------------------------

void SearchHighestWorkingsetProcess(struct HeadOfSnapshotsList* headOfSnapshot) {

	struct OneProcessInfo* HolderOfHigestWSS = headOfSnapshot->HeadOfSnapshot;
	struct OneProcessInfo* CurrentKey = headOfSnapshot->HeadOfSnapshot->ProcessListNext;

	while (CurrentKey != NULL) {
		if (HolderOfHigestWSS->MemoryWorkingSetSize >= CurrentKey->MemoryWorkingSetSize) {

			CurrentKey = CurrentKey->ProcessListNext;
		}
		else {

			//*******placement******
			HolderOfHigestWSS = CurrentKey;
			CurrentKey = CurrentKey->ProcessListNext;
		}
	}

	headOfSnapshot->HighestWorkingsetProcess = HolderOfHigestWSS;

	return;
}




//***take one snepshot functions : --------------------------------------------------------------------------------

//5----------------------------------------------------------------------------------------------------------------

void AddHeadToLinkedlist(struct HeadOfSnapshotsList* CurrentHead)
{

	if (HeadListHead == NULL) {
		HeadListHead = CurrentHead;
		HeadListTail = HeadListHead;
		CurrentHead->HeadListNext = NULL;
		CurrentHead->HeadListPrev = NULL;
		PrevItemHead = CurrentHead;
	}
	else
	{
		HeadListTail = CurrentHead;
		HeadListTail->HeadListPrev = PrevItemHead;
		HeadListTail->HeadListNext = NULL;
		PrevItemHead->HeadListNext = HeadListTail;
		PrevItemHead = CurrentHead;
	}

	CounterOfHeads++;
}

//4----------------------------------------------------------------------------------------------------------------

void AddProscessToLinkedlist(struct OneProcessInfo* Current)
{
	if (!strstr(Current->ProcessName, "exe")) {
		return;
	}

	if (ProcessListHead == NULL) {
		ProcessListHead = Current;
		ProcessListTail = ProcessListHead;
		Current->ProcessListNext = NULL;
		Current->ProcessListPrev = NULL;
		PrevItem = Current;
	}
	else
	{
		ProcessListTail = Current;
		ProcessListTail->ProcessListPrev = PrevItem;
		ProcessListTail->ProcessListNext = NULL;
		PrevItem->ProcessListNext = ProcessListTail;
		PrevItem = Current;
	}

	CounterOfProcess++;
}

//3----------------------------------------------------------------------------------------------------------------

void AddDllToLinkedlist(struct DllList* CurrentDll)
{

	if (DllListHead == NULL) {
		DllListHead = CurrentDll;
		DllListTail = DllListHead;
		CurrentDll->DllListNext = NULL;
		CurrentDll->DllListPrev = NULL;
		PrevItemDll = CurrentDll;
	}
	else
	{
		DllListTail = CurrentDll;
		DllListTail->DllListPrev = PrevItemDll;
		DllListTail->DllListNext = NULL;
		PrevItemDll->DllListNext = DllListTail;
		PrevItemDll = CurrentDll;
	}

	CounterOfDll++;
}

//2----------------------------------------------------------------------------------------------------------------

void GetMemoryAndDllInfo(DWORD processID, char strTime[100], int CounterOfSnapshots)
{
	//*******placement******
	struct OneProcessInfo* Current = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));

	//*******placement******
	Current->CounterOfSnapshots = CounterOfSnapshots;

	//*******placement******
	strcpy(Current->TimeOfSnapshot, strTime);

	//*******placement******
	Current->ProcessId = processID;

	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info

  //like doing "fopen" of a process by using the id and pointer
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	if (NULL == hProcess) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error. write to log
		return;
	}

	HMODULE hMods[1024];  //*** hMods - an array of all the dll of one process
	DWORD cbNeeded;
	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
	TCHAR Buffer2[MAX_PATH];  //*** buffer2 - contains the full path (name) to the dll.

	//Get process name
	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
	{

		//*******placement******
		// Convert wChar to regular char array (string)
		size_t numConverted;
		wcstombs_s(&numConverted, Current->ProcessName, MAX_PATH, Buffer, MAX_PATH);
	}
	else
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error. write to log
	}

	//Get memory info
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		//*******placement******
		Current->MemoryPageFaultCount = pmc.PageFaultCount;
		Current->MemoryWorkingSetSize = pmc.PeakWorkingSetSize;
		Current->MemoryQuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		Current->MemoryQuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		Current->MemoryPagefileUsage = pmc.PagefileUsage;
		SumOfMemoryWorkingSet = SumOfMemoryWorkingSet + Current->MemoryWorkingSetSize;
	}

	//Get Dlls List
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{

		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{

			//Get dll name, general count, index
			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
			{
				//*******placement******
				struct DllList* CurrentDll = (struct DllList*)malloc(sizeof(struct DllList));
				Current->CurrentDll = CurrentDll;

				// Convert wChar to regular char array (string)
				//*******placement******
				size_t numConverted;
				wcstombs_s(&numConverted, CurrentDll->dllName, MAX_PATH, Buffer2, MAX_PATH);

				//creat dlls linked list
				AddDllToLinkedlist(CurrentDll);

				CreatDictionary_DD(CurrentDll->dllName, Current->ProcessName);
			}
		}

		DllListHead = NULL;
		DllListTail = NULL;
		Current->CounterOfDll = CounterOfDll;
		//SumOfDll = SumOfDll + CounterOfDll;
		CounterOfDll = 0;
	}

	//creat processes linked list
	AddProscessToLinkedlist(Current);

	CloseHandle(hProcess);
}

//1----------------------------------------------------------------------------------------------------------------

void GetProcessesInfo()
{

	//Get Processes - Receive all process ID
	DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
	unsigned int i;

	//Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//Error. Write to log
		return 1;
	}

	//Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	//saves the time for each snapshot
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char strTime[100];
	sprintf(strTime, "%d.%d.%d-%d:%d:%d ", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	//saves the number of snapshots taken
	CounterOfSnapshots++;

	//Loop of all processes - For each Process, get its Memory Information
	for (i = 0; i < cProcesses; i++)
	{
		GetMemoryAndDllInfo(aProcesses[i], strTime, CounterOfSnapshots);
		//*** aProcesses[i] - the id of a singel process
	}

	snapshot_Shaiker_BubleSort();

	struct HeadOfSnapshotsList* CurrentHead = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
	CurrentHead->HeadOfSnapshot = ProcessListHead;
	CurrentHead->CounterOfProcess = CounterOfProcess;
	CurrentHead->SumOfDll = SumOfDll;
	CurrentHead->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
	AddHeadToLinkedlist(CurrentHead);

	SearchHighestWorkingsetProcess(CurrentHead);

	ProcessListHead = NULL;
	ProcessListTail = NULL;
	CounterOfProcess = 0;
	//SumOfDll = 0;
	SumOfMemoryWorkingSet = 0;
}

//----------------------------------------------------------------------------------------------------------------







//***take 20 snepshots functions : -----------------------------------------------------------------------------------

//5----------------------------------------------------------------------------------------------------------------

void SearchDll(char KeyDll[MAX_PATH], struct OneProcessInfo* KeyAdress) {

	struct DllList* CurrentDllKey = KeyAdress->CurrentDll;

	while (CurrentDllKey != NULL) {
		if (!(strcmp(CurrentDllKey->dllName, KeyDll))) {
			return;
		}
		else {
			CurrentDllKey = CurrentDllKey->DllListPrev;
		}
	}

	struct DllList* NewDll = (struct DllList*)malloc(sizeof(struct DllList));
	strcpy(NewDll->dllName, KeyDll);
	KeyAdress->CurrentDll->DllListNext = NewDll;
	NewDll->DllListPrev = KeyAdress->CurrentDll;
	NewDll->DllListNext = NULL;
	KeyAdress->CurrentDll = NewDll;
	CounterOfDll++;
	//SumOfDll++;
	KeyAdress->CounterOfDll = CounterOfDll;

}

//4----------------------------------------------------------------------------------------------------------------

struct OneProcessInfo* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryPagefileUsage) {

	struct OneProcessInfo* CurrentKey = HeadListTail->HeadOfSnapshot;
	CurrentHead = HeadListTail;

	while (CurrentKey != NULL) {
		if ((!(strcmp(CurrentKey->ProcessName, key))) && processID == CurrentKey->ProcessId) {

			//*******placement******
			CurrentKey->MemoryPageFaultCount = CurrentKey->MemoryPageFaultCount + MemoryPageFaultCount;
			CurrentKey->MemoryWorkingSetSize = CurrentKey->MemoryWorkingSetSize + MemoryWorkingSetSize;
			CurrentKey->MemoryQuotaPeakPagedPoolUsage = CurrentKey->MemoryQuotaPeakPagedPoolUsage + MemoryQuotaPeakPagedPoolUsage;
			CurrentKey->MemoryQuotaPagedPoolUsage = CurrentKey->MemoryQuotaPagedPoolUsage + MemoryQuotaPagedPoolUsage;
			CurrentKey->MemoryPagefileUsage = CurrentKey->MemoryPagefileUsage + MemoryPagefileUsage;
			SumOfMemoryWorkingSet = SumOfMemoryWorkingSet + CurrentKey->MemoryWorkingSetSize;
			return CurrentKey;
		}
		else {
			CurrentKey = CurrentKey->ProcessListNext;
		}
	}

	GetMemoryAndDllInfo(processID, HeadListTail->HeadOfSnapshot->TimeOfSnapshot, HeadListTail->HeadOfSnapshot->CounterOfSnapshots);
	CurrentHead->CounterOfProcess = CounterOfProcess;
	return NULL;
}

//3----------------------------------------------------------------------------------------------------------------

void GetMemoryAndDllInfo_20version(DWORD processID)
{
	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info

  //like doing "fopen" of a process by using the id and pointer
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	if (NULL == hProcess) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error. write to log
		return;
	}

	HMODULE hMods[1024];  //*** hMods - an array of all the dll of one process
	DWORD cbNeeded;
	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
	TCHAR Buffer2[MAX_PATH];  //*** buffer2 - contains the full path (name) to the dll.
	char KeyProcess[MAX_PATH];
	char KeyDll[MAX_PATH];
	struct OneProcessInfo* KeyAdress = NULL;

	//Get process name
	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
	{

		//*******placement******
		// Convert wChar to regular char array (string)
		size_t numConverted;
		wcstombs_s(&numConverted, KeyProcess, MAX_PATH, Buffer, MAX_PATH);
	}
	else
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error. write to log
	}

	//Get memory info
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		//*******placement******
		KeyAdress = SearchProcess(processID, KeyProcess, pmc.PageFaultCount, pmc.PeakWorkingSetSize, pmc.QuotaPagedPoolUsage, pmc.QuotaPeakPagedPoolUsage, pmc.PagefileUsage);
	}

	//Get Dlls List
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{

		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{

			//Get dll name, general count, index
			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
			{
				// Convert wChar to regular char array (string)
				//*******placement******
				size_t numConverted;
				wcstombs_s(&numConverted, KeyDll, MAX_PATH, Buffer2, MAX_PATH);

				if (KeyAdress == NULL) {
					return;
				}

				SearchDll(KeyDll, KeyAdress);

				CreatDictionary_DD(KeyDll, KeyProcess);
			}
		}
	}
	CloseHandle(hProcess);
}

//2----------------------------------------------------------------------------------------------------------------

void GetProcessesInfo_noNull()
{

	//Get Processes - Receive all process ID
	DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
	unsigned int i;

	//Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//Error. Write to log
		return 1;
	}

	//Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	//saves the time for each snapshot
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char strTime[100];
	sprintf(strTime, "%d.%d.%d-%d:%d:%d ", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	//saves the number of snapshots taken
	CounterOfSnapshots++;

	//Loop of all processes - For each Process, get its Memory Information
	for (i = 0; i < cProcesses; i++)
	{
		GetMemoryAndDllInfo(aProcesses[i], strTime, CounterOfSnapshots);
		//*** aProcesses[i] - the id of a singel process
	}

	struct HeadOfSnapshotsList* CurrentHead = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
	CurrentHead->HeadOfSnapshot = ProcessListHead;
	CurrentHead->CounterOfProcess = CounterOfProcess;
	CurrentHead->SumOfDll = SumOfDll;
	CurrentHead->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
	AddHeadToLinkedlist(CurrentHead);
}

//1----------------------------------------------------------------------------------------------------------------

void GetProcessesInfo_20version()
{

	GetProcessesInfo_noNull();

	for (int i = 0; i < 3; i++) {

		Sleep(1000);

		//Get Processes - Receive all process ID
		DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
		unsigned int i;

		//Receive all process ID and put in aProcesses Array
		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//Error. Write to log
			return 1;
		}

		//Calculate how many process identifiers were returned.
		cProcesses = cbNeeded / sizeof(DWORD);

		//Loop of all processes - For each Process, get its Memory Information
		for (i = 0; i < cProcesses; i++)
		{
			GetMemoryAndDllInfo_20version(aProcesses[i]);
			//*** aProcesses[i] - the id of a singel process
		}
	}

	snapshot_Shaiker_BubleSort();

	HeadListTail->HeadOfSnapshot = ProcessListHead;
	HeadListTail->SumOfDll = SumOfDll;
	HeadListTail->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;

	SearchHighestWorkingsetProcess(HeadListTail);

	//SumOfDll = 0;
	SumOfMemoryWorkingSet = 0;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	CounterOfProcess = 0;
	//doubel check:
	DllListHead = NULL;
	DllListTail = NULL;

}

//----------------------------------------------------------------------------------------------------------------





//***take long snepshots functions : -----------------------------------------------------------------------------------

void GetProcessesInfo_UserVersion()
{

	GetProcessesInfo_noNull();

	int Stop = 1;

	while (Stop)
	{

		Sleep(1000);

		//Get Processes - Receive all process ID
		DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
		unsigned int i;

		//Receive all process ID and put in aProcesses Array
		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//Error. Write to log
			return 1;
		}

		//Calculate how many process identifiers were returned.
		cProcesses = cbNeeded / sizeof(DWORD);

		//Loop of all processes - For each Process, get its Memory Information
		for (i = 0; i < cProcesses; i++)
		{
			GetMemoryAndDllInfo_20version(aProcesses[i]);
			//*** aProcesses[i] - the id of a singel process
		}

		if (kbhit())
		{
			char ch1 = getch();
			if (ch1 == 'E')
				Stop = 0;
		}
	}

	snapshot_Shaiker_BubleSort();
	HeadListTail->HeadOfSnapshot = ProcessListHead;
	HeadListTail->SumOfDll = SumOfDll;
	HeadListTail->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;

	SearchHighestWorkingsetProcess(HeadListTail);

	//SumOfDll = 0;
	SumOfMemoryWorkingSet = 0;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	CounterOfProcess = 0;
	//doubel check:
	DllListHead = NULL;
	DllListTail = NULL;

}

//----------------------------------------------------------------------------------------------------------------





//***reset collection functions : -----------------------------------------------------------------------------------

void ResetCollections() {

	//reset all snapshots:
	struct HeadOfSnapshotsList* CurrentFreeHead = HeadListHead;
	struct HeadOfSnapshotsList* FreeHead = NULL;


	//if there are no lists to reset:
	if (CurrentFreeHead == NULL) {
		//log error.
		printf("there are no snapshots to reset");
		return;
	}

	//reset one snapshot:
	while (CurrentFreeHead->HeadListNext != NULL) {

		struct OneProcessInfo* CurrentFreeProcess = CurrentFreeHead->HeadOfSnapshot;
		struct OneProcessInfo* FreeProcess = NULL;

		//reset one process:
		while (CurrentFreeProcess->ProcessListNext != NULL) {

			struct DllList* CurrentFreeDll = CurrentFreeProcess->CurrentDll;
			struct DllList* FreeDll = NULL;

			//reset dll list in one process:
			while (CurrentFreeDll->DllListPrev != NULL) {
				//go to next dll:
				FreeDll = CurrentFreeDll;
				CurrentFreeDll = CurrentFreeDll->DllListPrev;
				free(FreeDll);
			}
			//free last dll:
			FreeDll = CurrentFreeDll;
			free(FreeDll);

			//go to next process:
			FreeProcess = CurrentFreeProcess;
			CurrentFreeProcess = CurrentFreeProcess->ProcessListNext;
			free(FreeProcess);
		}
		//free last process:
		FreeProcess = CurrentFreeProcess;
		free(FreeProcess);

		//go to next snapshot:
		FreeHead = CurrentFreeHead;
		CurrentFreeHead = CurrentFreeHead->HeadListNext;
		free(FreeHead);
	}
	//free last head:
	FreeHead = CurrentFreeHead;
	free(FreeHead);

	HeadListHead = NULL;
	HeadListTail = NULL;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	DllListHead = NULL;
	DllListTail = NULL;
	CounterOfHeads = 0;
	CounterOfProcess = 0;
	CounterOfDll = 0;
	CounterOfSnapshots = 0;
	SumOfDll = 0;
	SumOfMemoryWorkingSet = 0;

	//-----------------------------------------------------

	struct Dic_Dll* CurrentFreeDD = DD_head;
	struct Dic_Dll* FreeDD = NULL;

	while (CurrentFreeDD->DD_next != NULL) {

		struct Dic_Process* CurrentFreeDP = CurrentFreeDD->Dic_currProcess;
		struct Dic_Process* FreeDP = NULL;

		//DICTIONARY - reset process list in one DLL:
		while (CurrentFreeDP->DP_next != NULL) {
			//go to next process:
			FreeDP = CurrentFreeDP;
			CurrentFreeDP = CurrentFreeDP->DP_next;
			free(FreeDP);
		}
		//free last process:
		FreeDP = CurrentFreeDP;
		free(FreeDP);

		//DICTIONARY - go to next DLL:
		FreeDD = CurrentFreeDD;
		CurrentFreeDD = CurrentFreeDD->DD_next;
		free(FreeDD);
	}

	//free last DLL:
	FreeDD = CurrentFreeDD;
	free(FreeDD);

	DD_head = NULL;
	DD_tail = NULL;
	DP_tail = NULL;

	//-----------------------------------------------------


	//clean the file:
	FILE* f1 = fopen("projectAfile.bin", "wb");
	if (f1) {
		struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
		HeaderOfSnapshots->CounterOfHeads = 0;
		HeaderOfSnapshots->Version = 0;
		strcpy(HeaderOfSnapshots->Extra, "reset function was used");

		int write = fwrite(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
		if (write == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}
	}
	else {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//log error
	}
	fclose(f1);
}

//----------------------------------------------------------------------------------------------------------------





