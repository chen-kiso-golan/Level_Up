#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)


typedef struct ItemNum
{
	int num;
	struct ItemNum* Next;
	struct ItemNum* Prev;
}t_ItemNum;

t_ItemNum* Tail = NULL;
t_ItemNum* Head = NULL;

void Log(char msg[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str[100];
	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, msg);

	FILE* f = fopen("Yoni_log.log", "a");
	fputs("\n\n", f);
	fputs(str, f);
	fputs("\n\n", f);

	fclose(f);
}

void LogError(char msg[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", msg);
	Log(newMessage);
}

void LogEvent(char msg[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", msg);
	Log(newMessage);
}

void LogEventNum(char msg[100], int num) {
	char newMessage[100];
	sprintf(newMessage, "item num %d : %s", num, msg);
	Log(newMessage);
}

void AddItem(int number)
{

	t_ItemNum* currentItem = NULL;
	currentItem = (t_ItemNum*)malloc(sizeof(t_ItemNum));
	currentItem->num = number;
	LogEventNum("create new item", number);

	if (Head == NULL) {
		LogEventNum("list is strted now", number);
		Head = currentItem;
		Tail = currentItem;
		currentItem->Prev = NULL;
		currentItem->Next = NULL;
	}
	else
	{
		LogEventNum("list is strted now", number);
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
	t_ItemNum* CopyList = NULL;
	t_ItemNum* NextItem;
	t_ItemNum* List;

	CopyList = (t_ItemNum*)malloc(sizeof(t_ItemNum));

	List = item;
	CopyList->Next = item->Next;
	CopyList->Prev = item->Prev;
	NextItem = item->Next;
	
	if (item == NULL) {
		LogEventNum("no need to swap, no items in list", 0);
		return;
	}
	if (item == Tail) {
		LogEventNum("no need to swap, only one item in list or the item is the tail", item->num);
		return;
	}
	else if (List == Head && NextItem == Tail) {
		LogEventNum("made a swap, only two items in list", item->num);
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		Tail = List;
		Head = NextItem;
	}
	else if (item == Head) {
		LogEventNum("made a swap, the item was the head of the list", item->num);
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		List->Next->Prev = List;
		Head = NextItem;
	}
	else if (item == Tail->Prev)
	{
		LogEventNum("made a swap, the item was before the tail of the list", item->num);
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
		LogEventNum("made a swap, the item was in the midel of the list", item->num);
		List->Prev = NextItem;
		List->Next = NextItem->Next;
		NextItem->Prev = CopyList->Prev;
		NextItem->Next = List;
		NextItem->Prev->Next = NextItem;
		List->Next->Prev = List;
	}
}

void Replace2(t_ItemNum* item)
{
	t_ItemNum* CopyList = NULL;
	t_ItemNum* NextItem;
	t_ItemNum* List;
	CopyList = (t_ItemNum*)malloc(sizeof(t_ItemNum));

	List = item;
	CopyList->Next = item->Next;
	CopyList->Prev = item->Prev;
	NextItem = item->Next;

	List->Prev = NextItem;
	List->Next = NextItem->Next;
	NextItem->Prev = CopyList->Prev;
	NextItem->Next = List; 

	if (item == NULL) {
		LogEventNum("no need to swap, no items in list", 0);
		return;
	}
	if (item == Tail) {
		LogEventNum("no need to swap, only one item in list or the item is the tail", item->num);
		return;
	}
	else if (List == Head && NextItem == Tail) {
		LogEventNum("made a swap, only two items in list", item->num);
		Tail = List;
		Head = NextItem;
	}
	else if (item == Head) {
		LogEventNum("made a swap, the item was the head of the list", item->num);
		List->Next->Prev = List;
		Head = NextItem;
	}
	else if (item == Tail->Prev)
	{
		LogEventNum("made a swap, the item was before the tail of the list", item->num);
		NextItem->Prev->Next = NextItem;
		if (Tail == NextItem) {
			Tail = List;
		}
	}
	else
	{
		LogEventNum("made a swap, the item was in the midel of the list", item->num);
		NextItem->Prev->Next = NextItem;
		List->Next->Prev = List;
	}
}

void BubleSort()
{
	int Bublecounter = 1;
	t_ItemNum* curr = Head;
	t_ItemNum* CheckItem = Head->Next;

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
	}

}


int main()
{


	AddItem(7);
	AddItem(9);
	AddItem(22);
	AddItem(1);
	AddItem(100);
	AddItem(13);
	AddItem(36);
	AddItem(97);
	AddItem(2);
	AddItem(0);
	Printlist();


	BubleSort();
	Printlist();

	return 0;
}
