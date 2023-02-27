#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "html.h"


//***creating html from the data: -----------------------------------------------------------------------------------

int SaveHTMLIntoFile(char* fileName, char* buff)
{
	FILE* fi = fopen(fileName, "w");
	if (!fi)
	{
		return 0;
	}

	fputs(buff, fi);

	fclose(fi);
}

char* ReadAllHTMLFile(char* fileName)
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

#define HomePageSEPERATOR "[[start writing your snapshots and Dlls tables]]"
#define SnapsotPageSEPERATOR "[[start writing your snapshot's process table]]"
#define DllPageSEPERATOR "[[start writing your Dll processes table]]"

void HTML_HomePgae()
{
	struct HeadOfSnapshotsList* currentHead = HeadListHead;
	char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_HomePage.html"); // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, HomePageSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * SumOfDll));

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	while (currentHead != NULL)
	{
		// creates sample table rows
		sprintf(HTML_REPLACE, "<tr><td>%d</td><td><a href=\"NewSnapshotPage%d.html\">Snapshot Number %d</a></td><td>%d</td><td>%d</td><td>%lu</td></tr>", currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->CounterOfProcess, currentHead->SumOfDll, currentHead->AverageOfMemoryWorkingSet);
		strcat(newFileSpace, HTML_REPLACE);
		len = len + strlen(HTML_REPLACE);
		newFileSpace[len] = NULL;
		currentHead = currentHead->HeadListNext;
		if (currentHead == NULL)
		{
			// creates general Dll table header
			strcpy(HTML_REPLACE, "</table><br><br><h2>General Dll`s List</h2><table><tr><th>Dll Name</th><th>Dll Page</th></tr>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
			struct Dic_Dll* currentDll = DD_head;
			unsigned int counter = 0;
			while (currentDll != NULL)
			{
				//creates general Dll table rows
				counter++;
				sprintf(HTML_REPLACE, "<tr><td>%s</td><td><a href=\"newHTML/newDllPage%d.html\">Dll Number %d</a></td></tr>", currentDll->Dic_dllName, counter, counter);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
				currentDll = currentDll->DD_next;
			}
		}
	}

	strcat(newFileSpace, found + strlen(HomePageSEPERATOR)); // adding the rest of the template

	SaveHTMLIntoFile("myHTML\\NewHomePage.html", newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);
}

void HTML_SnapshotPage(struct HeadOfSnapshotsList* currentHead)
{
	int errorCount = 0;
	char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_SnapshotPage.html"); // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, SnapsotPageSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	///???
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * CounterOfSnapshots) + (strlen(HTML_REPLACE) * currentHead->CounterOfProcess) + (strlen(HTML_REPLACE) * currentHead->SumOfDll));

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	// adding snapshot page header + processes table header
	sprintf(HTML_REPLACE, "<h2>Snapshot Number: %d</h2><h2>Snapshot Time: %s</h2><br><br><h1>Process List</h1><table><tr><th>Process ID</th><th>Process Name</th><th>Memory Page Fault Count</th><th>Memory Working Set Size</th><th>Memory Quota Paged Pool Usage</th><th>Memory Quota Peak Paged Pool Usage</th><th>Memory Page file Usage</th><th>Dll count</th><th>Dll List</th></tr>", currentHead->HeadOfSnapshot->CounterOfSnapshots, currentHead->HeadOfSnapshot->TimeOfSnapshot);
	strcat(newFileSpace, HTML_REPLACE);
	len = len + strlen(HTML_REPLACE);
	newFileSpace[len] = NULL;
	struct OneProcessInfo* currentProcess = currentHead->HeadOfSnapshot;
	while (currentProcess != NULL)
	{
		// creates processes table rows
		if (currentProcess == currentHead->HighestWorkingsetProcess)
		{
			//for puting icon
			sprintf(HTML_REPLACE, "<tr><td>%lu</td><td>%s</td><td>%u</td><td>%lu <i class=\"fa-solid fa-triangle-exclamation\"></i></td><td>%lu</td><td>%lu</td><td>%lu</td><td>%d</td>", currentProcess->ProcessId, currentProcess->ProcessName, currentProcess->MemoryPageFaultCount, currentProcess->MemoryWorkingSetSize, currentProcess->MemoryQuotaPagedPoolUsage, currentProcess->MemoryQuotaPeakPagedPoolUsage, currentProcess->MemoryPagefileUsage, currentProcess->CounterOfDll);
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}
		else
		{
			sprintf(HTML_REPLACE, "<tr><td>%lu</td><td>%s</td><td>%u</td><td>%lu</td><td>%lu</td><td>%lu</td><td>%lu</td><td>%d</td>", currentProcess->ProcessId, currentProcess->ProcessName, currentProcess->MemoryPageFaultCount, currentProcess->MemoryWorkingSetSize, currentProcess->MemoryQuotaPagedPoolUsage, currentProcess->MemoryQuotaPeakPagedPoolUsage, currentProcess->MemoryPagefileUsage, currentProcess->CounterOfDll);
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}

		struct DllList* currentDll = currentProcess->CurrentDll;
		if (currentDll == NULL)
		{
			strcpy(HTML_REPLACE, "<td>No Dlls were found</td>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
		}
		while (currentDll != NULL)
		{
			// creates processes Dll select tag for the first dll on the list
			if (currentDll->DllListNext == NULL)
			{
				sprintf(HTML_REPLACE, "<td><select><option>%s</option>", currentDll->dllName);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
			}
			else
			{
				sprintf(HTML_REPLACE, "<option>%s</option>", currentDll->dllName);
				strcat(newFileSpace, HTML_REPLACE);
				len = len + strlen(HTML_REPLACE);
				newFileSpace[len] = NULL;
			}
			currentDll = currentDll->DllListPrev;
		}

		if (currentDll == NULL) {
			strcpy(HTML_REPLACE, "</select></td></tr>");
			strcat(newFileSpace, HTML_REPLACE);
			len = len + strlen(HTML_REPLACE);
			newFileSpace[len] = NULL;
			errorCount++;
		}

		if (errorCount == currentHead->CounterOfProcess)
		{
			currentProcess->ProcessListNext = NULL;
		}

		currentProcess = currentProcess->ProcessListNext;
	}
	strcat(newFileSpace, found + strlen(SnapsotPageSEPERATOR)); // adding the rest of the template

	char pageName[100];
	sprintf(pageName, "myHTML\\NewSnapshotPage%d.html", currentHead->HeadOfSnapshot->CounterOfSnapshots);
	SaveHTMLIntoFile(pageName, newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);

}

