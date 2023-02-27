#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "Data_Base_SnapShot3.h"


t_HeadOfSnapshotsList* HeadListHead = NULL;
t_HeadOfSnapshotsList* HeadListTail = NULL;
t_HeadOfSnapshotsList* CurrentHead;
t_HeadOfSnapshotsList* PrevItemHead;


t_DllList* DllListHead = NULL;
t_DllList* DllListTail = NULL;
t_DllList* CurrentDll;
t_DllList* PrevItemDll;


t_ProcessData* ProcessListHead = NULL;
t_ProcessData* ProcessListTail = NULL;
t_ProcessData* Current;
t_ProcessData* PrevItem;



t_Dic_Dll* DD_head = NULL;
t_Dic_Dll* DD_tail = NULL;
t_Dic_Dll* DD_prevItem;


t_Dic_Process* DP_tail = NULL;



int CounterOfSnapshots = 0;
int Head_Of_Snapshots_Head_List_Counter = 0;
int sum_of_Dll = 0; //*************For generata HTML****************
unsigned long long sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
int prosesCount = 0;



int err;
char* strE;

//---------------------------------------------------Dic+Shaiker-------------------------------------------------------------

void Search_HighestWorkingSetSize_In_One_p(t_HeadOfSnapshotsList* headOfSnapshot) {

	t_ProcessData* HolderOfHigestWSS = headOfSnapshot->HeadOfSnapshot;
	t_ProcessData* List = headOfSnapshot->HeadOfSnapshot->ProcessListNext;
	if (HolderOfHigestWSS == NULL || List == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	while (List != NULL) {
		if (HolderOfHigestWSS->MemoryWorkingSetSize >= List->MemoryWorkingSetSize) {

			List = List->ProcessListNext;
		}
		else {

			//*********placement**********
			HolderOfHigestWSS = List;
			List = List->ProcessListNext;
		}
	}

	headOfSnapshot->HighestWorkingSetSize_In_One_p = HolderOfHigestWSS;

	return;
}

void AddDllToLinkedlist_Dictionary(t_Dic_Dll* DD_current)
{

	DD_current->Dic_counterOfProcess = 0;
	sum_of_Dll++; //*************For generata HTML****************

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
}

struct Dic_Process* AddProcessToLinkedlist_Dictionary(t_Dic_Process* DP_current, t_Dic_Process* DP_head, t_Dic_Process* DP_prevItem)
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

void CreatDictionary_DP(t_Dic_Dll* DD_NewDll, char Dic_ProcessName[MAX_PATH]) {


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

void CreatDictionary_DD_Generate_HTML_Report(char Dic_dllName[MAX_PATH], char Dic_ProcessName[MAX_PATH]) {

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

void Replace(t_ProcessData* item)
{
	if (item == NULL) {
		//	EventLogval("No need to swap", 0);
		return;
	}

	//CopyList = (t_ItemNum*)malloc(sizeof(t_ItemNum));
	t_ProcessData CopyList;
	t_ProcessData* NextItem;
	t_ProcessData* List;

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
	//free(CopyList);
}

void Shaiker_Sort_ProcessDataByDllCount()
{
	int Bublecounter = 1;

	// add search tail




	t_ProcessData* curr = ProcessListHead; // enter the real head
	t_ProcessData* CheckItem;
	t_ProcessData* CopyHead = NULL;
	t_ProcessData* CopyTail = NULL;

	if (!curr/* !curr = curr!=NULL*/) {
		//EventLog("the list is empty");
		return;
	}

	// add search tail


	//EventLog("Start sorting");
	while (Bublecounter != 0)
	{
		curr = ProcessListHead;
		CheckItem = ProcessListHead->ProcessListNext;

		while (Bublecounter != 0)
		{
			Bublecounter = 0;

			while (CheckItem != NULL && curr->ProcessListNext != CopyTail)
			{
				if (curr->DllCount < CheckItem->DllCount) {
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
				if (curr->DllCount > CheckItem->DllCount) {
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
	//EventLog("End sorting");

}

//---------------------------------------------------Dic+Shaiker-------------------------------------------------------------


//---------------------------------------------------snapshot-------------------------------------------------------------

void AddHeadToLinkedlist(t_HeadOfSnapshotsList* CurrentHead)
{
	Head_Of_Snapshots_Head_List_Counter++;

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
}


void AddProscessToLinkedlist(t_ProcessData* Current)
{
	if (!strstr(Current->ProcessName, "exe")) {
		return;
	}
	prosesCount++;

	Current->ProcessListNext = NULL;

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
}


void AddDllToLinkedlist(t_DllList* CurrentDll)
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
}


void GetMemoryAndDllInfo(DWORD processID, char strTime[100], int CounterOfSnapshots)
{

	//**placement***
	t_ProcessData* Curr = (t_ProcessData*)malloc(sizeof(t_ProcessData));
	if (Curr == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	Curr->ProcessListNext = NULL;
	Curr->ProcessListPrev = NULL;
	Curr->CurrentDll = NULL;

	//**placement***
	Curr->CounterOfSnapshots = CounterOfSnapshots;

	//**placement***
	strcpy(Curr->TimeOfSnapshot, strTime);

	//**placement***
	Curr->ProcessId = processID;

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

	HMODULE hMods[1024];  //* hMods - an array of all the dll of one process
	DWORD cbNeeded;
	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
	TCHAR Buffer2[MAX_PATH];  //* buffer2 - contains the full path (name) to the dll.

	//Get process name
	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
	{
		//**placement***
		// Convert wChar to regular char array (string)
		size_t numConverted;
		wcstombs_s(&numConverted, Curr->ProcessName, MAX_PATH, Buffer, MAX_PATH);
	}
	else
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
	}

	//Get memory info
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		//**placement***
		Curr->MemoryPageFaultCount = pmc.PageFaultCount;
		Curr->MemoryWorkingSetSize = pmc.PeakWorkingSetSize;
		Curr->MemoryQuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		Curr->MemoryQuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		Curr->MemoryPagefileUsage = pmc.PagefileUsage;
		sum_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize + Curr->MemoryWorkingSetSize; //*************For generata HTML****************
	}

	//Get Dlls List
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		//**placement***
		Curr->DllCount = 0;

		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{

			//Get dll name, general count, index
			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
			{
				//**placement***
				t_DllList* CurrentDll = (t_DllList*)malloc(sizeof(t_DllList));
				Curr->CurrentDll = CurrentDll;

				// Convert wChar to regular char array (string)
				//**placement***
				size_t numConverted;
				wcstombs_s(&numConverted, CurrentDll->dllName, MAX_PATH, Buffer2, MAX_PATH);

				Curr->DllCount++;


				//creat dlls linked list
				AddDllToLinkedlist(CurrentDll);
				CreatDictionary_DD_Generate_HTML_Report(CurrentDll->dllName, Curr->ProcessName);

			}
		}
		DllListHead = NULL;
		DllListTail = NULL;
	}

	//creat processes linked list
	AddProscessToLinkedlist(Curr);
	CloseHandle(hProcess);
}


void GetProcessesInfo()
{
	//Get Processes - Receive all process ID
	DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
	unsigned int i;

	//Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
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
		//* aProcesses[i] - the id of a singel process
	}

	Shaiker_Sort_ProcessDataByDllCount();
	t_HeadOfSnapshotsList* CurrentHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
	if (CurrentHead == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}
	CurrentHead->HeadOfSnapshot = ProcessListHead;
	CurrentHead->prosesCountOfEachHead = prosesCount; ///cProcesses- i dont use this, becuse it include the process that we are not allwo to get into.
	CurrentHead->sum_of_Dll = sum_of_Dll;//*************For generata HTML****************
	CurrentHead->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;//*************For generata HTML****************
	AddHeadToLinkedlist(CurrentHead);

	Search_HighestWorkingSetSize_In_One_p(CurrentHead);

	ProcessListHead = NULL;
	ProcessListTail = NULL;
	//**placement***
	prosesCount = 0;
	sum_of_MemoryWorkingSetSize = 0;//*************For generata HTML****************
}
//---------------------------------------------------snapshot-------------------------------------------------------------

#define gotoxy(y,x) printf("\033[%d;%dH", (y), (x))

//---------------------------------------20 snapshot--------------------------------------------
t_ProcessData* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryPagefileUsage)
{

	t_ProcessData* List = HeadListTail->HeadOfSnapshot;
	t_ProcessData* currkey = HeadListTail->HeadOfSnapshot;
	t_HeadOfSnapshotsList* CurrentHead1 = HeadListTail->HeadOfSnapshot;
	if (CurrentHead1 == NULL || List == NULL || currkey == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}


	while (List != NULL)
	{
		List = currkey;
		currkey = currkey->ProcessListNext;

		if ((!(strcmp(List->ProcessName, key))) && processID == List->ProcessId) { //if strcmp==0 it is eqwal
			List->MemoryPageFaultCount = List->MemoryPageFaultCount + MemoryPageFaultCount;
			List->MemoryWorkingSetSize = List->MemoryWorkingSetSize + MemoryWorkingSetSize;
			List->MemoryQuotaPagedPoolUsage = List->MemoryQuotaPagedPoolUsage + MemoryQuotaPagedPoolUsage;
			List->MemoryQuotaPeakPagedPoolUsage = List->MemoryQuotaPeakPagedPoolUsage + MemoryQuotaPeakPagedPoolUsage;
			List->MemoryPagefileUsage = List->MemoryPagefileUsage + MemoryPagefileUsage;
			sum_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize + List->MemoryWorkingSetSize; //*************For generata HTML****************

			return List;
		}
		else if (currkey == NULL) {

			GetMemoryAndDllInfo(processID, HeadListTail->HeadOfSnapshot->TimeOfSnapshot, HeadListTail->HeadOfSnapshot->CounterOfSnapshots);
			CurrentHead1->prosesCountOfEachHead = prosesCount;
			return NULL;
		}
	}

}

void searchDll(char keyDLL[MAX_PATH], t_ProcessData* currproses)
{

	t_DllList* currDllkey = currproses->CurrentDll;
	t_DllList* List = currproses->CurrentDll;
	if (currDllkey == NULL || List == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}
	

	while (List != NULL)
	{
		List = currDllkey;
		currDllkey = currDllkey->DllListPrev;


		if (!(strcmp(List->dllName, keyDLL))) {
			return;
		}
		else if (currDllkey == NULL) {

			t_DllList* NewDll = (t_DllList*)malloc(sizeof(t_DllList));
			//NewDll->dllName == keyDLL; // **************why this placement work??***************
			strcpy(NewDll->dllName, keyDLL);
			currproses->CurrentDll->DllListNext = NewDll;
			NewDll->DllListNext = NULL;
			NewDll->DllListPrev = currproses->CurrentDll;
			currproses->CurrentDll = NewDll;
			DllListTail = NewDll;
			currproses->DllCount++;
			return;
		}
	}

}

void GetProcessesInfo_WithoutNULL()
{
	//Get Processes - Receive all process ID
	DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
	unsigned int i;

	//Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
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
		//* aProcesses[i] - the id of a singel process
	}


	t_HeadOfSnapshotsList* CurrentHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
	if (CurrentHead == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}
	CurrentHead->HeadOfSnapshot = ProcessListHead;
	CurrentHead->prosesCountOfEachHead = prosesCount; ///cProcesses- i dont use this, becuse it include the process that we are not allwo to get into.
	CurrentHead->sum_of_Dll = sum_of_Dll;//*************For generata HTML****************
	CurrentHead->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;//*************For generata HTML****************
	AddHeadToLinkedlist(CurrentHead);



}

void GetMemoryAndDllInfo_20(DWORD processID)
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


	HMODULE hMods[1024];  //* hMods - an array of all the dll of one process
	DWORD cbNeeded;
	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
	TCHAR Buffer2[MAX_PATH];  //* buffer2 - contains the full path (name) to the dll.

	char keyProcess[MAX_PATH];
	char keyDLL[MAX_PATH];
	t_ProcessData* keyproses_For_Check_Dll = NULL;

	//Get process name
	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
	{

		//**placement***
		// Convert wChar to regular char array (string)
		size_t numConverted;
		wcstombs_s(&numConverted, keyProcess, MAX_PATH, Buffer, MAX_PATH);
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
		//**placement***
		keyproses_For_Check_Dll = SearchProcess(processID, keyProcess, pmc.PageFaultCount, pmc.PeakWorkingSetSize, pmc.QuotaPagedPoolUsage, pmc.QuotaPeakPagedPoolUsage, pmc.PagefileUsage);
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
				//**placement***
				size_t numConverted;
				wcstombs_s(&numConverted, keyDLL, MAX_PATH, Buffer2, MAX_PATH);

				CreatDictionary_DD_Generate_HTML_Report(keyDLL, keyProcess);

				if (keyproses_For_Check_Dll == NULL) { //whan we add a new proses to the list we dont need to check the dll list
					return;
				}
				else
				{
					searchDll(keyDLL, keyproses_For_Check_Dll);
				}
			}
		}
	}


	CloseHandle(hProcess);
}

