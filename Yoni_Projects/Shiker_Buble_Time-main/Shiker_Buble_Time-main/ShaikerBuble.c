#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)


typedef struct ItemNum
{
	int num;
	int stop;
	struct ItemNum* Next;
	struct ItemNum* Prev;
}t_ItemNum;

t_ItemNum* Tail = NULL;
t_ItemNum* Head = NULL;



void Log(char massage[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;

	timeinfo = localtime(&t);
	char str[100];
	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);

	FILE* f = fopen("check_time.log", "a");
	fputs("\n\n", f);
	fputs(str, f);
	fputs("\n\n", f);


	fclose(f);
}

void LogError(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", message);
	Log(newMessage);
}

void EventLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", message);
	Log(newMessage);
}

void EventLogval(char msg[100], int val)
{
	char str[100];
	sprintf(str, "Item val %d : %s", val, msg);
	Log(str);
}


void AddItem(int number)
{

	t_ItemNum* currentItem = NULL;


	currentItem = (t_ItemNum*)malloc(sizeof(t_ItemNum));
	currentItem->num = number;
	currentItem->stop = 1;

	if (Head == NULL) {
		//EventLogval("added the First number to the list", number);
		Head = currentItem;
		Tail = currentItem;
		currentItem->Prev = NULL;
		currentItem->Next = NULL;
	}
	else
	{
		//EventLogval("added a number to the list", number);
		currentItem->Next = NULL;
		currentItem->Prev = Tail;
		Tail->Next = currentItem;
		Tail = currentItem;
	}
}

void Printlist()
{
	int counter = 0;
	t_ItemNum* currentItem1 = Head;
	t_ItemNum* print_Item = Head;

	while (print_Item->Next != NULL)
	{
		print_Item = currentItem1;
		currentItem1 = currentItem1->Next;
		counter++;
		printf("#%d-%d\n", counter, print_Item->num);
	}
	printf("\n\n");
}

void Replace(t_ItemNum* item)
{
	if (item == NULL) {
		EventLogval("No need to swap", 0);
		return;
	}

	t_ItemNum* CopyList = NULL;
	t_ItemNum* NextItem;
	t_ItemNum* List;

	CopyList = (t_ItemNum*)malloc(sizeof(t_ItemNum));

	List = item;
	CopyList->Next = item->Next;
	CopyList->Prev = item->Prev;
	NextItem = item->Next;


	if (item == Tail) {
		EventLogval("No need to swap", item->num);
		return;
	}
	else if (List == Head && NextItem == Tail)
	{
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		Tail = List;
		Head = NextItem;
	}
	else if (item == Head) {
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		List->Next->Prev = List;
		Head = NextItem;
	}
	else if (item == Tail->Prev)
	{
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		NextItem->Prev->Next = NextItem;
		if (Tail == NextItem) {
			Tail = List;
		}
	}
	else
	{
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		NextItem->Prev->Next = NextItem;
		List->Next->Prev = List;

	}
	free(CopyList);
}

void Shaiker_BubleSort()
{

	int Bublecounter = 1;

	t_ItemNum* curr = Head;

	if (!curr/* !curr = curr!=NULL*/) {
		EventLog("the list is empty");
		return;
	}
	t_ItemNum* CheckItem = Head->Next;

	EventLog("Start sorting");
	while (Bublecounter != 0)
	{
		Bublecounter = 0;
		curr = Head;
		CheckItem = Head->Next;

		while (CheckItem != NULL)
		{
			if (curr->num > CheckItem->num) {
				Replace(curr);
				CheckItem = curr->Next;
				Bublecounter++;
			}
			else
			{
				curr = curr->Next;
				CheckItem = CheckItem->Next;
			}
		}
			CheckItem = curr->Prev;

		while (CheckItem != NULL)
		{

			if (curr->num < CheckItem->num) {
				Replace(CheckItem);
				CheckItem = curr->Prev;
				Bublecounter++;
			}
			else
			{
				curr = curr->Prev;
				CheckItem = CheckItem->Prev;
			}
		}
	}
	EventLog("End sorting");

}

void New_Shaiker_BubleSort()
{

	int Bublecounter = 1;

	t_ItemNum* curr = Head;

	if (!curr/* !curr = curr!=NULL*/) {
		EventLog("the list is empty");
		return;
	}
	t_ItemNum* CheckItem = Head->Next;


	EventLog("Start sorting");
	while (Bublecounter != 0)
	{
		
		curr = Head;
		CheckItem = Head->Next;

		while (Bublecounter != 0)
		{
			Bublecounter = 0;

			while (CheckItem != NULL && curr->Next->stop == 1)
			{
				if (curr->num > CheckItem->num) {
					Replace(curr);
					CheckItem = curr->Next;
					Bublecounter++;
				}
				else
				{
					curr = curr->Next;
					CheckItem = CheckItem->Next;
				}
			}
			curr->stop = 0;
			curr = curr->Prev;
			CheckItem = curr->Prev;
	

			while (CheckItem != NULL && curr->Prev->stop == 1)
			{
				if (curr->num < CheckItem->num) {
					Replace(CheckItem);
					CheckItem = curr->Prev;
					Bublecounter++;
				}
				else
				{
					curr = curr->Prev;
					CheckItem = CheckItem->Prev;
				}
			}
			curr->stop = 0;
			curr = curr->Next;
			CheckItem = curr->Next;
			
		}
	}
	EventLog("End sorting");

}

void New_Best_Shaiker_BubleSort()
{

	int Bublecounter = 1;

	t_ItemNum* curr = Head;

	if (!curr/* !curr = curr!=NULL*/) {
		EventLog("the list is empty");
		return;
	}
	t_ItemNum* CheckItem = Head->Next;

	t_ItemNum* CopyHead= NULL;
	t_ItemNum* CopyTail=NULL;

	EventLog("Start sorting");
	while (Bublecounter != 0)
	{
		curr = Head;
		CheckItem = Head->Next;

		while (Bublecounter != 0)
		{
			Bublecounter = 0;

			while (CheckItem != NULL && curr->Next!=CopyTail)
			{
				if (curr->num > CheckItem->num) {
					Replace(curr);
					CheckItem = curr->Next;
					Bublecounter++;
				}
				else
				{
					curr = curr->Next;
					CheckItem = CheckItem->Next;
				}
			}
			CopyTail = curr;
			curr = curr->Prev;
			CheckItem = curr->Prev;


			while (CheckItem != NULL && curr->Prev != CopyHead)
			{
				if (curr->num < CheckItem->num) {
					Replace(CheckItem);
					CheckItem = curr->Prev;
					Bublecounter++;
				}
				else
				{
					curr = curr->Prev;
					CheckItem = CheckItem->Prev;
				}
			}
			CopyHead = curr;
			curr = curr->Next;
			CheckItem = curr->Next;

		}
	}
	EventLog("End sorting");

}


int main()
{
	time_t j = time(NULL);
	srand(j);


	for (int i = 0; i < 10000; i++)
	{
	AddItem(rand()%1000);
	}
	Printlist();

	
	New_Best_Shaiker_BubleSort();

	Printlist();

	return 0;
}
