//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//#include <windows.h>
//#include <psapi.h>
//#include <wchar.h>
//
//#pragma warning (disable : 4996)
//
//
//
//typedef struct HeadOfSnapshotsList_Header
//{
//	int version;
//	int Head_Of_Snapshots_Head_List_Counter;
//	char Reserved[1000];
//}t_HeadOfSnapshotsList_Header;
//int Head_Of_Snapshots_Head_List_Counter = 0;
//
//typedef struct HeadOfSnapshotsList {
//	struct ProcessData* HeadOfSnapshot;
//	struct ProcessData* HighestWorkingSetSize_In_One_p;
//	int prosesCountOfEachHead;
//	long int sum_of_Dll;//*************For generata HTML****************
//	unsigned long Average_of_MemoryWorkingSetSize;//*************For generata HTML  //log int- because the number is very big****************
//	struct HeadOfSnapshotsList* HeadListNext;
//	struct HeadOfSnapshotsList* HeadListPrev;
//}t_HeadOfSnapshotsList;
//
//t_HeadOfSnapshotsList* HeadListHead = NULL;
//t_HeadOfSnapshotsList* HeadListTail = NULL;
//t_HeadOfSnapshotsList* CurrentHead;
//t_HeadOfSnapshotsList* PrevItemHead;
//int sum_of_Dll = 0; //*************For generata HTML****************
//unsigned long long sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
//int prosesCount = 0;
//
//typedef struct DllList {
//	//single dll info:
//	char dllName[MAX_PATH];
//	struct DllList* DllListNext;
//	struct DllList* DllListPrev;
//}t_DllList;
//
//t_DllList* DllListHead = NULL;
//t_DllList* DllListTail = NULL;
//t_DllList* CurrentDll;
//t_DllList* PrevItemDll;
//
//
//typedef struct ProcessData {
//	//snapshot info:
//	unsigned int CounterOfSnapshots;
//	char TimeOfSnapshot[100];
//	//process info:
//	char ProcessName[MAX_PATH];
//	DWORD ProcessId;
//	//process memory use info:
//	DWORD MemoryPageFaultCount;
//	SIZE_T MemoryWorkingSetSize;
//	SIZE_T MemoryQuotaPeakPagedPoolUsage;
//	SIZE_T MemoryQuotaPagedPoolUsage;
//	SIZE_T MemoryPagefileUsage;
//	//dll list info:
//	unsigned int DllCount;
//	struct DllList* CurrentDll;
//	//process linked list info:
//	struct ProcessData* ProcessListNext;
//	struct ProcessData* ProcessListPrev;
//} t_ProcessData;
//
//t_ProcessData* ProcessListHead = NULL;
//t_ProcessData* ProcessListTail = NULL;
//t_ProcessData* Current;
//t_ProcessData* PrevItem;
//int CounterOfSnapshots = 0;
//
//
//typedef struct Dic_Dll {
//	char Dic_dllName[MAX_PATH];
//	int Dic_counterOfProcess;
//	struct Dic_Process* Dic_currProcess;
//	struct Dic_Process* Dic_previtemProcess;
//	struct Dic_Dll* DD_prev;
//	struct Dic_Dll* DD_next;
//}t_Dic_Dll;
//
//t_Dic_Dll* DD_head = NULL;
//t_Dic_Dll* DD_tail = NULL;
//t_Dic_Dll* DD_prevItem;
//
//
//typedef struct Dic_Process {
//	char Dic_ProcessName[MAX_PATH];
//	struct Dic_Process* DP_prev;
//	struct Dic_Process* DP_next;
//}t_Dic_Process;
//
//t_Dic_Process* DP_tail = NULL;
//
////----------------------------------------------log----------------------------------------------------
//void Log(char massage[100])
//{
//	time_t t;
//	time(&t);
//	struct tm* timeinfo;
//
//	timeinfo = localtime(&t);
//	char str[100];
//	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);
//
//	FILE* f = fopen("Yoni_log.log", "a");
//	fputs("\n\n", f);
//	fputs(str, f);
//	fputs("\n\n", f);
//
//
//	fclose(f);
//}
//
//void LogError(char message[100])
//{
//	char newMessage[100];
//	sprintf(newMessage, "Error - %s", message);
//	Log(newMessage);
//}
//
//void EventLog(char message[100])
//{
//	char newMessage[100];
//	sprintf(newMessage, "Event - %s", message);
//	Log(newMessage);
//}
//
//void text_init(char usernum[100])
//{
//	FILE* f1 = fopen("numbers.txt", "a");
//	if (f1) {
//
//		for (int i = 0; i < atoi(usernum); i++)
//		{
//			char usernum2[100];
//			itoa(i, usernum2, 10);
//			fputs(usernum2, f1);
//			fputs("\n", f1);
//		}
//		fclose(f1);
//	}
//	else
//	{
//		LogError("the file did not open");
//		//error
//	}
//
//}
////----------------------------------------------log----------------------------------------------------
//
//
//void Search_HighestWorkingSetSize_In_One_p(t_HeadOfSnapshotsList* headOfSnapshot) {
//
//	t_ProcessData* HolderOfHigestWSS = headOfSnapshot->HeadOfSnapshot;
//	t_ProcessData* List = headOfSnapshot->HeadOfSnapshot->ProcessListNext;
//
//	while (List != NULL) {
//		if (HolderOfHigestWSS->MemoryWorkingSetSize >= List->MemoryWorkingSetSize) {
//
//			List = List->ProcessListNext;
//		}
//		else {
//
//			//*********placement**********
//			HolderOfHigestWSS = List;
//			List = List->ProcessListNext;
//		}
//	}
//
//	headOfSnapshot->HighestWorkingSetSize_In_One_p = HolderOfHigestWSS;
//
//	return;
//}
//
//void AddDllToLinkedlist_Dictionary(t_Dic_Dll* DD_current)
//{
//
//	DD_current->Dic_counterOfProcess = 0;
//	sum_of_Dll++; //*************For generata HTML****************
//
//	if (DD_head == NULL) {
//		DD_head = DD_current;
//		DD_tail = DD_head;
//		DD_current->DD_next = NULL;
//		DD_current->DD_prev = NULL;
//		DD_prevItem = DD_current;
//	}
//	else
//	{
//		DD_tail = DD_current;
//		DD_tail->DD_prev = DD_prevItem;
//		DD_tail->DD_next = NULL;
//		DD_prevItem->DD_next = DD_tail;
//		DD_prevItem = DD_current;
//	}
//}
//
//struct Dic_Process* AddProcessToLinkedlist_Dictionary(t_Dic_Process* DP_current, t_Dic_Process* DP_head, t_Dic_Process* DP_prevItem)
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
//void CreatDictionary_DP(t_Dic_Dll* DD_NewDll, char Dic_ProcessName[MAX_PATH]) {
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
//void CreatDictionary_DD_Generate_HTML_Report(char Dic_dllName[MAX_PATH], char Dic_ProcessName[MAX_PATH]) {
//
//	struct Dic_Dll* Dic_CurrentDllKey = DD_head;
//
//	while (Dic_CurrentDllKey != NULL) {
//		if (!(strcmp(Dic_CurrentDllKey->Dic_dllName, Dic_dllName))) {
//			CreatDictionary_DP(Dic_CurrentDllKey, Dic_ProcessName);
//
//			return;
//		}
//		else {
//			Dic_CurrentDllKey = Dic_CurrentDllKey->DD_next;
//		}
//	}
//
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
//
//}
//
//
//void Replace(t_ProcessData* item)
//{
//	if (item == NULL) {
//		//	EventLogval("No need to swap", 0);
//		return;
//	}
//
//	//CopyList = (t_ItemNum*)malloc(sizeof(t_ItemNum));
//	t_ProcessData CopyList;
//	t_ProcessData* NextItem;
//	t_ProcessData* List;
//
//	List = item;
//	CopyList.ProcessListNext = item->ProcessListNext;
//	CopyList.ProcessListPrev = item->ProcessListPrev;
//	NextItem = item->ProcessListNext;
//
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
//	//free(CopyList);
//}
//
//void Shaiker_Sort_ProcessDataByDllCount()
//{
//	int Bublecounter = 1;
//
//	// add search tail
//
//
//
//
//	t_ProcessData* curr = ProcessListHead; // enter the real head
//	t_ProcessData* CheckItem;
//	t_ProcessData* CopyHead = NULL;
//	t_ProcessData* CopyTail = NULL;
//
//	if (!curr/* !curr = curr!=NULL*/) {
//		//EventLog("the list is empty");
//		return;
//	}
//
//	// add search tail
//
//
//	//EventLog("Start sorting");
//	while (Bublecounter != 0)
//	{
//		curr = ProcessListHead;
//		CheckItem = ProcessListHead->ProcessListNext;
//
//		while (Bublecounter != 0)
//		{
//			Bublecounter = 0;
//
//			while (CheckItem != NULL && curr->ProcessListNext != CopyTail)
//			{
//				if (curr->DllCount < CheckItem->DllCount) {
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
//				if (curr->DllCount > CheckItem->DllCount) {
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
//		}
//	}
//	//EventLog("End sorting");
//
//}
//
//
////---------------------------------------------------snapshot-------------------------------------------------------------
//
//void AddHeadToLinkedlist(t_HeadOfSnapshotsList* CurrentHead)
//{
//	Head_Of_Snapshots_Head_List_Counter++;
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
//}
//
//
//void AddProscessToLinkedlist(t_ProcessData* Current)
//{
//	if (!strstr(Current->ProcessName, "exe")) {
//		return;
//	}
//	prosesCount++;
//
//	//if (CounterOfSnapshots == 4)
//	//{
//	//	if (prosesCount == 186)
//	//	{
//	//		Sleep(10);
//	//	}
//	//}
//
//	Current->ProcessListNext = NULL;
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
//}
//
//
//void AddDllToLinkedlist(t_DllList* CurrentDll)
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
//}
//
//
//void GetMemoryAndDllInfo(DWORD processID, char strTime[100], int CounterOfSnapshots)
//{
//
//	int err;
//	char* strE;
//
//	//**placement***
//	t_ProcessData* Curr = (t_ProcessData*)malloc(sizeof(t_ProcessData));
//
//	Curr->ProcessListNext = NULL;
//	Curr->ProcessListPrev = NULL;
//	Curr->CurrentDll = NULL;
//
//	//**placement***
//	Curr->CounterOfSnapshots = CounterOfSnapshots;
//
//	//**placement***
//	strcpy(Curr->TimeOfSnapshot, strTime);
//
//	//**placement***
//	Curr->ProcessId = processID;
//
//	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
//	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info
//
//  //like doing "fopen" of a process by using the id and pointer
//	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
//
//	if (NULL == hProcess) {
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//		//error. write to log
//		return;
//	}
//
//	HMODULE hMods[1024];  //* hMods - an array of all the dll of one process
//	DWORD cbNeeded;
//	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
//	TCHAR Buffer2[MAX_PATH];  //* buffer2 - contains the full path (name) to the dll.
//
//	//Get process name
//	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
//	{
//		//**placement***
//		// Convert wChar to regular char array (string)
//		size_t numConverted;
//		wcstombs_s(&numConverted, Curr->ProcessName, MAX_PATH, Buffer, MAX_PATH);
//	}
//	else
//	{
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//		//error. write to log
//	}
//
//	//Get memory info
//	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
//	{
//		//**placement***
//		Curr->MemoryPageFaultCount = pmc.PageFaultCount;
//		Curr->MemoryWorkingSetSize = pmc.PeakWorkingSetSize;
//		Curr->MemoryQuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
//		Curr->MemoryQuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
//		Curr->MemoryPagefileUsage = pmc.PagefileUsage;
//		sum_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize + Curr->MemoryWorkingSetSize; //*************For generata HTML****************
//	}
//
//	//Get Dlls List
//	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
//	{
//		//**placement***
//		Curr->DllCount = 0;
//
//		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
//		{
//
//			//Get dll name, general count, index
//			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
//			{
//				//**placement***
//				t_DllList* CurrentDll = (t_DllList*)malloc(sizeof(t_DllList));
//				Curr->CurrentDll = CurrentDll;
//
//				// Convert wChar to regular char array (string)
//				//**placement***
//				size_t numConverted;
//				wcstombs_s(&numConverted, CurrentDll->dllName, MAX_PATH, Buffer2, MAX_PATH);
//
//				Curr->DllCount++;
//
//
//				//creat dlls linked list
//				AddDllToLinkedlist(CurrentDll);
//				CreatDictionary_DD_Generate_HTML_Report(CurrentDll->dllName, Curr->ProcessName);
//
//			}
//		}
//		DllListHead = NULL;
//		DllListTail = NULL;
//	}
//
//	//creat processes linked list
//	AddProscessToLinkedlist(Curr);
//	CloseHandle(hProcess);
//}
//
//
//void GetProcessesInfo()
//{
//	int err;
//	char* strE;
//	//Get Processes - Receive all process ID
//	DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
//	unsigned int i;
//
//	//Receive all process ID and put in aProcesses Array
//	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//	{
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
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
//		//* aProcesses[i] - the id of a singel process
//	}
//
//	Shaiker_Sort_ProcessDataByDllCount();
//	t_HeadOfSnapshotsList* CurrentHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
//	CurrentHead->HeadOfSnapshot = ProcessListHead;
//	CurrentHead->prosesCountOfEachHead = prosesCount; ///cProcesses- i dont use this, becuse it include the process that we are not allwo to get into.
//	CurrentHead->sum_of_Dll = sum_of_Dll;//*************For generata HTML****************
//	CurrentHead->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;//*************For generata HTML****************
//	AddHeadToLinkedlist(CurrentHead);
//
//	Search_HighestWorkingSetSize_In_One_p(CurrentHead);
//
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	//**placement***
//	prosesCount = 0;
//	sum_of_MemoryWorkingSetSize = 0;//*************For generata HTML****************
//}
////---------------------------------------------------snapshot-------------------------------------------------------------
//
//
//
////---------------------------------------20 snapshot--------------------------------------------
//t_ProcessData* SearchProcess(DWORD processID, char key[MAX_PATH], DWORD MemoryPageFaultCount, SIZE_T MemoryWorkingSetSize, SIZE_T MemoryQuotaPagedPoolUsage, SIZE_T MemoryQuotaPeakPagedPoolUsage, SIZE_T MemoryPagefileUsage)
//{
//
//	t_ProcessData* List = HeadListTail->HeadOfSnapshot;
//	t_ProcessData* currkey = HeadListTail->HeadOfSnapshot;
//
//	t_HeadOfSnapshotsList* CurrentHead1 = HeadListTail->HeadOfSnapshot;
//
//
//	while (List != NULL)
//	{
//		List = currkey;
//		currkey = currkey->ProcessListNext;
//
//		if ((!(strcmp(List->ProcessName, key))) && processID == List->ProcessId) { //if strcmp==0 it is eqwal
//			List->MemoryPageFaultCount = List->MemoryPageFaultCount + MemoryPageFaultCount;
//			List->MemoryWorkingSetSize = List->MemoryWorkingSetSize + MemoryWorkingSetSize;
//			List->MemoryQuotaPagedPoolUsage = List->MemoryQuotaPagedPoolUsage + MemoryQuotaPagedPoolUsage;
//			List->MemoryQuotaPeakPagedPoolUsage = List->MemoryQuotaPeakPagedPoolUsage + MemoryQuotaPeakPagedPoolUsage;
//			List->MemoryPagefileUsage = List->MemoryPagefileUsage + MemoryPagefileUsage;
//			sum_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize + List->MemoryWorkingSetSize; //*************For generata HTML****************
//
//			return List;
//		}
//		else if (currkey == NULL) {
//
//			GetMemoryAndDllInfo(processID, HeadListTail->HeadOfSnapshot->TimeOfSnapshot, HeadListTail->HeadOfSnapshot->CounterOfSnapshots);
//			CurrentHead1->prosesCountOfEachHead = prosesCount;
//			return NULL;
//		}
//	}
//
//}
//
//void searchDll(char keyDLL[MAX_PATH], t_ProcessData* currproses)
//{
//
//	t_DllList* currDllkey = currproses->CurrentDll;
//	t_DllList* List = currproses->CurrentDll;
//
//	while (List != NULL)
//	{
//		List = currDllkey;
//		currDllkey = currDllkey->DllListPrev;
//
//
//		if (!(strcmp(List->dllName, keyDLL))) {
//			return;
//		}
//		else if (currDllkey == NULL) {
//
//			t_DllList* NewDll = (t_DllList*)malloc(sizeof(t_DllList));
//			//NewDll->dllName == keyDLL; // **************why this placement work??***************
//			strcpy(NewDll->dllName, keyDLL);
//			currproses->CurrentDll->DllListNext = NewDll;
//			NewDll->DllListNext = NULL;
//			NewDll->DllListPrev = currproses->CurrentDll;
//			currproses->CurrentDll = NewDll;
//			DllListTail = NewDll;
//			currproses->DllCount++;
//			return;
//		}
//	}
//
//}
//
//void GetProcessesInfo_WithoutNULL()
//{
//	int err;
//	char* strE;
//
//	//Get Processes - Receive all process ID
//	DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
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
//		//* aProcesses[i] - the id of a singel process
//	}
//
//
//	t_HeadOfSnapshotsList* CurrentHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
//	CurrentHead->HeadOfSnapshot = ProcessListHead;
//	CurrentHead->prosesCountOfEachHead = prosesCount; ///cProcesses- i dont use this, becuse it include the process that we are not allwo to get into.
//	CurrentHead->sum_of_Dll = sum_of_Dll;//*************For generata HTML****************
//	CurrentHead->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;//*************For generata HTML****************
//	AddHeadToLinkedlist(CurrentHead);
//
//
//
//}
//
//void GetMemoryAndDllInfo_20(DWORD processID)
//{
//	int err;
//	char* strE;
//
//	HANDLE hProcess;  //** hprocess - a pointer to a singel process by the id we got
//	PROCESS_MEMORY_COUNTERS pmc;  //** pmc - a struct of a singel process by the id we got, contains all the process memory info
//
//  //like doing "fopen" of a process by using the id and pointer
//	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
//
//	if (NULL == hProcess) {
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//		//error. write to log
//		return;
//	}
//
//
//	HMODULE hMods[1024];  //* hMods - an array of all the dll of one process
//	DWORD cbNeeded;
//	TCHAR Buffer[MAX_PATH];   //** buffer - contains the full path (name) to the executable (process)
//	TCHAR Buffer2[MAX_PATH];  //* buffer2 - contains the full path (name) to the dll.
//
//	char keyProcess[MAX_PATH];
//	char keyDLL[MAX_PATH];
//	t_ProcessData* keyproses_For_Check_Dll = NULL;
//
//	//Get process name
//	if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
//	{
//
//		//**placement***
//		// Convert wChar to regular char array (string)
//		size_t numConverted;
//		wcstombs_s(&numConverted, keyProcess, MAX_PATH, Buffer, MAX_PATH);
//	}
//	else
//	{
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//		//error. write to log
//	}
//
//
//	//Get memory info
//	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
//	{
//		//**placement***
//		keyproses_For_Check_Dll = SearchProcess(processID, keyProcess, pmc.PageFaultCount, pmc.PeakWorkingSetSize, pmc.QuotaPagedPoolUsage, pmc.QuotaPeakPagedPoolUsage, pmc.PagefileUsage);
//	}
//
//
//	//Get Dlls List
//	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
//	{
//
//
//		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
//		{
//
//			//Get dll name, general count, index
//			if (GetModuleFileNameEx(hProcess, hMods[i], Buffer2, MAX_PATH))
//			{
//
//				// Convert wChar to regular char array (string)
//				//**placement***
//				size_t numConverted;
//				wcstombs_s(&numConverted, keyDLL, MAX_PATH, Buffer2, MAX_PATH);
//
//				CreatDictionary_DD_Generate_HTML_Report(keyDLL, keyProcess);
//
//				if (keyproses_For_Check_Dll == NULL) { //whan we add a new proses to the list we dont need to check the dll list
//					return;
//				}
//				else
//				{
//					searchDll(keyDLL, keyproses_For_Check_Dll);
//				}
//			}
//		}
//	}
//
//
//	CloseHandle(hProcess);
//}
//
//void GetProcessesInfo_20()
//{
//	int err;
//	char* strE;
//	GetProcessesInfo_WithoutNULL();
//
//	for (int i = 0; i < 20; i++)
//	{
//		Sleep(1000);
//
//		//Get Processes - Receive all process ID
//		DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
//		unsigned int i;
//
//		//Receive all process ID and put in aProcesses Array
//		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//		{
//			err = GetLastError();
//			strE = strerror(err);
//			LogError(strE);
//			//Error. Write to log
//			return 1;
//		}
//
//		//Calculate how many process identifiers were returned.
//		cProcesses = cbNeeded / sizeof(DWORD);
//
//
//		//Loop of all processes - For each Process, get its Memory Information
//		for (i = 0; i < cProcesses; i++)
//		{
//			GetMemoryAndDllInfo_20(aProcesses[i]);
//			//* aProcesses[i] - the id of a singel process
//		}
//	}
//	Shaiker_Sort_ProcessDataByDllCount();
//	HeadListTail->HeadOfSnapshot = ProcessListHead;
//
//	Search_HighestWorkingSetSize_In_One_p(HeadListTail);
//
//	HeadListTail->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;
//	HeadListTail->sum_of_Dll = sum_of_Dll;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	DllListHead = NULL;  ///is alrady null but i dont take risk
//	DllListTail = NULL;  ///is alrady null but i dont take risk
//
//	//**placement***
//	prosesCount = 0;
//	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
//}
//
////---------------------------------------20 snapshot---------------------------------------------
//
//
//
//
//
////---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------
//
//void GetProcessesInfo_Long_SnapShot()
//{
//	int err;
//	char* strE;
//	int counter_of_shots = 1;
//
//	GetProcessesInfo_WithoutNULL();
//	int Stop = 1;
//	printf("%d", counter_of_shots);
//
//	while (Stop)
//	{
//		counter_of_shots++;
//		printf("%d", counter_of_shots);
//		/*Sleep(1000);*/
//
//		//Get Processes - Receive all process ID
//		DWORD aProcesses[1024], cbNeeded, cProcesses;  //* aProcesses - array of id, * cProcesses - how many id we have 
//		unsigned int i;
//
//		//Receive all process ID and put in aProcesses Array
//		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
//		{
//			err = GetLastError();
//			strE = strerror(err);
//			LogError(strE);
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
//			GetMemoryAndDllInfo_20(aProcesses[i]);
//			//* aProcesses[i] - the id of a singel process
//		}
//
//
//		if (kbhit()) // kbhit() return 1 if keyboard key was clicked else returns 0
//		{
//			char ch1 = getch();
//			if (ch1 == 'E') {
//				Stop = 0;
//			}
//		}
//	}
//	Shaiker_Sort_ProcessDataByDllCount();
//	HeadListTail->HeadOfSnapshot = ProcessListHead;
//
//	Search_HighestWorkingSetSize_In_One_p(HeadListTail);
//	HeadListTail->Average_of_MemoryWorkingSetSize = sum_of_MemoryWorkingSetSize / prosesCount;
//	HeadListTail->sum_of_Dll = sum_of_Dll;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	DllListHead = NULL;  ///is alrady null but i dont take risk
//	DllListTail = NULL;  ///is alrady null but i dont take risk
//
//	//**placement***
//	prosesCount = 0;
//	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
//}
//
////---------------------------------------Start Long SnapShot & End Long SnapShot---------------------------------------------
//
//
//
//
//
////---------------------------------------reset collection functions---------------------------------------------
//
//void ResetCollections() {
//
//	int err;
//	char* strE;
//
//	prosesCount = 0;
//	Head_Of_Snapshots_Head_List_Counter = 0;
//	CounterOfSnapshots = 0;
//
//	// it is alredy "0" , - double check
//	sum_of_Dll = 0; //*************For generata HTML****************
//	sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
//
//	//reset all snapshots:
//	t_HeadOfSnapshotsList* CurrFreeHead = HeadListHead;
//	t_HeadOfSnapshotsList* FreeHead = NULL;
//
//	// if there are no list 
//	if (CurrFreeHead == NULL) {
//		// log error
//		return;
//	}
//
//	//reset one snapshot:
//	while (CurrFreeHead->HeadListNext != NULL) {
//
//		t_ProcessData* CurrFreeProcess = CurrFreeHead->HeadOfSnapshot;
//		t_ProcessData* FreeProcess = NULL;
//
//		//reset one process
//		while (CurrFreeProcess->ProcessListNext != NULL) {
//
//			t_DllList* CurrFreeDll = CurrFreeProcess->CurrentDll;
//			t_DllList* FreeDll = NULL;
//
//			//reset dll list in one process:
//			while (CurrFreeDll->DllListPrev != NULL) {
//				//go to next dll:
//				FreeDll = CurrFreeDll;
//				CurrFreeDll = CurrFreeDll->DllListPrev;
//				free(FreeDll);
//			}
//			//free last dll:
//			FreeDll = CurrFreeDll;
//			free(FreeDll);
//
//			//go to next process:
//			FreeProcess = CurrFreeProcess;
//			CurrFreeProcess = CurrFreeProcess->ProcessListNext;
//			free(FreeProcess);
//		}
//		//free last process:
//		FreeProcess = CurrFreeProcess;
//		free(FreeProcess);
//
//		//go to next snapshot:
//		FreeHead = CurrFreeHead;
//		CurrFreeHead = CurrFreeHead->HeadListNext;
//		free(FreeHead);
//	}
//	//free last head:
//	FreeHead = CurrFreeHead;
//	free(FreeHead);
//	DllListHead = NULL;
//	DllListTail = NULL;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	HeadListHead = NULL;
//	HeadListTail = NULL;
//
//	//clean the file and put reaset massega
//	FILE* f = fopen("project.bin", "wb");
//	if (f) {
//
//		t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
//		currHeader->version = 0;
//		currHeader->Head_Of_Snapshots_Head_List_Counter = 0;
//		strcpy(currHeader->Reserved, "the File was Reset");
//
//		int write = fwrite(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
//		if (write == NULL) {
//			err = GetLastError();
//			strE = strerror(err);
//			LogError(strE);
//			//error
//		}
//	}
//	else
//	{
//		//error
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//	}
//	fclose(f);
//
//	//clean the struct From Generate_HTML_Report 
//	// 
//	//reset one Dll From Generate_HTML_Report
//	// 
//	t_Dic_Dll* CurrFreeDic_Dll = DD_head;
//	t_Dic_Dll* FreeDic_Dll = NULL;
//
//	while (CurrFreeDic_Dll->DD_next != NULL) {
//
//		t_Dic_Process* CurrFreeDic_Process = CurrFreeDic_Dll->Dic_currProcess;
//		t_Dic_Process* FreeDic_Process = NULL;
//
//		//reset Process list in one Dll:
//		while (CurrFreeDic_Process->DP_next != NULL) {
//			//go to next Process:
//			FreeDic_Process = CurrFreeDic_Process;
//			CurrFreeDic_Process = CurrFreeDic_Process->DP_next;
//			free(FreeDic_Process);
//		}
//		//free last Process:
//		FreeDic_Process = CurrFreeDic_Process;
//		free(FreeDic_Process);
//
//		//go to next Dll:
//		FreeDic_Dll = CurrFreeDic_Dll;
//		CurrFreeDic_Dll = CurrFreeDic_Dll->DD_next;
//		free(FreeDic_Dll);
//	}
//	//free last Dll:
//	FreeDic_Dll = CurrFreeDic_Dll;
//	free(FreeDic_Dll);
//
//	DD_head = NULL;
//	DD_tail = NULL;
//	DP_tail = NULL;
//}
//
////---------------------------------------reset collection functions---------------------------------------------
//
//
//
//
////---------------------------------------Save in File---------------------------------------------
//
//void Save_Collections_In_File(char FileName[100]) {
//
//	int err;
//	char* strE;
//
//	// malloc to Header of File + placement
//	t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
//	currHeader->version = 1;
//	currHeader->Head_Of_Snapshots_Head_List_Counter = Head_Of_Snapshots_Head_List_Counter;
//	strcpy(currHeader->Reserved, "the File was Saved");
//
//
//
//	t_HeadOfSnapshotsList* CurrHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
//	t_ProcessData* CurrProcess = (t_ProcessData*)malloc(sizeof(t_ProcessData));
//	t_DllList* CurrDll = (t_DllList*)malloc(sizeof(t_DllList));
//
//
//	FILE* f = fopen(FileName, "wb");
//	if (f) {
//
//		int write = fwrite(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
//		if (write == NULL) {
//
//			err = GetLastError();
//			strE = strerror(err);
//			LogError(strE);
//			//error
//		}
//		fclose(f);
//	}
//	else
//	{
//		//error
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//	}
//
//	f = fopen(FileName, "ab");
//	if (f) {
//
//		CurrHead = HeadListHead;
//
//		for (int i = 0; i < currHeader->Head_Of_Snapshots_Head_List_Counter; i++)
//		{
//			int write = fwrite(CurrHead, sizeof(t_HeadOfSnapshotsList), 1, f);
//			if (!write) { //!write = if its not null its true 1=true    0=Fales
//				err = GetLastError();
//				strE = strerror(err);
//				LogError(strE);
//			}
//
//			CurrProcess = CurrHead->HeadOfSnapshot;
//
//			for (int i = 0; i < CurrHead->prosesCountOfEachHead; i++)
//			{
//				write = fwrite(CurrProcess, sizeof(t_ProcessData), 1, f);
//				if (!write) {  //!write = if its not null its true 1=true    0=Fales
//					err = GetLastError();
//					strE = strerror(err);
//					LogError(strE);
//					//error
//				}
//
//				CurrDll = CurrProcess->CurrentDll;
//
//				for (int i = 0; i < CurrProcess->DllCount; i++)
//				{
//					write = fwrite(CurrDll, sizeof(t_DllList), 1, f);
//					if (!write) {  //!write = if its not null its true 1=true    0=Fales
//						err = GetLastError();
//						strE = strerror(err);
//						LogError(strE);
//						//error
//					}
//					CurrDll = CurrDll->DllListPrev;
//				}
//				CurrProcess = CurrProcess->ProcessListNext;
//			}
//			CurrHead = CurrHead->HeadListNext;
//		}
//
//		fclose(f);
//		free(currHeader);
//		free(CurrHead);
//		free(CurrProcess);
//		free(CurrDll);
//	}
//}
//
////---------------------------------------Save in File---------------------------------------------
//
//
//
//
//
////---------------------------------------Load From File-----------------------------------------------------------
//
//void Load_Collections_From_File(char FileName[100]) {
//
//	int err;
//	char* strE;
//
//	// malloc to Header of File + placement
//	t_HeadOfSnapshotsList_Header* currHeader = (t_HeadOfSnapshotsList_Header*)malloc(sizeof(t_HeadOfSnapshotsList_Header));
//
//	Head_Of_Snapshots_Head_List_Counter = 0;
//	prosesCount = 0;
//
//	//// it is alredy "0" , - double check
//	//sum_of_Dll = 0; //*************For generata HTML****************
//	//sum_of_MemoryWorkingSetSize = 0; //*************For generata HTML****************
//
//
//	HeadListHead = NULL;
//	HeadListTail = NULL;
//	ProcessListHead = NULL;
//	ProcessListTail = NULL;
//	DllListHead = NULL;
//	DllListTail = NULL;
//
//	t_HeadOfSnapshotsList* CurrHead = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
//	t_ProcessData* CurrProcess = (t_ProcessData*)malloc(sizeof(t_ProcessData));
//	t_DllList* CurrDll = (t_DllList*)malloc(sizeof(t_DllList));
//
//
//
//	FILE* f = fopen(FileName, "rb");
//	if (f) {
//
//		int read = fread(currHeader, sizeof(t_HeadOfSnapshotsList_Header), 1, f);
//		printf("Heder:: version:%d Itemcount:%d massege:%s\n\n", currHeader->version, currHeader->Head_Of_Snapshots_Head_List_Counter, currHeader->Reserved);
//		if (read == NULL) {
//			err = GetLastError();
//			strE = strerror(err);
//			LogError(strE);
//			//error
//		}
//
//
//		for (int i = 0; i < currHeader->Head_Of_Snapshots_Head_List_Counter; i++)
//		{
//			read = fread(CurrHead, sizeof(t_HeadOfSnapshotsList), 1, f);
//			if (!read) { //!write = if its not null its true 1=true    0=Fales
//				err = GetLastError();
//				strE = strerror(err);
//				LogError(strE);
//				//error
//			}
//			t_HeadOfSnapshotsList* Curr_Save_Head = (t_HeadOfSnapshotsList*)malloc(sizeof(t_HeadOfSnapshotsList));
//			Curr_Save_Head->HeadOfSnapshot = CurrHead->HeadOfSnapshot;
//			Curr_Save_Head->sum_of_Dll = CurrHead->sum_of_Dll;
//			Curr_Save_Head->Average_of_MemoryWorkingSetSize = CurrHead->Average_of_MemoryWorkingSetSize;
//			AddHeadToLinkedlist(Curr_Save_Head);
//
//			CurrProcess = CurrHead->HeadOfSnapshot;
//
//			for (int i = 0; i < CurrHead->prosesCountOfEachHead; i++)
//			{
//				read = fread(CurrProcess, sizeof(t_ProcessData), 1, f);
//				if (!read) {  //!write = if its not null its true 1=true    0=Fales
//					err = GetLastError();
//					strE = strerror(err);
//					LogError(strE);
//					//error
//				}
//				t_ProcessData* Curr_save_Process = (t_ProcessData*)malloc(sizeof(t_ProcessData));
//
//				strcpy(Curr_save_Process->ProcessName, CurrProcess->ProcessName);
//				strcpy(Curr_save_Process->TimeOfSnapshot, CurrProcess->TimeOfSnapshot);
//				Curr_save_Process->CounterOfSnapshots = CurrProcess->CounterOfSnapshots;
//				Curr_save_Process->CurrentDll = CurrProcess->CurrentDll;
//				Curr_save_Process->DllCount = CurrProcess->DllCount;
//				Curr_save_Process->MemoryPageFaultCount = CurrProcess->MemoryPageFaultCount;
//				Curr_save_Process->MemoryPagefileUsage = CurrProcess->MemoryPagefileUsage;
//				Curr_save_Process->MemoryQuotaPagedPoolUsage = CurrProcess->MemoryQuotaPagedPoolUsage;
//				Curr_save_Process->MemoryQuotaPeakPagedPoolUsage = CurrProcess->MemoryQuotaPeakPagedPoolUsage;
//				Curr_save_Process->MemoryWorkingSetSize = CurrProcess->MemoryWorkingSetSize;
//				Curr_save_Process->ProcessId = CurrProcess->ProcessId;
//
//				AddProscessToLinkedlist(Curr_save_Process);
//				CurrDll = CurrProcess->CurrentDll;
//
//				for (int i = 0; i < CurrProcess->DllCount; i++)
//				{
//					read = fread(CurrDll, sizeof(t_DllList), 1, f);
//					if (!read) {  //!write = if its not null its true 1=true    0=Fales
//						err = GetLastError();
//						strE = strerror(err);
//						LogError(strE);
//						//error
//					}
//					t_DllList* Curr_save_Dll = (t_DllList*)malloc(sizeof(t_DllList));
//
//					strcpy(Curr_save_Dll->dllName, CurrDll->dllName);
//					AddDllToLinkedlist(Curr_save_Dll);
//					CurrDll = CurrDll->DllListPrev;
//				}
//				DllListHead = NULL;
//				DllListTail = NULL;
//				CurrProcess = CurrProcess->ProcessListNext;
//			}
//			ProcessListHead = NULL;
//			ProcessListTail = NULL;
//			Curr_Save_Head->prosesCountOfEachHead = prosesCount;
//			prosesCount = 0;
//			CurrHead = CurrHead->HeadListNext;
//		}
//
//		fclose(f);
//		free(CurrHead);
//		free(CurrProcess);
//		free(CurrDll);
//	}
//	else
//	{
//		//error
//	}
//}
//
////---------------------------------------Load From File-----------------------------------------------------------
//
//
//
//
//
////---------------------------------------Generate_HTML_Report---------------------------------------------
//
////void AddDllToGenerate_HTML_Report(t_DllListForGenerate_HTML_Report* DllName, t_ProcessData* processName)
////{
////
////t_ProcessData* tempHead = NULL;
////t_ProcessData* tempTail = NULL;
////
////void Swap(t_ProcessData* Adress)
////{
////	if (Adress == NULL || Adress->ProcessListNext == NULL)
////	{
////		return;
////	}
////	t_ProcessData* temp = (t_ProcessData*)malloc(sizeof(t_ProcessData));
////	temp->ProcessListNext = Adress->ProcessListNext->ProcessListNext;
////	temp->ProcessListPrev = Adress->ProcessListNext;
////	Adress->ProcessListNext->ProcessListNext = Adress;
////	Adress->ProcessListNext->ProcessListPrev = Adress->ProcessListPrev;
////	Adress->ProcessListNext = temp->ProcessListNext;
////	Adress->ProcessListPrev = temp->ProcessListPrev;
////	free(temp);
////	if (Adress->ProcessListPrev->ProcessListPrev == NULL)
////	{
////		tempHead = Adress->ProcessListPrev;
////	}
////	else
////	{
////		Adress->ProcessListPrev->ProcessListPrev->ProcessListNext= Adress->ProcessListPrev;
////	}
////	if (Adress->ProcessListNext == NULL)
////	{
////		tempTail = Adress;
////	}
////	else
////	{
////		Adress->ProcessListNext->ProcessListPrev = Adress;
////	}
////}
////
////
////void SortSampleByDllAmount()
////{
////	t_HeadOfSnapshotsList* currentS = HeadListHead;
////	while (currentS)
////	{
////		t_ProcessData* currentP = currentS->HeadOfSnapshot;
////
////		while (currentP)
////		{
////			if (!currentP->ProcessListNext)
////			{
////				tempHead = currentS->HeadOfSnapshot;
////				tempTail = currentP;
////			}
////			currentP = currentP->ProcessListNext;
////		}
////		t_ProcessData* currentPSwap = NULL;
////		int swaps = 1;
////		if (tempHead == NULL)
////		{
////			return;
////		}
////		do
////		{
////			currentPSwap = tempHead;
////			swaps = 0;
////			while (currentPSwap != NULL)
////			{
////				if (currentPSwap->ProcessListNext && currentPSwap->DllCount > currentPSwap->ProcessListNext->DllCount)
////				{
////					Swap(currentPSwap);
////					swaps = 1;
////				}
////				currentPSwap = currentPSwap->ProcessListNext;
////			}
////		} while (swaps);
////		currentS->HeadOfSnapshot = tempHead;
////		tempHead = NULL;
////		tempTail = NULL;
////		currentS = currentS->HeadListNext;
////	}
////}
//
//void Html_SaveIntoFile(char* fileName, char* buff)
//{
//	int err;
//	char* strE;
//
//	FILE* fi = fopen(fileName, "w");
//	if (!fi)
//	{
//		err = GetLastError();
//		strE = strerror(err);
//		LogError(strE);
//		return;
//	}
//	else
//	{
//		fputs(buff, fi);
//	}
//
//
//
//	fclose(fi);
//}
//
//char* ReadAllFile(char* fileName)
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
//// Generate HTML - creating pages (home, sample, Dll)
////--------------------------------------------------------------------
//
//#define HPSEPERATOR "[[sample + Dll tables]]"
//#define SPSEPERATOR "[[processes table]]"
//#define DPSEPERATOR "[[Dll-processes List]]"
//
//void HomePgaeGenerator()
//{
//	t_HeadOfSnapshotsList* currentH = HeadListHead;
//	char* htmlTemplate = ReadAllFile("html_Temp\\T_Index.html"); // get html template a from local folder
//	char HTML_REPLACE[10000];
//	char* found = strstr(htmlTemplate, HPSEPERATOR); // find token adress
//	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * sum_of_Dll));
//
//	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//	newFileSpace[len] = NULL;
//
//	while (currentH != NULL)
//	{
//		// creates sample table rows
//		sprintf(HTML_REPLACE, "<tr><td>%d</td><td><a href=\"../HTML_dist/SnapShot_Page/sample%d.html\">Sample%d</a></td><td>%d</td><td>%d</td><td>%lu</td></tr>", currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->prosesCountOfEachHead, currentH->sum_of_Dll, currentH->Average_of_MemoryWorkingSetSize);
//		strcat(newFileSpace, HTML_REPLACE);
//		len = len + strlen(HTML_REPLACE);
//		newFileSpace[len] = NULL;
//		currentH = currentH->HeadListNext;
//		if (currentH == NULL)
//		{
//			// creates general Dll table header
//			strcpy(HTML_REPLACE, "</table><br><br><h2>General Dll`s List</h2><table><tr><th>Dll Name</th><th>Dll Page</th></tr>");
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//			t_Dic_Dll* currentD = DD_head;
//			unsigned int counter = 0;
//			while (currentD != NULL)
//			{
//				//creates general Dll table rows
//				counter++;
//				sprintf(HTML_REPLACE, "<tr><td>%s</td><td><a href=\"../HTML_dist/DLL_Page/dll%d.html\">Link</a></td></tr>", currentD->Dic_dllName, counter);
//				strcat(newFileSpace, HTML_REPLACE);
//				len = len + strlen(HTML_REPLACE);
//				newFileSpace[len] = NULL;
//				currentD = currentD->DD_next;
//			}
//		}
//	}
//
//	strcat(newFileSpace, found + strlen(HPSEPERATOR)); // adding the rest of the template
//
//	Html_SaveIntoFile("HTML_dist\\NewIndex.html", newFileSpace);
//
//	free(newFileSpace);
//	free(htmlTemplate);
//}
//
//void SamplePgaeGenerator(t_HeadOfSnapshotsList* currentH)
//{
//	int count_error = 0;
//	char* htmlTemplate = ReadAllFile("html_Temp\\T_SnapShotSample.html"); // get html template a from local folder
//	char HTML_REPLACE[10000];
//	char* found = strstr(htmlTemplate, SPSEPERATOR); // find token adress
//	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * currentH->prosesCountOfEachHead) + (strlen(HTML_REPLACE) * currentH->sum_of_Dll));
//
//	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//	newFileSpace[len] = NULL;
//
//	// adding sample page header + processes table header
//	sprintf(HTML_REPLACE, "<h2>Number Of SnapShot: %d</h2><h2>Time Of Snapshot: %s</h2><h2>Process Count: %d</h2><h2>Dll Count: %d</h2><h2>WorkingSet Average: %lu</h2><br><br><h1>Process List</h1><table><tr><th class=\"Head_of_table\">Process Name</th><th class=\"Head_of_table\">Icon_High_M</th><th class=\"Head_of_table\">Process_ID</th><th class=\"Head_of_table\">Memory</th><th class=\"Head_of_table\">Dll_count</th><th class=\"Head_of_table\">Dll List</th></tr>", currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->TimeOfSnapshot, currentH->prosesCountOfEachHead, currentH->sum_of_Dll, currentH->Average_of_MemoryWorkingSetSize);
//	strcat(newFileSpace, HTML_REPLACE);
//	len = len + strlen(HTML_REPLACE);
//	newFileSpace[len] = NULL;
//	t_ProcessData* currentP = currentH->HeadOfSnapshot;
//	while (currentP != NULL)
//	{
//		// creates processes table rows
//		if (currentP == currentH->HighestWorkingSetSize_In_One_p)
//		{
//			//for puting icon
//			sprintf(HTML_REPLACE, "<tr><td>%s</td><td><i class=\"fa-solid fa-triangle-exclamation\"></i><i class=\"fa-solid fa-radiation\"></i><i class=\"fa-solid fa-triangle-exclamation\"></i><i class=\"fa-solid fa-radiation\"></i></td><td>%lu</td><td><select><option>MemoryPageFaultCount=%ul</option><option>MemoryWorkingSetSize=%zu</option><option>MemoryQuotaPagedPoolUsage=%zu</option><option>MemoryQuotaPeakPagedPoolUsage=%zu</option><option>MemoryPagefileUsage=%zu</option></select></td><td>%d</td>", currentP->ProcessName, currentP->ProcessId, currentP->MemoryPageFaultCount, currentP->MemoryWorkingSetSize, currentP->MemoryQuotaPagedPoolUsage, currentP->MemoryQuotaPeakPagedPoolUsage, currentP->MemoryPagefileUsage, currentP->DllCount);
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//		}
//		else
//		{
//			sprintf(HTML_REPLACE, "<tr><td>%s</td><td></td><td>%lu</td><td><select><option>MemoryPageFaultCount=%ul</option><option>MemoryWorkingSetSize=%zu</option><option>MemoryQuotaPagedPoolUsage=%zu</option><option>MemoryQuotaPeakPagedPoolUsage=%zu</option><option>MemoryPagefileUsage=%zu</option></select></td><td>%d</td>", currentP->ProcessName, currentP->ProcessId, currentP->MemoryPageFaultCount, currentP->MemoryWorkingSetSize, currentP->MemoryQuotaPagedPoolUsage, currentP->MemoryQuotaPeakPagedPoolUsage, currentP->MemoryPagefileUsage, currentP->DllCount);
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//		}
//
//		t_DllList* currentD = currentP->CurrentDll;
//		if (currentD == NULL)
//		{
//			strcpy(HTML_REPLACE, "<td>There is No Access To Dll List</td>");
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//		}
//		while (currentD != NULL)
//		{
//			// creates processes Dll select tag
//			if (currentD->DllListNext == NULL)
//			{
//				sprintf(HTML_REPLACE, "<td><select><option>%s</option>", currentD->dllName);
//				strcat(newFileSpace, HTML_REPLACE);
//				len = len + strlen(HTML_REPLACE);
//				newFileSpace[len] = NULL;
//			}
//			else
//			{
//				sprintf(HTML_REPLACE, "<option>%s</option>", currentD->dllName);
//				strcat(newFileSpace, HTML_REPLACE);
//				len = len + strlen(HTML_REPLACE);
//				newFileSpace[len] = NULL;
//			}
//			currentD = currentD->DllListPrev;
//		}
//
//		if (currentD == NULL)
//		{
//			strcpy(HTML_REPLACE, "</select></td></tr>");
//			strcat(newFileSpace, HTML_REPLACE);
//			len = len + strlen(HTML_REPLACE);
//			newFileSpace[len] = NULL;
//			count_error++;
//		}
//
//		if (count_error == currentH->prosesCountOfEachHead)
//		{
//			currentP->ProcessListNext = NULL;
//		}
//
//		currentP = currentP->ProcessListNext;
//	}
//	strcat(newFileSpace, found + strlen(SPSEPERATOR)); // adding the rest of the template
//
//	char pageName[100];
//	sprintf(pageName, "HTML_dist\\SnapShot_Page\\sample%d.html", currentH->HeadOfSnapshot->CounterOfSnapshots);
//	Html_SaveIntoFile(pageName, newFileSpace);
//
//	free(newFileSpace);
//	free(htmlTemplate);
//}
//
//void SamplePgaeGeneratorLoop()
//{
//	t_HeadOfSnapshotsList* currentH = HeadListHead;
//	while (currentH != NULL)
//	{
//		SamplePgaeGenerator(currentH);
//		currentH = currentH->HeadListNext;
//	}
//}
//
//void DllPgaeGenerator(t_Dic_Dll* currentD, unsigned int counter)
//{
//	char* htmlTemplate = ReadAllFile("html_Temp\\T_DllSample.html");  // get html template a from local folder
//	char HTML_REPLACE[10000];
//	char* found = strstr(htmlTemplate, DPSEPERATOR); // find token adress
//	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
//	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * currentD->Dic_counterOfProcess));
//
//	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
//	newFileSpace[len] = NULL;
//
//	// adding Dll page header + Dll users table header
//	sprintf(HTML_REPLACE, "<h1>DLL Name: %s</h1><h2>Number Of Processes: %d</h2><br><br><h3>List Of Processes:</h3><div class = \"OneDll\"><ul>", currentD->Dic_dllName, currentD->Dic_counterOfProcess);
//	strcat(newFileSpace, HTML_REPLACE);
//	len = len + strlen(HTML_REPLACE);
//	newFileSpace[len] = NULL;
//	t_Dic_Process* currentP = currentD->Dic_currProcess;
//	while (currentP != NULL)
//	{
//		// creates Dll users table rows
//		sprintf(HTML_REPLACE, " <li class=\"Dll_li\">%s</li>", currentP->Dic_ProcessName);
//		strcat(newFileSpace, HTML_REPLACE);
//		len = len + strlen(HTML_REPLACE);
//		newFileSpace[len] = NULL;
//		currentP = currentP->DP_next;
//	}
//	strcat(newFileSpace, found + strlen(DPSEPERATOR));  // adding the rest of the template
//
//	char page_Name[100];
//	sprintf(page_Name, "HTML_dist\\DLL_Page\\dll%d.html", counter);
//	Html_SaveIntoFile(page_Name, newFileSpace);
//
//	free(newFileSpace);
//	free(htmlTemplate);
//}
//
//void DllPgaeGeneratorLoop()
//{
//	t_Dic_Dll* currentD = DD_head;
//	unsigned int counter = 0;
//	while (currentD != NULL)
//	{
//		counter++;
//		DllPgaeGenerator(currentD, counter);
//		currentD = currentD->DD_next;
//	}
//}
////---------------------------------------Generate_HTML_Report---------------------------------------------
//
//
//int main()
//{
//
//	//int UserRispon=0;
//
//	//while (UserRispon != 9) {
//	//printf("****MENU****\n~ Type Option Number For Execution ~\n1.Take One SnapShot.\n2.Take 20 Seconds SnapShot.\n3.Start Long SnapShot.\n4.End Long SnapShot.\n5.Generate HTML Report.\n6.Reset Collections.\n7.Save in File.\n8.Load from File.\n9.Quit\ntype here:");
//	//scanf("%d", &UserRispon);
//	//printf("\n\n");
//
//
//	//	switch (UserRispon)
//	//	{
//	//	case 1:
//	//		break;
//	//	case 2:
//	//		break;
//	//	case 3:
//	//		break;
//	//	case 4:
//	//		break;
//	//	case 5:
//	//		break;
//	//	case 6:
//	//		break;
//	//	case 7:
//	//		break;
//	//	case 8:
//	//		break;
//	//	case 9:
//	//		break;
//	//	default:
//	//		printf("invalid number");
//	//		printf("\n\n");
//	//		break;
//	//	}
//	//}
//	////take one snapshot
//	GetProcessesInfo();
//	GetProcessesInfo();
//	//GetProcessesInfo();
//	//GetProcessesInfo();
//
//
//
//	////take 20 secound snapshot
//	GetProcessesInfo_20();
//
//
//	////Start Long SnapShot& End Long SnapShot
//	GetProcessesInfo_Long_SnapShot();
//
//
//	////reset collection functions
//	//ResetCollections();
//
//	////Save in File
//	//GetProcessesInfo();
//	Save_Collections_In_File("project.bin");
//	//GetProcessesInfo();
//	//ResetCollections();
//	//GetProcessesInfo();
//	//Save_Collections_In_File("project.bin");
//	//ResetCollections();
//	//GetProcessesInfo();
//	//Save_Collections_In_File("project.bin");
//	//ResetCollections();
//
//
//	////Load From File
//	Load_Collections_From_File("project.bin");
//
//	////Generate HTML Report
//	DllPgaeGeneratorLoop();
//	SamplePgaeGeneratorLoop();
//	HomePgaeGenerator();
//
//	ResetCollections();
//	return 0;
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
//
////
////
////void HTML_DllPgae()
////{
////	struct Dic_Dll* currentDll = DD_head;
////	unsigned int counter = 0;
////	while (currentDll != NULL)
////	{
////		counter++;
////
////		char* htmlTemplate = ReadAllFile("vishal code\\html_Temp\\T_DllSample.html");  // get html template a from local folder
////		char HTML_REPLACE[10000];
////		char* found = strstr(htmlTemplate, "[[Dll-processes List]]"); // find token adress
////		unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
////		char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * currentDll->Dic_counterOfProcess));
////
////		strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
////		newFileSpace[len] = NULL;
////
////		// adding Dll page header + Dll users table header
////		sprintf(HTML_REPLACE, "<h1>DLL Name: %s</h1><h2>Number Of Processes: %d</h2><br><br><h3>List Of Processes:</h3><div class = \"OneDll\"><ul>", currentDll->Dic_dllName, currentDll->Dic_counterOfProcess);
////		strcat(newFileSpace, HTML_REPLACE);
////		len = len + strlen(HTML_REPLACE);
////		newFileSpace[len] = NULL;
////		struct Dic_Process* currentProcess = currentDll->Dic_currProcess;
////		while (currentProcess != NULL)
////		{
////			// creates Dll process table rows
////			sprintf(HTML_REPLACE, "<li>%s</li>", currentProcess->Dic_ProcessName);
////			strcat(newFileSpace, HTML_REPLACE);
////			len = len + strlen(HTML_REPLACE);
////			newFileSpace[len] = NULL;
////			currentProcess = currentProcess->DP_next;
////		}
////		strcat(newFileSpace, found + strlen("[[Dll - processes List]]"));  // adding the rest of the template
////
////		char pageName[50];
////		sprintf(pageName, "HTML_dist\\dll%d.html", counter);
////		Html_SaveIntoFile(pageName, newFileSpace);
////
////		free(newFileSpace);
////		free(htmlTemplate);
////
////		currentDll = currentDll->DD_next;
////	}
////}