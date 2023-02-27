//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <conio.h>
//#include <windows.h>
//#include <psapi.h>
//#pragma warning (disable : 4996)
//
////take one snepshot structrs : -----------------------------------------------------------------------------------
//
//int CounterOfSnapshots = 0;
//
//struct HeaderOfFile {
//	int Version;
//	int CounterOfHeads;
//	char Extra[100];
//};
//
//int CounterOfHeads = 0;
//
//struct HeadOfSnapshotsList {
//	int CounterOfProcess;
//	unsigned long SumOfDll;
//	unsigned long AverageOfMemoryWorkingSet;
//	struct OneProcessInfo* HighestWorkingsetProcess;
//	struct OneProcessInfo* HeadOfSnapshot;
//	struct HeadOfSnapshotsList* HeadListNext;
//	struct HeadOfSnapshotsList* HeadListPrev;
//};
//
//int CounterOfProcess = 0;
//unsigned long SumOfDll = 0;
//unsigned long long SumOfMemoryWorkingSet = 0;
//struct HeadOfSnapshotsList* HeadListHead = NULL;
//struct HeadOfSnapshotsList* HeadListTail = NULL;
//struct HeadOfSnapshotsList* CurrentHead;
//struct HeadOfSnapshotsList* PrevItemHead;
//
//struct DllList {
//  //single dll info:
//	char dllName[MAX_PATH];
//  //dll linked list info:
//	struct DllList* DllListNext;
//	struct DllList* DllListPrev;
//};
//
//struct DllList* DllListHead = NULL;
//struct DllList* DllListTail = NULL;
//struct DllList* CurrentDll;
//struct DllList* PrevItemDll;
//
//struct OneProcessInfo {
//	int CounterOfDll;
//  //snapshot info:
//	int CounterOfSnapshots;
//	char TimeOfSnapshot[100];
//  //process info:
//	char ProcessName[MAX_PATH];
//	DWORD ProcessId;
//  //process memory use info:
//	DWORD MemoryPageFaultCount;
//	SIZE_T MemoryWorkingSetSize;
//	SIZE_T MemoryQuotaPeakPagedPoolUsage;
//	SIZE_T MemoryQuotaPagedPoolUsage;
//	SIZE_T MemoryPagefileUsage;
//  //dll list info:
//  //unsigned int DllCount;
//	struct DllList* CurrentDll;
//  //process linked list info:
//	struct OneProcessInfo* ProcessListNext;
//	struct OneProcessInfo* ProcessListPrev;
//};
//
//unsigned long long CounterOfDll = 0;
//struct OneProcessInfo* ProcessListHead = NULL;
//struct OneProcessInfo* ProcessListTail = NULL;
//struct OneProcessInfo* Current;
//struct OneProcessInfo* PrevItem;
//
//
//
////***generait HTML functions : -----------------------------------------------------------------------------------
//
//
////DLL list: ---------------------------------------------------------------------------------------------------
//
//struct Dic_Dll {
//	char Dic_dllName[MAX_PATH];
//	int Dic_counterOfProcess;
//	struct Dic_Process* Dic_currProcess;
//	struct Dic_Process* Dic_previtemProcess;
//	struct Dic_Dll* DD_prev;
//	struct Dic_Dll* DD_next;
//};
//
//struct Dic_Dll* DD_head = NULL;
//struct Dic_Dll* DD_tail = NULL;
//struct Dic_Dll* DD_prevItem;
//
//struct Dic_Process {
//	char Dic_ProcessName[MAX_PATH];
//	struct Dic_Process* DP_prev;
//	struct Dic_Process* DP_next;
//};
//
//struct Dic_Process* DP_tail = NULL;
//
//void AddDllToLinkedlist_Dictionary(struct Dic_Dll* DD_current)
//{
//	
//
//	if (DD_head == NULL) {
//		DD_head = DD_current;
//		DD_tail = DD_head;
//		DD_current->DD_next = NULL;
//		DD_current->DD_prev = NULL;
//		DD_prevItem = DD_current;
//		
//	}
//	else
//	{
//		DD_tail = DD_current;
//		DD_tail->DD_prev = DD_prevItem;
//		DD_tail->DD_next = NULL;
//		DD_prevItem->DD_next = DD_tail;
//		DD_prevItem = DD_current;
//	}
//
//	DD_current->Dic_counterOfProcess = 0;
//	SumOfDll++;
//}
//
//struct Dic_Process* AddProcessToLinkedlist_Dictionary(struct Dic_Process* DP_current, struct Dic_process* DP_head, struct Dic_Process* DP_prevItem)
//{
//
//	if (DP_head == NULL) {
//		DP_head = DP_current;
//		DP_tail = DP_head;
//		DP_current->DP_next = NULL;
//		DP_current->DP_prev = NULL;
//		DP_prevItem = DP_current;
//	}
//	else
//	{
//		DP_tail = DP_current;
//		DP_tail->DP_prev = DP_prevItem;
//		DP_tail->DP_next = NULL;
//		DP_prevItem->DP_next = DP_tail;
//		DP_prevItem = DP_current;
//	}
//
//	//Dic_counterOfProcess++;
//	return DP_prevItem;
//}
//
//void CreatDictionary_DP(struct Dic_Dll* DD_NewDll, char Dic_ProcessName[MAX_PATH]) {
//
//
//	struct Dic_Process* Dic_CurrentProcessKey = DD_NewDll->Dic_currProcess;
//
//	while (Dic_CurrentProcessKey != NULL) {
//		if (!(strcmp(Dic_CurrentProcessKey->Dic_ProcessName, Dic_ProcessName))) {
//			return;
//		}
//		else {
//			Dic_CurrentProcessKey = Dic_CurrentProcessKey->DP_next;
//		}
//	}
//
//	struct Dic_Process* DP_NewProcess = (struct Dic_Process*)malloc(sizeof(struct Dic_Process));
//	strcpy(DP_NewProcess->Dic_ProcessName, Dic_ProcessName);
//	DD_NewDll->Dic_previtemProcess = AddProcessToLinkedlist_Dictionary(DP_NewProcess, DD_NewDll->Dic_currProcess, DD_NewDll->Dic_previtemProcess);
//	DD_NewDll->Dic_counterOfProcess++;
//}
//
//void CreatDictionary_DD(char Dic_dllName[MAX_PATH], char Dic_ProcessName[MAX_PATH]) {
//
//	struct Dic_Dll* Dic_CurrentDllKey = DD_head;
//
//	while (Dic_CurrentDllKey != NULL) {
//		if (!(strcmp(Dic_CurrentDllKey->Dic_dllName, Dic_dllName))) {
//			CreatDictionary_DP(Dic_CurrentDllKey, Dic_ProcessName);
//			return;
//		}
//		else {
//			Dic_CurrentDllKey = Dic_CurrentDllKey->DD_next;
//		}
//	}
//
//	struct Dic_Dll* DD_NewDll = (struct Dic_Dll*)malloc(sizeof(struct Dic_Dll));
//	strcpy(DD_NewDll->Dic_dllName, Dic_dllName);
//	AddDllToLinkedlist_Dictionary(DD_NewDll);
//	DD_NewDll->Dic_currProcess = NULL;
//	DD_NewDll->Dic_previtemProcess = NULL;
//	
//
//	struct Dic_Process* DP_NewProcess = (struct Dic_Process*)malloc(sizeof(struct Dic_Process));
//	strcpy(DP_NewProcess->Dic_ProcessName, Dic_ProcessName);
//	DD_NewDll->Dic_previtemProcess = AddProcessToLinkedlist_Dictionary(DP_NewProcess, DD_NewDll->Dic_currProcess, DD_NewDll->Dic_previtemProcess);
//	DD_NewDll->Dic_counterOfProcess++;
//	DD_NewDll->Dic_currProcess = DP_NewProcess;
//}
//
////sorted snapshot: -----------------------------------------------------------------------------------------------
//
//void Replace(struct OneProcessInfo* item)
//{
//	if (item == NULL) {
//		//EventLogval("No need to swap", 0);
//		return;
//	}
//
//	struct OneProcessInfo CopyList;
//	struct OneProcessInfo* NextItem;
//	struct OneProcessInfo* List;
//
//	List = item;
//	CopyList.ProcessListNext = item->ProcessListNext;
//	CopyList.ProcessListPrev = item->ProcessListPrev;
//	NextItem = item->ProcessListNext;
//	
//	if (item == ProcessListHead) {
//		List->ProcessListPrev = NextItem;
//		List->ProcessListNext = NextItem->ProcessListNext;
//		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
//		NextItem->ProcessListNext = List;
//		List->ProcessListNext->ProcessListPrev = List;
//		ProcessListHead = NextItem;
//	}
//	else if (item == ProcessListTail->ProcessListPrev)
//	{
//		List->ProcessListPrev = NextItem;
//		List->ProcessListNext = NextItem->ProcessListNext;
//		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
//		NextItem->ProcessListNext = List;
//		NextItem->ProcessListPrev->ProcessListNext = NextItem;
//		if (ProcessListTail == NextItem) {
//			ProcessListTail = List;
//		}
//	}
//	else
//	{
//		List->ProcessListPrev = NextItem;
//		List->ProcessListNext = NextItem->ProcessListNext;
//		NextItem->ProcessListPrev = CopyList.ProcessListPrev;
//		NextItem->ProcessListNext = List;
//		NextItem->ProcessListPrev->ProcessListNext = NextItem;
//		List->ProcessListNext->ProcessListPrev = List;
//	}
//}
//
//void snapshot_Shaiker_BubleSort()
//{
//
//	int Bublecounter = 1;
//
//	struct OneProcessInfo* curr = ProcessListHead;
//	struct OneProcessInfo* CheckItem = ProcessListHead->ProcessListNext;
//	struct OneProcessInfo* CopyHead = NULL;
//	struct OneProcessInfo* CopyTail = NULL;
//
//	if (curr == NULL) {
//		//EventLog("the list is empty");
//		return;
//	}
//
//	//EventLog("Start sorting");
//	/*while (Bublecounter != 0)
//	{*/
//		//curr = ProcessListHead;
//		//CheckItem = ProcessListHead->ProcessListNext;
//
//		while (Bublecounter != 0)
//		{
//			Bublecounter = 0;
//
//			while (CheckItem != NULL && curr->ProcessListNext != CopyTail)
//			{
//				if (curr->CounterOfDll < CheckItem->CounterOfDll) {
//					Replace(curr);
//					CheckItem = curr->ProcessListNext;
//					Bublecounter++;
//				}
//				else
//				{
//					curr = curr->ProcessListNext;
//					CheckItem = CheckItem->ProcessListNext;
//				}
//			}
//			CopyTail = curr;
//			curr = curr->ProcessListPrev;
//			CheckItem = curr->ProcessListPrev;
//
//
//			while (CheckItem != NULL && curr->ProcessListPrev != CopyHead)
//			{
//				if (curr->CounterOfDll > CheckItem->CounterOfDll) {
//					Replace(CheckItem);
//					CheckItem = curr->ProcessListPrev;
//					Bublecounter++;
//				}
//				else
//				{
//					curr = curr->ProcessListPrev;
//					CheckItem = CheckItem->ProcessListPrev;
//				}
//			}
//			CopyHead = curr;
//			curr = curr->ProcessListNext;
//			CheckItem = curr->ProcessListNext;
//
//		}
//	//}
//	//EventLog("End sorting");
//}
//
////highest workingset icon: ---------------------------------------------------------------------------------------
//
//void SearchHighestWorkingsetProcess(struct HeadOfSnapshotsList* headOfSnapshot) {
//
//	struct OneProcessInfo* HolderOfHigestWSS = headOfSnapshot->HeadOfSnapshot;
//	struct OneProcessInfo* CurrentKey = headOfSnapshot->HeadOfSnapshot->ProcessListNext;
//
//	while (CurrentKey != NULL) {
//		if (HolderOfHigestWSS->MemoryWorkingSetSize >= CurrentKey->MemoryWorkingSetSize) {
//
//			CurrentKey = CurrentKey->ProcessListNext;
//		}
//		else {
//
//			//*******placement******
//			HolderOfHigestWSS = CurrentKey;
//			CurrentKey = CurrentKey->ProcessListNext;
//		}
//	}
//
//	headOfSnapshot->HighestWorkingsetProcess = HolderOfHigestWSS;
//
//	return;
//}
//
//
//
//
//
//
////***take one snepshot functions : --------------------------------------------------------------------------------
//
////5----------------------------------------------------------------------------------------------------------------
//
//void AddHeadToLinkedlist(struct HeadOfSnapshotsList* CurrentHead)
//{
//
//	if (HeadListHead == NULL) {
//		HeadListHead = CurrentHead;
//		HeadListTail = HeadListHead;
//		CurrentHead->HeadListNext = NULL;
//		CurrentHead->HeadListPrev = NULL;
//		PrevItemHead = CurrentHead;
//	}
//	else
//	{
//		HeadListTail = CurrentHead;
//		HeadListTail->HeadListPrev = PrevItemHead;
//		HeadListTail->HeadListNext = NULL;
//		PrevItemHead->HeadListNext = HeadListTail;
//		PrevItemHead = CurrentHead;
//	}
//
//	CounterOfHeads++;
//}
//
////4----------------------------------------------------------------------------------------------------------------
//
//void AddProscessToLinkedlist(struct OneProcessInfo* Current)
//{
//	if (!strstr(Current->ProcessName, "exe")) {
//		return;
//	}
//
//	if (ProcessListHead == NULL) {
//		ProcessListHead = Current;
//		ProcessListTail = ProcessListHead;
//		Current->ProcessListNext = NULL;
//		Current->ProcessListPrev = NULL;
//		PrevItem = Current;
//	}
//	else
//	{
//		ProcessListTail = Current;
//		ProcessListTail->ProcessListPrev = PrevItem;
//		ProcessListTail->ProcessListNext = NULL;
//		PrevItem->ProcessListNext = ProcessListTail;
//		PrevItem = Current;
//	}
//
//	CounterOfProcess++;
//}
//
////3----------------------------------------------------------------------------------------------------------------
//
//void AddDllToLinkedlist(struct DllList* CurrentDll)
//{
//
//	if (DllListHead == NULL) {
//		DllListHead = CurrentDll;
//		DllListTail = DllListHead;
//		CurrentDll->DllListNext = NULL;
//		CurrentDll->DllListPrev = NULL;
//		PrevItemDll = CurrentDll;
//	}
//	else
//	{
//		DllListTail = CurrentDll;
//		DllListTail->DllListPrev = PrevItemDll;
//		DllListTail->DllListNext = NULL;
//		PrevItemDll->DllListNext = DllListTail;
//		PrevItemDll = CurrentDll;
//	}
//
//	CounterOfDll++;
//}
//
////2----------------------------------------------------------------------------------------------------------------
//
//void GetMemoryAndDllInfo(DWORD processID, char strTime [100], int CounterOfSnapshots)
//{
//  //*******placement******
//	struct OneProcessInfo* Current = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
//
//  //*******placement******
//	Current->CounterOfSnapshots = CounterOfSnapshots;
//
//  //*******placement******
//	strcpy(Current->TimeOfSnapshot, strTime);
//
//  //*******placement******
//	Current->ProcessId = processID;
//	
//	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
//	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info
//
//  //like doing "fopen" of a process by using the id and pointer
//	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |	PROCESS_VM_READ, FALSE, processID);
//	 
//	if (NULL == hProcess)
//		//error. write to log
//		return;
//
//	HMODULE hMods[1024];  //*** hMods - an array of all the dll of one process
//	DWORD cbNeeded;
//	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
//	TCHAR Buffer2[MAX_PATH];  //*** buffer2 - contains the full path (name) to the dll.
//
//	//Get process name
//	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
//	{
//		
//      //*******placement******
//	  // Convert wChar to regular char array (string)
//		size_t numConverted;
//		wcstombs_s(&numConverted, Current->ProcessName, MAX_PATH, Buffer, MAX_PATH);
//	}
//	else
//	{
//	  //error. write to log
//	}
//
//	//Get memory info
//	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
//	{
//	  //*******placement******
//		Current->MemoryPageFaultCount = pmc.PageFaultCount;
//		Current->MemoryWorkingSetSize = pmc.PeakWorkingSetSize;
//		Current->MemoryQuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
//		Current->MemoryQuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
//		Current->MemoryPagefileUsage = pmc.PagefileUsage;
//		SumOfMemoryWorkingSet = SumOfMemoryWorkingSet + Current->MemoryWorkingSetSize;
//	}
//
//	//Get Dlls List
//	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
//	{		
//
//		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
//		{
//
//			//Get dll name, general count, index
//			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
//			{
//				//*******placement******
//				struct DllList* CurrentDll = (struct DllList*)malloc(sizeof(struct DllList));
//				Current->CurrentDll = CurrentDll;
//
//				// Convert wChar to regular char array (string)
//				//*******placement******
//				size_t numConverted;
//				wcstombs_s(&numConverted, CurrentDll->dllName, MAX_PATH, Buffer2, MAX_PATH);
//
//			   //creat dlls linked list
//				AddDllToLinkedlist(CurrentDll);
//
//				CreatDictionary_DD(CurrentDll->dllName, Current->ProcessName);
//			}
//		}
//
//		DllListHead = NULL;
//		DllListTail = NULL;
//		Current->CounterOfDll = CounterOfDll;
//		//SumOfDll = SumOfDll + CounterOfDll;
//		CounterOfDll = 0;
//	}
//
//  //creat processes linked list
//	AddProscessToLinkedlist(Current);
//
//	CloseHandle(hProcess);
//}
//
////1----------------------------------------------------------------------------------------------------------------
//
//void GetProcessesInfo()
//{
//	
//  //Get Processes - Receive all process ID
//	DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
//	unsigned int i;
//
//  //Receive all process ID and put in aProcesses Array
//	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//	{
//	  //Error. Write to log
//	  return 1;
//	}
//
//  //Calculate how many process identifiers were returned.
//	cProcesses = cbNeeded / sizeof(DWORD);
//
//  //saves the time for each snapshot
//	time_t t;
//	time(&t);
//	struct tm* timeinfo;
//	timeinfo = localtime(&t);
//	char strTime[100];
//	sprintf(strTime, "%d.%d.%d-%d:%d:%d ", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//
//  //saves the number of snapshots taken
//	CounterOfSnapshots++;
//	
//   //Loop of all processes - For each Process, get its Memory Information
//	for (i = 0; i < cProcesses; i++)
//	{
//         GetMemoryAndDllInfo(aProcesses[i], strTime, CounterOfSnapshots);
//		//*** aProcesses[i] - the id of a singel process
//	}
//
//	snapshot_Shaiker_BubleSort();
//	
//	struct HeadOfSnapshotsList* CurrentHead = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
//	CurrentHead->HeadOfSnapshot = ProcessListHead;
//	CurrentHead->CounterOfProcess = CounterOfProcess;
//	CurrentHead->SumOfDll = SumOfDll;
//	CurrentHead->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
//	AddHeadToLinkedlist(CurrentHead);
//
//	SearchHighestWorkingsetProcess(CurrentHead);
//	
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	CounterOfProcess = 0;
//	//SumOfDll = 0;
//	SumOfMemoryWorkingSet = 0;
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
////***take 20 snepshots functions : -----------------------------------------------------------------------------------
//
////5----------------------------------------------------------------------------------------------------------------
//
//void SearchDll(char KeyDll[MAX_PATH], struct OneProcessInfo* KeyAdress) {
//
//	struct DllList* CurrentDllKey = KeyAdress->CurrentDll;
//
//	while (CurrentDllKey != NULL) {
//		if (!(strcmp(CurrentDllKey->dllName,KeyDll))) {
//			return;
//		}
//		else {
//			CurrentDllKey = CurrentDllKey->DllListPrev;
//		}
//	}
//
//	struct DllList* NewDll = (struct DllList*)malloc(sizeof(struct DllList));
//	strcpy(NewDll->dllName, KeyDll);
//	KeyAdress->CurrentDll->DllListNext = NewDll;
//	NewDll->DllListPrev = KeyAdress->CurrentDll;
//	NewDll->DllListNext = NULL;
//	KeyAdress->CurrentDll = NewDll;
//	CounterOfDll++;
//	//SumOfDll++;
//	KeyAdress->CounterOfDll = CounterOfDll;
//	
//}
//
////4----------------------------------------------------------------------------------------------------------------
//
//struct OneProcessInfo* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryPagefileUsage) {
//
//	struct OneProcessInfo* CurrentKey = HeadListTail->HeadOfSnapshot;
//	CurrentHead = HeadListTail;
//
//	while (CurrentKey != NULL) {
//		if ((!(strcmp(CurrentKey->ProcessName, key))) && processID == CurrentKey->ProcessId) {
//			
//			//*******placement******
//			CurrentKey->MemoryPageFaultCount = CurrentKey->MemoryPageFaultCount + MemoryPageFaultCount;
//			CurrentKey->MemoryWorkingSetSize = CurrentKey->MemoryWorkingSetSize + MemoryWorkingSetSize;
//			CurrentKey->MemoryQuotaPeakPagedPoolUsage = CurrentKey->MemoryQuotaPeakPagedPoolUsage + MemoryQuotaPeakPagedPoolUsage;
//			CurrentKey->MemoryQuotaPagedPoolUsage = CurrentKey->MemoryQuotaPagedPoolUsage + MemoryQuotaPagedPoolUsage;
//			CurrentKey->MemoryPagefileUsage = CurrentKey->MemoryPagefileUsage + MemoryPagefileUsage;
//			SumOfMemoryWorkingSet = SumOfMemoryWorkingSet + CurrentKey->MemoryWorkingSetSize;
//			return CurrentKey;
//		}
//		else {
//			CurrentKey = CurrentKey->ProcessListNext;
//		}
//	}
//
//	GetMemoryAndDllInfo(processID, HeadListTail->HeadOfSnapshot->TimeOfSnapshot, HeadListTail->HeadOfSnapshot->CounterOfSnapshots);
//	CurrentHead->CounterOfProcess = CounterOfProcess;
//	return NULL;
//}
//
////3----------------------------------------------------------------------------------------------------------------
//
//void GetMemoryAndDllInfo_20version(DWORD processID)
//{
//	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
//	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info
//
//  //like doing "fopen" of a process by using the id and pointer
//	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
//
//	if (NULL == hProcess)
//		//error. write to log
//		return;
//
//	HMODULE hMods[1024];  //*** hMods - an array of all the dll of one process
//	DWORD cbNeeded;
//	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
//	TCHAR Buffer2[MAX_PATH];  //*** buffer2 - contains the full path (name) to the dll.
//	char KeyProcess[MAX_PATH];
//	char KeyDll[MAX_PATH];
//	struct OneProcessInfo* KeyAdress = NULL;
//
//	//Get process name
//	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
//	{
//
//		//*******placement******
//		// Convert wChar to regular char array (string)
//		size_t numConverted;
//		wcstombs_s(&numConverted, KeyProcess, MAX_PATH, Buffer, MAX_PATH);
//	}
//	else
//	{
//		//error. write to log
//	}
//
//	//Get memory info
//	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
//	{
//		//*******placement******
//		KeyAdress = SearchProcess(processID, KeyProcess, pmc.PageFaultCount, pmc.PeakWorkingSetSize, pmc.QuotaPagedPoolUsage, pmc.QuotaPeakPagedPoolUsage, pmc.PagefileUsage);
//	}
//
//	//Get Dlls List
//	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
//	{
//
//		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
//		{
//
//			//Get dll name, general count, index
//			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
//			{
//				// Convert wChar to regular char array (string)
//				//*******placement******
//				size_t numConverted;
//				wcstombs_s(&numConverted, KeyDll, MAX_PATH, Buffer2, MAX_PATH);
//
//				if (KeyAdress == NULL) {
//					return;
//				}
//
//				SearchDll(KeyDll, KeyAdress);
//
//				CreatDictionary_DD(KeyDll, KeyProcess);
//			}
//		}
//	}
//	CloseHandle(hProcess);
//}
//
////2----------------------------------------------------------------------------------------------------------------
//
//void GetProcessesInfo_noNull()
//{
//
//	//Get Processes - Receive all process ID
//	DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
//	unsigned int i;
//
//	//Receive all process ID and put in aProcesses Array
//	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//	{
//		//Error. Write to log
//		return 1;
//	}
//
//	//Calculate how many process identifiers were returned.
//	cProcesses = cbNeeded / sizeof(DWORD);
//
//	//saves the time for each snapshot
//	time_t t;
//	time(&t);
//	struct tm* timeinfo;
//	timeinfo = localtime(&t);
//	char strTime[100];
//	sprintf(strTime, "%d.%d.%d-%d:%d:%d ", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//
//	//saves the number of snapshots taken
//	CounterOfSnapshots++;
//
//	//Loop of all processes - For each Process, get its Memory Information
//	for (i = 0; i < cProcesses; i++)
//	{
//		GetMemoryAndDllInfo(aProcesses[i], strTime, CounterOfSnapshots);
//		//*** aProcesses[i] - the id of a singel process
//	}
//
//	struct HeadOfSnapshotsList* CurrentHead = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
//	CurrentHead->HeadOfSnapshot = ProcessListHead;
//	CurrentHead->CounterOfProcess = CounterOfProcess;
//	CurrentHead->SumOfDll = SumOfDll;
//	CurrentHead->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
//	AddHeadToLinkedlist(CurrentHead);
//}
//
////1----------------------------------------------------------------------------------------------------------------
//
//void GetProcessesInfo_20version()
//{
//
//	GetProcessesInfo_noNull();
//
//	for (int i = 0; i < 3; i++) {
//
//		Sleep(1000);
//
//		//Get Processes - Receive all process ID
//		DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
//		unsigned int i;
//
//		//Receive all process ID and put in aProcesses Array
//		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//		{
//			//Error. Write to log
//			return 1;
//		}
//
//		//Calculate how many process identifiers were returned.
//		cProcesses = cbNeeded / sizeof(DWORD);
//
//		//Loop of all processes - For each Process, get its Memory Information
//		for (i = 0; i < cProcesses; i++)
//		{
//			GetMemoryAndDllInfo_20version(aProcesses[i]);
//			//*** aProcesses[i] - the id of a singel process
//		}
//	}
//
//	snapshot_Shaiker_BubleSort();
//
//	HeadListTail->HeadOfSnapshot = ProcessListHead;
//	HeadListTail->SumOfDll = SumOfDll;
//	HeadListTail->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
//	
//	SearchHighestWorkingsetProcess(HeadListTail);
//	
//	//SumOfDll = 0;
//	SumOfMemoryWorkingSet = 0;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	CounterOfProcess = 0;
//	//doubel check:
//	DllListHead = NULL;
//	DllListTail = NULL;
//	
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
////***take long snepshots functions : -----------------------------------------------------------------------------------
//
//void GetProcessesInfo_UserVersion()
//{
//
//	GetProcessesInfo_noNull();
//
//	int Stop = 1;
//
//	while (Stop) 
//	{
//
//		Sleep(1000);
//
//		//Get Processes - Receive all process ID
//		DWORD aProcesses[1024], cbNeeded, cProcesses;  //** aProcesses - array of id, ** cProcesses - how many id we have 
//		unsigned int i;
//
//		//Receive all process ID and put in aProcesses Array
//		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//		{
//			//Error. Write to log
//			return 1;
//		}
//
//		//Calculate how many process identifiers were returned.
//		cProcesses = cbNeeded / sizeof(DWORD);
//
//		//Loop of all processes - For each Process, get its Memory Information
//		for (i = 0; i < cProcesses; i++)
//		{
//			GetMemoryAndDllInfo_20version(aProcesses[i]);
//			//*** aProcesses[i] - the id of a singel process
//		}
//	  
//		if (kbhit())
//		{
//			char ch1 = getch();
//			if (ch1 == 'E')
//				Stop = 0;
//		}
//	}
//
//	snapshot_Shaiker_BubleSort();
//	HeadListTail->HeadOfSnapshot = ProcessListHead;
//	HeadListTail->SumOfDll = SumOfDll;
//	HeadListTail->AverageOfMemoryWorkingSet = SumOfMemoryWorkingSet / CounterOfProcess;
//
//	SearchHighestWorkingsetProcess(HeadListTail); 
//
//	//SumOfDll = 0;
//	SumOfMemoryWorkingSet = 0;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	CounterOfProcess = 0;
//	//doubel check:
//	DllListHead = NULL;
//	DllListTail = NULL;
//
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
////***reset collection functions : -----------------------------------------------------------------------------------
//
//void ResetCollections() {
//
//	//reset all snapshots:
//	struct HeadOfSnapshotsList* CurrentFreeHead = HeadListHead;
//	struct HeadOfSnapshotsList* FreeHead = NULL;
//
//
//	//if there are no lists to reset:
//	if (CurrentFreeHead == NULL) {
//		//log error.
//		printf("there are no snapshots to reset");
//		return;
//	}
//
//	//reset one snapshot:
//	while (CurrentFreeHead->HeadListNext != NULL) {
//
//		struct OneProcessInfo* CurrentFreeProcess = CurrentFreeHead->HeadOfSnapshot;
//		struct OneProcessInfo* FreeProcess = NULL;
//
//		//reset one process:
//		while (CurrentFreeProcess->ProcessListNext != NULL) {
//
//			struct DllList* CurrentFreeDll = CurrentFreeProcess->CurrentDll;
//			struct DllList* FreeDll = NULL;
//
//			//reset dll list in one process:
//			while (CurrentFreeDll->DllListPrev != NULL) {
//				//go to next dll:
//				FreeDll = CurrentFreeDll;
//				CurrentFreeDll = CurrentFreeDll->DllListPrev;
//				free(FreeDll);
//			}
//			//free last dll:
//			FreeDll = CurrentFreeDll;
//			free(FreeDll);
//
//			//go to next process:
//			FreeProcess = CurrentFreeProcess;
//			CurrentFreeProcess = CurrentFreeProcess->ProcessListNext;
//			free(FreeProcess);
//		}
//		//free last process:
//		FreeProcess = CurrentFreeProcess;
//		free(FreeProcess);
//
//		//go to next snapshot:
//		FreeHead = CurrentFreeHead;
//		CurrentFreeHead = CurrentFreeHead->HeadListNext;
//		free(FreeHead);
//	}
//	//free last head:
//	FreeHead = CurrentFreeHead;
//	free(FreeHead);
//
//	HeadListHead = NULL;
//	HeadListTail = NULL;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	DllListHead = NULL;
//	DllListTail = NULL;
//	CounterOfHeads = 0;
//	CounterOfProcess = 0;
//	CounterOfDll = 0;
//	CounterOfSnapshots = 0;
//	SumOfDll = 0;
//	SumOfMemoryWorkingSet = 0;
//
//	//-----------------------------------------------------
//
//	struct Dic_Dll* CurrentFreeDD = DD_head;
//	struct Dic_Dll* FreeDD = NULL;
//	
//	while (CurrentFreeDD->DD_next != NULL) {
//
//		struct Dic_Process* CurrentFreeDP = CurrentFreeDD->Dic_currProcess;
//		struct Dic_Process* FreeDP = NULL;
//
//		//DICTIONARY - reset process list in one DLL:
//		while (CurrentFreeDP->DP_next != NULL) {
//			//go to next process:
//			FreeDP = CurrentFreeDP;
//			CurrentFreeDP = CurrentFreeDP->DP_next;
//			free(FreeDP);
//		}
//		//free last process:
//		FreeDP = CurrentFreeDP;
//		free(FreeDP);
//
//		//DICTIONARY - go to next DLL:
//		FreeDD = CurrentFreeDD;
//		CurrentFreeDD = CurrentFreeDD->DD_next;
//		free(FreeDD);
//	}
//
//	//free last DLL:
//	FreeDD = CurrentFreeDD;
//	free(FreeDD);
//
//	DD_head = NULL;
//	DD_tail = NULL;
//	DP_tail = NULL;
//
//	//-----------------------------------------------------
//	 
//	
//	//clean the file:
//	FILE* f1 = fopen("projectAfile.bin", "wb");
//	if (f1) {
//		struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
//		HeaderOfSnapshots->CounterOfHeads = 0;
//		HeaderOfSnapshots->Version = 0;
//		strcpy(HeaderOfSnapshots->Extra, "reset function was used");
//
//		int write = fwrite(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
//		if (write == NULL) {
//			//error
//		}
//	}
//	else{
//		//log error
//	}
//	fclose(f1);
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
////***save in to file functions : -----------------------------------------------------------------------------------
//
//void SaveSnapshotsToFile()
//{
//	FILE* f1 = fopen("projectAfile.bin", "wb");
//	if (f1) {
//	struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
//	HeaderOfSnapshots->CounterOfHeads = CounterOfHeads;
//	HeaderOfSnapshots->Version = 1;
//	
//	int write = fwrite(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
//	if (write == NULL) {
//		//error
//	}
//	fclose(f1);
//	}
//	else {
//		//log error
//	}
//	
//
//	struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
//	HeaderOfSnapshots->CounterOfHeads = CounterOfHeads;
//	HeaderOfSnapshots->Version = 1;
//
//	struct HeadOfSnapshotsList* CurrH = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
//	struct OneProcessInfo* CurrP = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
//	struct DllList* CurrD = (struct DllList*)malloc(sizeof(struct DllList));
//
//	f1 = fopen("projectAfile.bin", "ab");
//	if (f1) {
//
//		CurrH = HeadListHead;
//
//		for (int i = 0; i < HeaderOfSnapshots->CounterOfHeads; i++)
//		{
//			int write = fwrite(CurrH, sizeof(struct HeadOfSnapshotsList), 1, f1);
//			if (!write) {
//				//error
//			}
//
//			CurrP = CurrH->HeadOfSnapshot;
//
//			for (int i = 0; i < CurrH->CounterOfProcess; i++)
//			{
//				write = fwrite(CurrP, sizeof(struct OneProcessInfo), 1, f1);
//				if (!write) {
//					//error
//				}
//
//				CurrD = CurrP->CurrentDll;
//
//				for (int i = 0; i < CurrP->CounterOfDll; i++)
//				{
//					write = fwrite(CurrD, sizeof(struct DllList), 1, f1);
//					if (!write) {
//						//error
//					}
//
//					CurrD = CurrD->DllListPrev;
//				}
//
//				CurrP = CurrP->ProcessListNext;
//			}
//
//			CurrH = CurrH->HeadListNext;
//		}
//
//		fclose(f1);
//		free(HeaderOfSnapshots);
//		free(CurrH);
//		free(CurrP);
//		free(CurrD);
//	}
//	else
//	{
//		//error
//	}
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
////***load from file functions : -----------------------------------------------------------------------------------
//
//void LoadSnapshotsFromFile(char FileName[100])
//{
//	struct HeaderOfFile* HeaderOfSnapshots = (struct HeaderOfFile*)malloc(sizeof(struct HeaderOfFile));
//	struct HeadOfSnapshotsList* CurrH = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
//	struct OneProcessInfo* CurrP = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
//	struct DllList* CurrD = (struct DllList*)malloc(sizeof(struct DllList));
//	//CounterOfSnapshots = 0;
//	CounterOfHeads = 0;
//	CounterOfProcess = 0;
//	CounterOfDll = 0;
//	SumOfDll = 0;
//	SumOfMemoryWorkingSet = 0;
//	HeadListHead = NULL;
//	HeadListTail = NULL;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	DllListHead = NULL;
//	DllListTail = NULL;
//
//	FILE* f1 = fopen(FileName, "rb");
//	if (f1) {
//		int read = fread(HeaderOfSnapshots, sizeof(struct HeaderOfFile), 1, f1);
//		if (read == NULL) {
//			//error
//		}
//
//		for (int i = 0; i < HeaderOfSnapshots->CounterOfHeads; i++)
//		{
//			read = fread(CurrH, sizeof(struct HeadOfSnapshotsList), 1, f1);
//			if (!read) {
//				//error
//			}
//			struct HeadOfSnapshotsList* CurrH1 = (struct HeadOfSnapshotsList*)malloc(sizeof(struct HeadOfSnapshotsList));
//			CurrH1->HeadOfSnapshot = CurrH->HeadOfSnapshot;
//			CurrH1->SumOfDll = CurrH->SumOfDll;
//			CurrH1->AverageOfMemoryWorkingSet = CurrH->AverageOfMemoryWorkingSet;
//			
//			AddHeadToLinkedlist(CurrH1);
//			CurrP = CurrH->HeadOfSnapshot;
//
//			for (int i = 0; i < CurrH->CounterOfProcess; i++)
//			{
//				read = fread(CurrP, sizeof(struct OneProcessInfo), 1, f1);
//				if (!read) {
//					//error
//				}
//				struct OneProcessInfo* CurrP1 = (struct OneProcessInfo*)malloc(sizeof(struct OneProcessInfo));
//				CurrP1->CounterOfSnapshots = CurrP->CounterOfSnapshots;
//				CurrP1->CurrentDll = CurrP->CurrentDll;
//				CurrP1->MemoryPageFaultCount = CurrP->MemoryPageFaultCount;
//				CurrP1->MemoryPagefileUsage = CurrP->MemoryPagefileUsage;
//				CurrP1->MemoryQuotaPagedPoolUsage = CurrP->MemoryQuotaPagedPoolUsage;
//				CurrP1->MemoryQuotaPeakPagedPoolUsage = CurrP->MemoryQuotaPeakPagedPoolUsage;
//				CurrP1->MemoryWorkingSetSize = CurrP->MemoryWorkingSetSize;
//				CurrP1->ProcessId = CurrP->ProcessId;
//				strcpy(CurrP1->ProcessName, CurrP->ProcessName);
//				strcpy(CurrP1->TimeOfSnapshot, CurrP->TimeOfSnapshot);
//
//				AddProscessToLinkedlist(CurrP1);
//				CurrD = CurrP->CurrentDll;
//
//				for (int i = 0; i < CurrP->CounterOfDll; i++)
//				{
//					read = fread(CurrD, sizeof(struct DllList), 1, f1);
//					if (!read) {
//						//error
//					}
//
//					struct DllList* CurrD1 = (struct DllList*)malloc(sizeof(struct DllList));
//					strcpy(CurrD1->dllName,CurrD->dllName);
//
//					AddDllToLinkedlist(CurrD1);
//
//					CurrD = CurrD->DllListPrev;
//				}
//				DllListHead = NULL;
//				DllListTail = NULL;
//				CurrP1->CounterOfDll = CounterOfDll;
//				CounterOfDll = 0;
//				
//				CurrP = CurrP->ProcessListNext;
//			}
//			ProcessListHead = NULL;
//			ProcessListTail = NULL;
//			CurrH1->CounterOfProcess = CounterOfProcess;
//			CounterOfProcess = 0;
//
//			CurrH = CurrH->HeadListNext;
//		}
//
//		fclose(f1);
//		//free(HeaderOfSnapshots);
//		free(CurrH);
//		free(CurrP);
//		free(CurrD);
//		
//	}
//	else
//	{
//		//error
//	}
//}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
////***creating html from the data: -----------------------------------------------------------------------------------
//
//int SaveHTMLIntoFile(char* fileName, char* buff)
//{
//	FILE* fi = fopen(fileName, "w");
//	if (!fi)
//	{
//		return 0;
//	}
//
//	fputs(buff, fi);
//
//	fclose(fi);
//}
//
//char* ReadAllHTMLFile(char* fileName)
//{
//	FILE* f = fopen(fileName, "r");
//	if (!f)
//	{
//		return NULL;
//	}
//
//
//	// Get the file size
//	char* buff = (char*)malloc(1000);
//	char* read;
//	int fileSize = 0;
//	while ((read = fgets(buff, 1000, f)))
//	{
//		fileSize += strlen(buff);
//	}
//
//	free(buff);
//	fclose(f);
//	fileSize++;
//	// alloc space as file size
//	buff = (char*)malloc(fileSize);
//
//	f = fopen(fileName, "r");
//	if (!f)
//	{
//		return NULL;
//	}
//	int readPosition = 0;
//	char charToRead;
//	while ((charToRead = fgetc(f)) != EOF)
//	{
//		buff[readPosition] = charToRead;
//		readPosition++;
//	}
//	buff[readPosition] = NULL;
//
//	fclose(f);
//
//	return buff;
//}
//
//#define HomePageSEPERATOR "[[start writing your snapshots and Dlls tables]]"
//#define SnapsotPageSEPERATOR "[[start writing your snapshot's process table]]"
//#define DllPageSEPERATOR "[[start writing your Dll processes table]]"
//
//void HTML_HomePgae()
//{
//	struct HeadOfSnapshotsList* currentHead = HeadListHead;
//	char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_HomePage.html"); // get html template a from local folder
//	char HTML_REPLACE[10000];
//	char* found = strstr(htmlTemplate, HomePageSEPERATOR); // find token adress
//	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * SumOfDll));
//
//	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//	newFileSpace[len] = NULL;
//
//	while (currentHead != NULL)
//	{
//		// creates sample table rows
//		sprintf(HTML_REPLACE, "<tr><td>%d</td><td><a href=\"NewSnapshotPage%d.html\">Snapshot Number %d</a></td><td>%d</td><td>%d</td><td>%zu</td></tr>", currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->CounterOfProcess, currentHead->SumOfDll, currentHead->AverageOfMemoryWorkingSet);
//		strcat(newFileSpace, HTML_REPLACE);
//		len = len + strlen(HTML_REPLACE);
//		newFileSpace[len] = NULL;
//		currentHead = currentHead->HeadListNext;
//		if (currentHead == NULL)
//		{
//			// creates general Dll table header
//			strcpy(HTML_REPLACE, "</table><br><br><h2>General Dll`s List</h2><table><tr><th>Dll Name</th><th>Dll Page</th></tr>");
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//			struct Dic_Dll* currentDll = DD_head;
//			unsigned int counter = 0;
//			while (currentDll != NULL)
//			{
//				//creates general Dll table rows
//				counter++;
//				sprintf(HTML_REPLACE, "<tr><td>%s</td><td><a href=\"newHTML/newDllPage%d.html\">Dll Number %d</a></td></tr>", currentDll->Dic_dllName, counter, counter);
//				strcat(newFileSpace, HTML_REPLACE);
//				len = len + strlen(HTML_REPLACE);
//				newFileSpace[len] = NULL;
//				currentDll = currentDll->DD_next;
//			}
//		}
//	}
//
//	strcat(newFileSpace, found + strlen(HomePageSEPERATOR)); // adding the rest of the template
//
//	SaveHTMLIntoFile("myHTML\\NewHomePage.html", newFileSpace);
//
//	free(newFileSpace);
//	free(htmlTemplate);
//}
//
//void HTML_SnapshotPage(struct HeadOfSnapshotsList* currentHead)
//{	
//	int errorCount = 0;
//	        char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_SnapshotPage.html"); // get html template a from local folder
//			char HTML_REPLACE[10000];
//			char* found = strstr(htmlTemplate, SnapsotPageSEPERATOR); // find token adress
//			unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//			///???
//			char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * currentHead->CounterOfProcess) + (strlen(HTML_REPLACE) * currentHead->SumOfDll));
//
//			strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//			newFileSpace[len] = NULL;
//
//			// adding snapshot page header + processes table header
//			sprintf(HTML_REPLACE, "<h2>Snapshot Number: %d</h2><h2>Snapshot Time: %s</h2><br><br><h1>Process List</h1><table><tr><th>Process ID</th><th>Process Name</th><th>MemoryPageFaultCount</th><th>MemoryWorkingSetSize</th><th>MemoryQuotaPagedPoolUsage</th><th>MemoryQuotaPeakPagedPoolUsage</th><th>MemoryPagefileUsage</th><th>Dll count</th><th>Dll List</th></tr>", currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->TimeOfSnapshot);
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//			struct OneProcessInfo* currentProcess = currentHead->HeadOfSnapshot;
//			while (currentProcess != NULL)
//			{
//				// creates processes table rows
//				if (currentProcess == currentHead->HighestWorkingsetProcess)
//				{
//					//for puting icon
//					sprintf(HTML_REPLACE, "<tr><td>%ul</td><td>%s</td><td>%ul</td><td>%zu <i class=\"fa-solid fa-triangle-exclamation\"></i></td><td>%zu</td><td>%zu</td><td>%zu</td><td>%d</td>", currentProcess->ProcessId, currentProcess->ProcessName, currentProcess->MemoryPageFaultCount, currentProcess->MemoryWorkingSetSize, currentProcess->MemoryQuotaPagedPoolUsage, currentProcess->MemoryQuotaPeakPagedPoolUsage, currentProcess->MemoryPagefileUsage, currentProcess->CounterOfDll);
//					strcat(newFileSpace, HTML_REPLACE);
//					len = len + strlen(HTML_REPLACE);
//					newFileSpace[len] = NULL;
//				}
//				else
//				{
//					sprintf(HTML_REPLACE, "<tr><td>%ul</td><td>%s</td><td>%ul</td><td>%zu</td><td>%zu</td><td>%zu</td><td>%zu</td><td>%d</td>", currentProcess->ProcessId, currentProcess->ProcessName, currentProcess->MemoryPageFaultCount, currentProcess->MemoryWorkingSetSize, currentProcess->MemoryQuotaPagedPoolUsage, currentProcess->MemoryQuotaPeakPagedPoolUsage, currentProcess->MemoryPagefileUsage, currentProcess->CounterOfDll);
//					strcat(newFileSpace, HTML_REPLACE);
//					len = len + strlen(HTML_REPLACE);
//					newFileSpace[len] = NULL;
//				}
//
//				struct DllList* currentDll = currentProcess->CurrentDll;
//				if (currentDll == NULL)
//				{
//					strcpy(HTML_REPLACE, "<td>No Dlls were found</td>");
//					strcat(newFileSpace, HTML_REPLACE);
//					len = len + strlen(HTML_REPLACE);
//					newFileSpace[len] = NULL;
//				}
//				while (currentDll != NULL)
//				{
//					// creates processes Dll select tag for the first dll on the list
//					if (currentDll->DllListNext == NULL)
//					{
//						sprintf(HTML_REPLACE, "<td><select><option>%s</option>", currentDll->dllName);
//						strcat(newFileSpace, HTML_REPLACE);
//						len = len + strlen(HTML_REPLACE);
//						newFileSpace[len] = NULL;
//					}
//					else
//					{
//						sprintf(HTML_REPLACE, "<option>%s</option>", currentDll->dllName);
//						strcat(newFileSpace, HTML_REPLACE);
//						len = len + strlen(HTML_REPLACE);
//						newFileSpace[len] = NULL;
//					}
//					currentDll = currentDll->DllListPrev;
//				}
//
//				if (currentDll == NULL) {
//					strcpy(HTML_REPLACE, "</select></td></tr>");
//					strcat(newFileSpace, HTML_REPLACE);
//					len = len + strlen(HTML_REPLACE);
//					newFileSpace[len] = NULL;
//					errorCount++;
//				}
//				
//				if (errorCount == currentHead->CounterOfProcess)
//				{
//					currentProcess->ProcessListNext = NULL;
//				}
//
//				currentProcess = currentProcess->ProcessListNext;
//			}
//			strcat(newFileSpace, found + strlen(SnapsotPageSEPERATOR)); // adding the rest of the template
//
//			char pageName[100];
//			sprintf(pageName, "myHTML\\NewSnapshotPage%d.html", currentHead->HeadOfSnapshot->CounterOfSnapshots);
//			SaveHTMLIntoFile(pageName, newFileSpace);
//
//			free(newFileSpace);
//			free(htmlTemplate);
//
//}
//
//void HTML_SnapshotPageLoop()
//{
//	struct HeadOfSnapshotsList* currentHead = HeadListHead;
//	while (currentHead != NULL)
//	{
//		HTML_SnapshotPage(currentHead);
//		currentHead = currentHead->HeadListNext;
//	}
//}
//
//void HTML_DllPgae(struct Dic_Dll* currentDll, unsigned int counter)
//{
//
//			char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_DllPage.html");  // get html template a from local folder
//			char HTML_REPLACE[10000];
//			char* found = strstr(htmlTemplate, DllPageSEPERATOR); // find token adress
//			unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//			char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * currentDll->Dic_counterOfProcess));
//
//			strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//			newFileSpace[len] = NULL;
//
//			// adding Dll page header + Dll users table header
//			sprintf(HTML_REPLACE, "<h1>DLL Name: %s</h1><h2>Number Of Processes: %d</h2><br><br><h3>List Of Processes:</h3><div class = \"OneDll\"><ul>", currentDll->Dic_dllName, currentDll->Dic_counterOfProcess);
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//			struct Dic_Process* currentProcess = currentDll->Dic_currProcess;
//			while (currentProcess != NULL)
//			{
//				// creates Dll process table rows
//				sprintf(HTML_REPLACE, "<li>%s</li>", currentProcess->Dic_ProcessName);
//				strcat(newFileSpace, HTML_REPLACE);
//				len = len + strlen(HTML_REPLACE);
//				newFileSpace[len] = NULL;
//				currentProcess = currentProcess->DP_next;
//			}
//			strcat(newFileSpace, found + strlen(DllPageSEPERATOR));  // adding the rest of the template
//
//			char pageName[50];
//			sprintf(pageName, "myHTML\\newHTML\\newDllPage%d.html", counter);
//			SaveHTMLIntoFile(pageName, newFileSpace);
//
//			free(newFileSpace);
//			free(htmlTemplate);
//}
//
//void HTML_DllPgaeLoop()
//{
//	struct Dic_Dll* currentDll = DD_head;
//	unsigned int counter = 0;
//	while (currentDll != NULL)
//	{
//		counter++;
//		HTML_DllPgae(currentDll, counter);
//		currentDll = currentDll->DD_next;
//	}
//}
//
//void GenerateHtmlReport() {
//
//	HTML_HomePgae();
//	HTML_SnapshotPageLoop();
//	HTML_DllPgaeLoop();
//}
//
////void oldHtml_HomePage()
////{
////	//list of all snapshots: ----------------------------
////
////	struct HeadOfSnapshotsList* HTML_currSnapshot = HeadListHead;
////	char HTML_REPLACE[1000];
////
////	char* htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\ProjectA_HomePage.html");
////	SaveIntoFile("newhomepage.html", htmlTemplate);
////
////	while (HTML_currSnapshot != NULL) {
////
////		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newhomepage.html");
////
////		// Number Of Snapshot, Link, Process Count, DLL Count, WorkingSet Memory Average:
////		sprintf(HTML_REPLACE,"%d</td><td><a href =\"/Project A - hen kiso golan/projectA_SnapshotPage.html\">click me</a></td><td>%d</td><td>%ul</td><td>%ul</td></tr>", HTML_currSnapshot->HeadOfSnapshot->CounterOfSnapshots, HTML_currSnapshot->CounterOfProcess, HTML_currSnapshot->SumOfDll, HTML_currSnapshot->AverageOfMemoryWorkingSet);
////		if (!HTML_REPLACE) {
////			HTML_currSnapshot = HTML_currSnapshot->HeadListNext;
////			continue;
////		}
////
////		char* found = strstr(htmlTemplate, "[[line1]]");
////
////		unsigned long len = found - htmlTemplate;
////		char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE) + strlen("<tr><td>[[line1]]</td></tr>"));
////
////		strncpy(newFileSpace, htmlTemplate, len);
////		newFileSpace[len] = NULL;
////
////		strcat(newFileSpace, HTML_REPLACE);
////		newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////
////		strcat(newFileSpace, "<tr><td>[[line1]]</td></tr>");
////		newFileSpace[len + strlen(HTML_REPLACE) + strlen("<tr><td>[[line1]]</td></tr>")] = NULL;
////
////		strcat(newFileSpace, found + strlen("[[line1]]</td></tr>"));
////
////		SaveIntoFile("newhomepage.html", newFileSpace);
////		free(newFileSpace);
////		free(htmlTemplate);
////
////		HTML_currSnapshot = HTML_currSnapshot->HeadListNext;
////	}
////
////	//table of DLL's in all the snapshots: ----------------------------
////
////	struct Dic_Dll* HTML_currDll = DD_head;
////	HTML_REPLACE[1000];
////
////	while (HTML_currDll != NULL) {
////
////		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newhomepage.html");
////
////		// Number Of Snapshot, Link, Process Count, DLL Count, WorkingSet Memory Average:
////		sprintf(HTML_REPLACE, "%s</td><td><a href =\"/Project A - hen kiso golan/projectA_DllPage.html\">click me</a></td></tr>", HTML_currDll->Dic_dllName);
////		if (!HTML_REPLACE) {
////			HTML_currDll = HTML_currDll->DD_next;
////			continue;
////		}
////
////		char* found = strstr(htmlTemplate, "[[line2]]");
////
////		unsigned long len = found - htmlTemplate;
////		char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE) + strlen("<tr><td>[[line2]]</td></tr>"));
////
////		strncpy(newFileSpace, htmlTemplate, len);
////		newFileSpace[len] = NULL;
////
////		strcat(newFileSpace, HTML_REPLACE);
////		newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////
////		strcat(newFileSpace, "<tr><td>[[line2]]</td></tr>");
////		newFileSpace[len + strlen(HTML_REPLACE) + strlen("<tr><td>[[line2]]</td></tr>")] = NULL;
////
////		strcat(newFileSpace, found + strlen("[[line2]]</td></tr>"));
////
////		SaveIntoFile("newhomepage.html", newFileSpace);
////		free(newFileSpace);
////		free(htmlTemplate);
////
////		HTML_currDll = HTML_currDll->DD_next;
////	}
////}
////
////void oldHtml_SnapshotPage() {
////
////	//snapshot page: ----------------------------------------------------------------------------------------
////
////	char* htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\ProjectA_SnapshotPage.html");
////
////	//snapshot number: ----------------------------------------------------------
////	char HTML_REPLACE[10000];
////	int num = 1;  //will change!!!!!!!!!!!!!!!!!!!!!!!!
////	sprintf(HTML_REPLACE, "%d", num);
////
////	char* found = strstr(htmlTemplate, "[[line8]]");
////
////	unsigned long len = found - htmlTemplate;
////	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE));
////
////	strncpy(newFileSpace, htmlTemplate, len);
////	newFileSpace[len] = NULL;
////
////	strcat(newFileSpace, HTML_REPLACE);
////	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////	strcat(newFileSpace, found + strlen("[[line8]]"));
////
////	SaveIntoFile("newsnapshotpage.html", newFileSpace);
////	free(newFileSpace);
////	free(htmlTemplate);
////
////
////	//time of snapshot: ----------------------------
////
////	struct HeadOfSnapshotsList* HTML_currSnap = HeadListHead; //will change!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////
////	strcpy(HTML_REPLACE, HTML_currSnap->HeadOfSnapshot->TimeOfSnapshot);
////
////	htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////
////	found = strstr(htmlTemplate, "[[line9]]");
////
////	len = found - htmlTemplate;
////	newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE));
////
////	strncpy(newFileSpace, htmlTemplate, len);
////	newFileSpace[len] = NULL;
////
////	strcat(newFileSpace, HTML_REPLACE);
////	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////	strcat(newFileSpace, found + strlen("[[line9]]"));
////
////	SaveIntoFile("newsnapshotpage.html", newFileSpace);
////	free(newFileSpace);
////	free(htmlTemplate);
////
////	//list of processes in the snapshot: ----------------------------
////
////	struct OneProcessInfo* HTML_currProcess1 = HTML_currSnap->HeadOfSnapshot;
////
////	while (HTML_currProcess1 != NULL) {
////
////		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////
////		//process name, PageFaultCount, WorkingSetSize, QuotaPagedPoolUsage, QuotaPeakPagedPoolUsage, PagefileUsage, Process ID, DLL Count:
////		sprintf(HTML_REPLACE, "%s</td><td>%lu</td><td>%zu</td><td>%zu</td><td>%zu</td><td>%zu</td><td>%lu</td><td>%d</td>", HTML_currProcess1->ProcessName, HTML_currProcess1->MemoryPageFaultCount, HTML_currProcess1->MemoryWorkingSetSize, HTML_currProcess1->MemoryQuotaPagedPoolUsage, HTML_currProcess1->MemoryQuotaPeakPagedPoolUsage, HTML_currProcess1->MemoryPagefileUsage, HTML_currProcess1->ProcessId, HTML_currProcess1->CounterOfDll);
////		if (!HTML_REPLACE) {
////			HTML_currProcess1 = HTML_currProcess1->ProcessListNext;
////			continue;
////		}
////
////		found = strstr(htmlTemplate, "[[line10]]");
////
////		len = found - htmlTemplate;
////		newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE) + strlen("</td><td><ul><li>[[line10]]</li></ul></td></tr>"));
////
////		strncpy(newFileSpace, htmlTemplate, len);
////		newFileSpace[len] = NULL;
////
////		strcat(newFileSpace, HTML_REPLACE);
////		newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////		strcat(newFileSpace, "</td><td><ul><li>[[line10]]</li></ul></td></tr>");
////		newFileSpace[len + strlen(HTML_REPLACE) + strlen("</td><td><ul><li>[[line10]]</li></ul></td></tr>")] = NULL;
////
////		strcat(newFileSpace, found + strlen("[[line10]]</td></tr>"));
////
////		SaveIntoFile("newsnapshotpage.html", newFileSpace);
////		free(newFileSpace);
////		free(htmlTemplate);
////
////		////----dll list of each process: (works but takes a very long time)----
////				//	struct DllList* HTML_currDll1 = HTML_currProcess1->CurrentDll;
////				//	while (HTML_currDll1 != NULL) {
////				//		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////				//		sprintf(HTML_REPLACE, "%s", HTML_currDll1->dllName);
////				//		if (!HTML_REPLACE) {
////				//			HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//			continue;
////				//		}
////				//		found = strstr(htmlTemplate, "[[line10]]");
////				//		len = found - htmlTemplate;
////				//		newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE) + strlen("</li><li>[[line10]]</li></ul></td></tr>"));
////				//		strncpy(newFileSpace, htmlTemplate, len);
////				//		newFileSpace[len] = NULL;
////				//		strcat(newFileSpace, HTML_REPLACE);
////				//		newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////				//		strcat(newFileSpace, "</li><li>[[line10]]</li></ul></td></tr>");
////				//		newFileSpace[len + strlen(HTML_REPLACE) + strlen("</li><li>[[line10]]</li></ul></td></tr>")] = NULL;
////				//		strcat(newFileSpace, found + strlen("[[line10]]</li></ul></td></tr>"));
////				//		SaveIntoFile("newsnapshotpage.html", newFileSpace);
////				//		free(newFileSpace);
////				//		free(htmlTemplate);
////				//		HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//	}
////
////		//----dll list of each process: round 2 (dont work)----
////				//struct DllList* HTML_currDll1 = HTML_currProcess1->CurrentDll;
////				//char ExtraSpace[1000000];
////				//htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////				//newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(ExtraSpace));
////				//newFileSpace = htmlTemplate;
////				//while (HTML_currDll1 != NULL) {
////				//	sprintf(HTML_REPLACE, "%s", HTML_currDll1->dllName);
////				//	if (!HTML_REPLACE) {
////				//		HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//		continue;
////				//	}
////				//	found = strstr(newFileSpace, "[[line10]]");
////				//	len = found - newFileSpace;
////				//	newFileSpace[len] = NULL;
////				//	//puts zevel in found?
////				//	strcat(newFileSpace, HTML_REPLACE);
////				//	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////				//	strcat(newFileSpace, "</li><li>[[line10]]</li></ul></td></tr>");
////				//	newFileSpace[len + strlen(HTML_REPLACE) + strlen("</li><li>[[line10]]</li></ul></td></tr>")] = NULL;
////				//	strcat(newFileSpace, found + strlen("[[line10]]</li></ul></td></tr>"));
////				//	HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//}
////				//SaveIntoFile("newsnapshotpage.html", newFileSpace);
////				//free(newFileSpace);
////				//free(htmlTemplate);
////				//----	
////
////		//----dll list of each process: round 3 (prints only one dll for each)----
////				//struct DllList* HTML_currDll1 = HTML_currProcess1->CurrentDll;
////				//char ExtraSpace[1000000];
////				//htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////				//newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(ExtraSpace));
////				//while (HTML_currDll1 != NULL) {
////				//	strcpy(HTML_REPLACE, HTML_currDll1->dllName);
////				//	if (!HTML_REPLACE) {
////				//		HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//		continue;
////				//	}
////				//	found = strstr(htmlTemplate, "[[line10]]");
////				//	len = found - htmlTemplate;
////				//	strncpy(newFileSpace, htmlTemplate, len);
////				//	newFileSpace[len] = NULL;
////				//	strcat(newFileSpace, HTML_REPLACE);
////				//	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////				//	strcat(newFileSpace, "</li><li>[[line10]]</li></ul></td></tr>");
////				//	newFileSpace[len + strlen(HTML_REPLACE) + strlen("</li><li>[[line10]]</li></ul></td></tr>")] = NULL;
////				//	strcat(newFileSpace, found + strlen("[[line10]]</li></ul></td></tr>"));
////				//	HTML_currDll1 = HTML_currDll1->DllListPrev;
////				//	//htmlTemplate = newFileSpace;
////				//}
////				//SaveIntoFile("newsnapshotpage.html", newFileSpace);
////				//free(newFileSpace);
////				//free(htmlTemplate);
////				////----			
////
////		//----dll list of each process: round 4----
////
////		struct DllList* HTML_currDll1 = HTML_currProcess1->CurrentDll;
////		char ExtraSpace[1000000];
////		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html");
////		newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(ExtraSpace));
////
////		found = strstr(htmlTemplate, "[[line10]]");
////		len = found - htmlTemplate;
////		strncpy(newFileSpace, htmlTemplate, len);
////		newFileSpace[len] = NULL;
////		SaveIntoFile("newsnapshotpage.html", newFileSpace);
////
////		FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newsnapshotpage.html", "a");
////		if (f1 == NULL) {
////			//log error
////		}
////
////		else {
////			while (HTML_currDll1 != NULL) {
////
////				strcpy(HTML_REPLACE, HTML_currDll1->dllName);
////				if (!HTML_REPLACE) {
////					HTML_currDll1 = HTML_currDll1->DllListPrev;
////					continue;
////				}
////
////				fputs(HTML_REPLACE, f1);
////				fputs("</li><li>", f1);
////
////				HTML_currDll1 = HTML_currDll1->DllListPrev;
////			}
////			fputs("</li></ul></td></tr>", f1);
////			fputs("<tr><td>[[line10]]</td></tr>", f1);
////			fputs("</table></div></body></html>", f1);
////
////			fclose(f1);
////			free(newFileSpace);
////			free(htmlTemplate);
////		}
////
////		HTML_currProcess1 = HTML_currProcess1->ProcessListNext;
////	}
////}
////
////void oldHtml_DllPage() {
////
////	//dll page: ----------------------------------------------------------------------------------------
////
////	char* htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\ProjectA_DllPage.html");
////
////	//dll name: ----------------------------------------------------------
////	char HTML_REPLACE[MAX_PATH];
////	struct Dic_Dll* HTML_currDll = DD_head->DD_next; //will change!!!!!!!!!!!!!!!!!!!!!
////	strcpy(HTML_REPLACE, HTML_currDll->Dic_dllName);
////
////	char* found = strstr(htmlTemplate, "[[line19]]");
////
////	unsigned long len = found - htmlTemplate;
////	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE));
////
////	strncpy(newFileSpace, htmlTemplate, len);
////	newFileSpace[len] = NULL;
////
////	strcat(newFileSpace, HTML_REPLACE);
////	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////	strcat(newFileSpace, found + strlen("[[line19]]"));
////
////	SaveIntoFile("newdllpage.html", newFileSpace);
////	free(newFileSpace);
////	free(htmlTemplate);
////
////
////	//counter of processes that use the one dll: ----------------------------
////
////	sprintf(HTML_REPLACE, "%d", HTML_currDll->Dic_counterOfProcess);
////
////	htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newdllpage.html");
////
////	found = strstr(htmlTemplate, "[[line20]]");
////
////	len = found - htmlTemplate;
////	newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE));
////
////	strncpy(newFileSpace, htmlTemplate, len);
////	newFileSpace[len] = NULL;
////
////	strcat(newFileSpace, HTML_REPLACE);
////	newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////	strcat(newFileSpace, found + strlen("[[line20]]"));
////
////	SaveIntoFile("newdllpage.html", newFileSpace);
////	free(newFileSpace);
////	free(htmlTemplate);
////
////	//list of processes that use the one dll: ----------------------------
////
////	struct Dic_Process* HTML_currProcess = HTML_currDll->Dic_currProcess;
////
////	while (HTML_currProcess != NULL) {
////
////		strcpy(HTML_REPLACE, HTML_currProcess->Dic_ProcessName);
////
////		htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\newdllpage.html");
////
////		found = strstr(htmlTemplate, "[[line21]]");
////
////		len = found - htmlTemplate;
////		newFileSpace = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE) + strlen("</li><li>[[line21]]</li>"));
////
////		strncpy(newFileSpace, htmlTemplate, len);
////		newFileSpace[len] = NULL;
////
////		strcat(newFileSpace, HTML_REPLACE);
////		newFileSpace[len + strlen(HTML_REPLACE)] = NULL;
////
////		strcat(newFileSpace, "</li><li>[[line21]]</li>");
////		newFileSpace[len + strlen(HTML_REPLACE) + strlen("</li><li>[[line21]]</li>")] = NULL;
////
////		strcat(newFileSpace, found + strlen("[[line21]]</li>"));
////
////		SaveIntoFile("newdllpage.html", newFileSpace);
////		free(newFileSpace);
////		free(htmlTemplate);
////
////		HTML_currProcess = HTML_currProcess->DP_next;
////	}
////}
////
////void oldHtml_AboutPage() {
////
////	char* htmlTemplate = ReadAllFile("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\Project A - hen kiso golan\\ProjectA_AboutPage.html");
////	SaveIntoFile("newaboutpage.html", htmlTemplate);
////}
//
////----------------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
////----------------------------------------------log----------------------------------------------------
//char Log_File_Name[100];
//
//void Log(char massage[100])
//{
//	time_t t;
//	time(&t);
//	struct tm* timeinfo;
//	timeinfo = localtime(&t);
//
//
//	char str[100];
//	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);
//
//	FILE* f = fopen("New_Log_Pro.log", "a");
//	fputs("\n\n", f);
//	fputs(str, f);
//	fputs("\n\n", f);
//
//
//	fclose(f);
//}
//
//void Error_Log(char message[100])
//{
//	char newMessage[100];
//	sprintf(newMessage, "Error - %s", message);
//	Log(newMessage);
//}
//
//void Event_Log(char message[100])
//{
//	char newMessage[100];
//	sprintf(newMessage, "Event - %s", message);
//	Log(newMessage);
//}
//
//void Log_init(char Log_Name[100])
//{
//	strcpy(Log_File_Name, Log_Name);
//}
////----------------------------------------------log----------------------------------------------------
//
//
//
//
//main()
//{
//	
//	GetProcessesInfo();
//	GetProcessesInfo();
//	//DllPgaeGeneratorLoop();
//	//GetProcessesInfo();
//	GenerateHtmlReport();
//	//HTML_DllPgae();
//	//GetProcessesInfo();
//	//GetProcessesInfo_20version();
//	//GetProcessesInfo_UserVersion();
//	//ResetCollections();
//	//GetProcessesInfo();
//	//SaveSnapshotsToFile();
//	//GetProcessesInfo();
//	//LoadSnapshotsFromFile("projectAfile.bin");
//	//SaveSnapshotsToFile();
//	//ResetCollections();
//	//GetProcessesInfo();
//	//SaveSnapshotsToFile();
//	//ResetCollections();
//	//ResetCollections();
//	//char str = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\Project A - hen kiso golan\\projectAfile.bin";
//	//LoadSnapshotsFromFile(str);
//	//int i = 5;
//	//i = i + 5;
//
//	//GetProcessesInfo_UserVersion(); 
//
//	return 0;
//}
//

//----------------------------------------------------main-------------------------------------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <conio.h>
//#include <windows.h>
//#include <psapi.h>
//#pragma warning (disable : 4996)
//
//int main12345567()
//{
//  int UserChoice;
//  printf("****MENU****\n~ Type Option Number For Execution ~\n1.Take One SnapShot.\n2.Take 60 Seconds SnapShot.\n3.Start Long SnapShot.\n4.End Long SnapShot.\n5.Generate HTML Report.\n6.Reset Collections.\n7.Save in File.\n8.Load from File.\n9.Quit\ntype here:");
//  scanf("%d", &UserChoice);
//  printf("\n\n");
//     switch (UserChoice)
//     {
//        case 1:
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 4:
//            break;
//        case 5:
//            break;
//        case 6:
//            break;
//        case 7:
//            break;
//        case 8:
//            break;
//        case 9:
//            break;
//        default:
//          printf("invalid choice");
//          printf("\n\n");
//          break;
//     }
//       
//        
//   
//  return 0;
//}
//
//
//
//
//
//
//
//
//