void HTML_SnapshotPageLoop()
{
	struct HeadOfSnapshotsList* currentHead = HeadListHead;
	while (currentHead != NULL)
	{
		HTML_SnapshotPage(currentHead);
		currentHead = currentHead->HeadListNext;
	}
}

void HTML_DllPgae(struct Dic_Dll* currentDll, unsigned int counter)
{

	char* htmlTemplate = ReadAllHTMLFile("myHTML\\ProjectA_DllPage.html");  // get html template a from local folder
	char HTML_REPLACE[10000];
	char* found = strstr(htmlTemplate, DllPageSEPERATOR); // find token adress
	unsigned long len = found - htmlTemplate; // found (bigger adress) - htmlTemplate (smaller adress)
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate) + (strlen(HTML_REPLACE) * currentDll->Dic_counterOfProcess));

	strncpy(newFileSpace, htmlTemplate, len); // adding template till token position 
	newFileSpace[len] = NULL;

	// adding Dll page header + Dll users table header
	sprintf(HTML_REPLACE, "<h1>DLL Name: %s</h1><h2>Number Of Processes: %d</h2><br><br><h3>List Of Processes:</h3><div class = \"OneDll\"><ul>", currentDll->Dic_dllName, currentDll->Dic_counterOfProcess);
	strcat(newFileSpace, HTML_REPLACE);
	len = len + strlen(HTML_REPLACE);
	newFileSpace[len] = NULL;
	struct Dic_Process* currentProcess = currentDll->Dic_currProcess;
	while (currentProcess != NULL)
	{
		// creates Dll process table rows
		sprintf(HTML_REPLACE, "<li>%s</li>", currentProcess->Dic_ProcessName);
		strcat(newFileSpace, HTML_REPLACE);
		len = len + strlen(HTML_REPLACE);
		newFileSpace[len] = NULL;
		currentProcess = currentProcess->DP_next;
	}
	strcat(newFileSpace, found + strlen(DllPageSEPERATOR));  // adding the rest of the template

	char pageName[50];
	sprintf(pageName, "myHTML\\newHTML\\newDllPage%d.html", counter);
	SaveHTMLIntoFile(pageName, newFileSpace);

	free(newFileSpace);
	free(htmlTemplate);
}

void HTML_DllPgaeLoop()
{
	struct Dic_Dll* currentDll = DD_head;
	unsigned int counter = 0;
	while (currentDll != NULL)
	{
		counter++;
		HTML_DllPgae(currentDll, counter);
		currentDll = currentDll->DD_next;
	}
}

void GenerateHtmlReport() {

	HTML_HomePgae();
	HTML_SnapshotPageLoop();
	HTML_DllPgaeLoop();
}