void GetProcessesInfo_20()
{
	int counter_of_shots = 1;

	GetProcessesInfo_WithoutNULL();

	for (int i = 0; i < 20; i++)
	{
		gotoxy(5, 1);
		//printf("\033[5;1Hhello"); // Move to (8, 5) and output hello
		printf("The number of SnapShot taken: %d", counter_of_shots);
		counter_of_shots++;
		/*Sleep(1000);*/

		//Get Processes - Receive all process ID
		DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
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
			GetMemoryAndDllInfo_20(aProcesses[i]);
			//* aProcesses[i] - the id of a singel process
		}
	}
	Shaiker_Sort_ProcessDataByDllCount();
	HeadListTail->HeadOfSnapshot = ProcessListHead;

	Search_HighestWorkingSetSize_In_One_p(HeadListTail);

	HeadListTail->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;
	HeadListTail->sum_of_Dll = sum_of_Dll;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	DllListHead = NULL;  ///is alrady null but i dont take risk
	DllListTail = NULL;  ///is alrady null but i dont take risk

	//**placement***
	prosesCount = 0;
	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
}

//---------------------------------------20 snapshot---------------------------------------------



//---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------

void GetProcessesInfo_Long_SnapShot()
{
	int counter_of_shots = 1;

	GetProcessesInfo_WithoutNULL();
	int Stop = 1;
	

	while (Stop)
	{
		gotoxy(5,1);
		//printf("\033[5;1Hhello"); // Move to (8, 5) and output hello
		printf("The number of SnapShot taken: %d", counter_of_shots);
		counter_of_shots++;
		Sleep(1000);

		//Get Processes - Receive all process ID
		DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
		unsigned int i;

		//Receive all process ID and put in aProcesses Array
		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			return 1;
		}

		//Calculate how many process identifiers were returned.
		cProcesses = cbNeeded / sizeof(DWORD);

		//Loop of all processes - For each Process, get its Memory Information
		for (i = 0; i < cProcesses; i++)
		{
			GetMemoryAndDllInfo_20(aProcesses[i]);
			//* aProcesses[i] - the id of a singel process
		}


		if (kbhit()) // kbhit() return 1 if keyboard key was clicked else returns 0
		{
			char ch1 = getch();
			if (ch1 == 'E' || ch1 == 'e') {
				Stop = 0;
			}
		}
	}
	Shaiker_Sort_ProcessDataByDllCount();
	HeadListTail->HeadOfSnapshot = ProcessListHead;

	Search_HighestWorkingSetSize_In_One_p(HeadListTail);
	HeadListTail->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;
	HeadListTail->sum_of_Dll = sum_of_Dll;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	DllListHead = NULL;  ///is alrady null but i dont take risk
	DllListTail = NULL;  ///is alrady null but i dont take risk

	//**placement***
	prosesCount = 0;
	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
}

