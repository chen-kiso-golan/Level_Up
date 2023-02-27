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




void AddItem(int number)
{

	t_ItemNum* currentItem = NULL;
	//t_ItemNum* kodemItem = NULL;

	currentItem = (t_ItemNum*)malloc(sizeof(t_ItemNum));
	currentItem->num = number;

	if (Head == NULL) {
		Head = currentItem;
		Tail = currentItem;
		currentItem->Prev = NULL;
		currentItem->Next = NULL;
	}
	else
	{
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

		if (item == Tail) {
			return;
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
}

void BubleSort()
{
	int Bublecounter = 1;
	t_ItemNum* curr = Head;
	t_ItemNum* CheckItem = Head->Next;

	while (Bublecounter != 0 )
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
