#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "HTML4.h"


int err;
char* strE;


//---------------------------------------Generate_HTML_Report---------------------------------------------

void Html_SaveIntoFile(char* fileName, char* buff)
{
	FILE* fi = fopen(fileName, "w");
	if (!fi)
	{
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}
	else
	{
		fputs(buff, fi);
	}



	fclose(fi);
}

char* ReadAllFile(char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}


	// Get the file size
	char* buff = (char*)malloc(1000);
	char* read;
	int fileSize = 0;
	while ((read = fgets(buff, 1000, f)))
	{
		fileSize += strlen(buff);
	}

	free(buff);
	fclose(f);
	fileSize++;
	// alloc space as file size
	buff = (char*)malloc(fileSize);

	f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}
	int readPosition = 0;
	char charToRead;
	while ((charToRead = fgetc(f)) != EOF)
	{
		buff[readPosition] = charToRead;
		readPosition++;
	}
	buff[readPosition] = NULL;

	fclose(f);

	return buff;
}


#define HPSEPERATOR "[[sample + Dll tables]]"
#define SPSEPERATOR "[[processes table]]"
#define DPSEPERATOR "[[Dll-processes List]]"

void HomePgaeGenerator()
{
	t_HeadOfSnapshotsList* currentH = HeadListHead;
	char* htmlTemplate = ReadAllFile("html_Temp\\T_Index.html"); // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, HPSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * sum_of_Dll));
	if (newFileSpace == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	while (currentH != NULL)
	{
		// creates sample table rows
		sprintf(HTML_REPLACE, "<tr><td>%d</td><td><a href=\"../HTML_dist/SnapShot_Page/sample%d.html\">Sample%d</a></td><td>%d</td><td>%d</td><td>%lu</td></tr>", currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->prosesCountOfEachHead, currentH->sum_of_Dll, currentH->Average_of_MemoryWorkingSetSize);
		strcat(newFileSpace, HTML_REPLACE);
		len = len + strlen(HTML_REPLACE);
		newFileSpace[len] = NULL;
		currentH = currentH->HeadListNext;
		if (currentH == NULL)
		{
			// creates general Dll table header
			strcpy(HTML_REPLACE, "</table><br><br><h2>General Dll`s List</h2><table><tr><th>Dll Name</th><th>Dll Page</th></tr>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
			t_Dic_Dll* currentD = DD_head;
			unsigned int counter = 0;
			while (currentD != NULL)
			{
				//creates general Dll table rows
				counter++;
				sprintf(HTML_REPLACE, "<tr><td>%s</td><td><a href=\"../HTML_dist/DLL_Page/dll%d.html\">Link</a></td></tr>", currentD->Dic_dllName, counter);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
				currentD = currentD->DD_next;
			}
		}
	}

	strcat(newFileSpace, found + strlen(HPSEPERATOR)); // adding the rest of the template

	Html_SaveIntoFile("HTML_dist\\NewIndex.html", newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);
}

void SamplePgaeGenerator(t_HeadOfSnapshotsList* currentH)
{
	int count_error = 0;
	char* htmlTemplate = ReadAllFile("html_Temp\\T_SnapShotSample.html"); // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, SPSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * currentH->prosesCountOfEachHead) + (strlen(HTML_REPLACE) * currentH->sum_of_Dll));
	if (newFileSpace == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	// adding sample page header + processes table header
	sprintf(HTML_REPLACE, "<h2>Number Of SnapShot: %d</h2><h2>Time Of Snapshot: %s</h2><h2>Process Count: %d</h2><h2>Dll Count: %d</h2><h2>WorkingSet Average: %lu</h2><br><br><h1>Process List</h1><table><tr><th class=\"Head_of_table\">Process Name</th><th class=\"Head_of_table\">Icon_High_M</th><th class=\"Head_of_table\">Process_ID</th><th class=\"Head_of_table\">Memory</th><th class=\"Head_of_table\">Dll_count</th><th class=\"Head_of_table\">Dll List</th></tr>", currentH->HeadOfSnapshot->CounterOfSnapshots, currentH->HeadOfSnapshot->TimeOfSnapshot, currentH->prosesCountOfEachHead, currentH->sum_of_Dll, currentH->Average_of_MemoryWorkingSetSize);
	strcat(newFileSpace, HTML_REPLACE);
	len = len + strlen(HTML_REPLACE);
	newFileSpace[len] = NULL;
	t_ProcessData* currentP = currentH->HeadOfSnapshot;
	while (currentP != NULL)
	{
		// creates processes table rows
		if (currentP == currentH->HighestWorkingSetSize_In_One_p)
		{
			//for puting icon
			sprintf(HTML_REPLACE, "<tr><td>%s</td><td><i class=\"fa-solid fa-triangle-exclamation\"></i><i class=\"fa-solid fa-radiation\"></i><i class=\"fa-solid fa-triangle-exclamation\"></i><i class=\"fa-solid fa-radiation\"></i></td><td>%lu</td><td><select><option>MemoryPageFaultCount=%ul</option><option>MemoryWorkingSetSize=%zu</option><option>MemoryQuotaPagedPoolUsage=%zu</option><option>MemoryQuotaPeakPagedPoolUsage=%zu</option><option>MemoryPagefileUsage=%zu</option></select></td><td>%d</td>", currentP->ProcessName, currentP->ProcessId, currentP->MemoryPageFaultCount, currentP->MemoryWorkingSetSize, currentP->MemoryQuotaPagedPoolUsage, currentP->MemoryQuotaPeakPagedPoolUsage, currentP->MemoryPagefileUsage, currentP->DllCount);
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}
		else
		{
			sprintf(HTML_REPLACE, "<tr><td>%s</td><td></td><td>%lu</td><td><select><option>MemoryPageFaultCount=%ul</option><option>MemoryWorkingSetSize=%zu</option><option>MemoryQuotaPagedPoolUsage=%zu</option><option>MemoryQuotaPeakPagedPoolUsage=%zu</option><option>MemoryPagefileUsage=%zu</option></select></td><td>%d</td>", currentP->ProcessName, currentP->ProcessId, currentP->MemoryPageFaultCount, currentP->MemoryWorkingSetSize, currentP->MemoryQuotaPagedPoolUsage, currentP->MemoryQuotaPeakPagedPoolUsage, currentP->MemoryPagefileUsage, currentP->DllCount);
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}

		t_DllList* currentD = currentP->CurrentDll;
		if (currentD == NULL)
		{
			strcpy(HTML_REPLACE, "<td>There is No Access To Dll List</td>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}
		while (currentD != NULL)
		{
			// creates processes Dll select tag
			if (currentD->DllListNext == NULL)
			{
				sprintf(HTML_REPLACE, "<td><select><option>%s</option>", currentD->dllName);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
			}
			else
			{
				sprintf(HTML_REPLACE, "<option>%s</option>", currentD->dllName);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
			}
			currentD = currentD->DllListPrev;
		}

		if (currentD == NULL)
		{
			strcpy(HTML_REPLACE, "</select></td></tr>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
			count_error++;
		}

		if (count_error == currentH->prosesCountOfEachHead)
		{
			currentP->ProcessListNext = NULL;
		}

		currentP = currentP->ProcessListNext;
	}
	strcat(newFileSpace, found + strlen(SPSEPERATOR)); // adding the rest of the template

	char pageName[100];
	sprintf(pageName, "HTML_dist\\SnapShot_Page\\sample%d.html", currentH->HeadOfSnapshot->CounterOfSnapshots);
	Html_SaveIntoFile(pageName, newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);
}

void SamplePgaeGeneratorLoop()
{
	t_HeadOfSnapshotsList* currentH = HeadListHead;
	while (currentH != NULL)
	{
		SamplePgaeGenerator(currentH);
		currentH = currentH->HeadListNext;
	}
}

void DllPgaeGenerator(t_Dic_Dll* currentD, unsigned int counter)
{
	char* htmlTemplate = ReadAllFile("html_Temp\\T_DllSample.html");  // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, DPSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * currentD->Dic_counterOfProcess));
	if (newFileSpace == NULL) {
		err = GetLastError();
		strE = strerror(err);
		Error_Log(strE);
		return;
	}

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	// adding Dll page header + Dll users table header
	sprintf(HTML_REPLACE, "<h1>DLL Name: %s</h1><h2>Number Of Processes: %d</h2><br><br><h3>List Of Processes:</h3><div class = \"OneDll\"><ul>", currentD->Dic_dllName, currentD->Dic_counterOfProcess);
	strcat(newFileSpace, HTML_REPLACE);
	len = len + strlen(HTML_REPLACE);
	newFileSpace[len] = NULL;
	t_Dic_Process* currentP = currentD->Dic_currProcess;
	while (currentP != NULL)
	{
		// creates Dll users table rows
		sprintf(HTML_REPLACE, " <li class=\"Dll_li\">%s</li>", currentP->Dic_ProcessName);
		strcat(newFileSpace, HTML_REPLACE);
		len = len + strlen(HTML_REPLACE);
		newFileSpace[len] = NULL;
		currentP = currentP->DP_next;
	}
	strcat(newFileSpace, found + strlen(DPSEPERATOR));  // adding the rest of the template

	char page_Name[100];
	sprintf(page_Name, "HTML_dist\\DLL_Page\\dll%d.html", counter);
	Html_SaveIntoFile(page_Name, newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);
}

void DllPgaeGeneratorLoop()
{
	t_Dic_Dll* currentD = DD_head;
	unsigned int counter = 0;
	while (currentD != NULL)
	{
		counter++;
		DllPgaeGenerator(currentD, counter);
		currentD = currentD->DD_next;
	}
}
//---------------------------------------Generate_HTML_Report---------------------------------------------