//---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------





//---------------------------------------reset collection functions---------------------------------------------

void ResetCollections() {

	prosesCount = 0;
	Head_Of_Snapshots_Head_List_Counter = 0;
	CounterOfSnapshots = 0;

	// it is alredy "0" , - double check
	sum_of_Dll = 0; //*************For generata HTML****************
	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************

	//reset all snapshots:
	t_HeadOfSnapshotsList* CurrFreeHead = HeadListHead;
	t_HeadOfSnapshotsList* FreeHead = NULL;

	// if there are no list 
	if (CurrFreeHead == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		// log error
		return;
	}

	//reset one snapshot:
	while (CurrFreeHead->HeadListNext != NULL) {

		t_ProcessData* CurrFreeProcess = CurrFreeHead->HeadOfSnapshot;
		t_ProcessData* FreeProcess = NULL;

		//reset one process
		while (CurrFreeProcess->ProcessListNext != NULL) {

			t_DllList* CurrFreeDll = CurrFreeProcess->CurrentDll;
			t_DllList* FreeDll = NULL;

			//reset dll list in one process:
			while (CurrFreeDll->DllListPrev != NULL) {
				//go to next dll:
				FreeDll = CurrFreeDll;
				CurrFreeDll = CurrFreeDll->DllListPrev;
				free(FreeDll);
			}
			//free last dll:
			FreeDll = CurrFreeDll;
			free(FreeDll);

			//go to next process:
			FreeProcess = CurrFreeProcess;
			CurrFreeProcess = CurrFreeProcess->ProcessListNext;
			free(FreeProcess);
		}
		//free last process:
		FreeProcess = CurrFreeProcess;
		free(FreeProcess);

		//go to next snapshot:
		FreeHead = CurrFreeHead;
		CurrFreeHead = CurrFreeHead->HeadListNext;
		free(FreeHead);
	}
	//free last head:
	FreeHead = CurrFreeHead;
	free(FreeHead);
	DllListHead = NULL;
	DllListTail = NULL;
	ProcessListHead = NULL;
	ProcessListTail = NULL;
	HeadListHead = NULL;
	HeadListTail = NULL;

	//clean the file and put reaset massega
	FILE* f = fopen("project.bin", "wb");
	if (f) {

		t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
		if (CurrentHead == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			return;
		}
		currHeader->version = 0;
		currHeader->Head_Of_Snapshots_Head_List_Counter = 0;
		strcpy(currHeader->Reserved, "the File was Reset");

		int write = fwrite(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
		if (write == NULL) {
			err = GetLastError();
			strE = strerror(err);
			Error_Log(strE);
			//error
		}
	}
	else
	{
		
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		//error
	}
	fclose(f);

	//clean the struct From Generate_HTML_Report 
	// 
	//reset one Dll From Generate_HTML_Report
	// 
	t_Dic_Dll* CurrFreeDic_Dll = DD_head;
	t_Dic_Dll* FreeDic_Dll = NULL;

	while (CurrFreeDic_Dll->DD_next != NULL) {

		t_Dic_Process* CurrFreeDic_Process = CurrFreeDic_Dll->Dic_currProcess;
		t_Dic_Process* FreeDic_Process = NULL;

		//reset Process list in one Dll:
		while (CurrFreeDic_Process->DP_next != NULL) {
			//go to next Process:
			FreeDic_Process = CurrFreeDic_Process;
			CurrFreeDic_Process = CurrFreeDic_Process->DP_next;
			free(FreeDic_Process);
		}
		//free last Process:
		FreeDic_Process = CurrFreeDic_Process;
		free(FreeDic_Process);

		//go to next Dll:
		FreeDic_Dll = CurrFreeDic_Dll;
		CurrFreeDic_Dll = CurrFreeDic_Dll->DD_next;
		free(FreeDic_Dll);
	}
	//free last Dll:
	FreeDic_Dll = CurrFreeDic_Dll;
	free(FreeDic_Dll);

	DD_head = NULL;
	DD_tail = NULL;
	DP_tail = NULL;
}

//---------------------------------------reset collection functions---------------------------------------------

