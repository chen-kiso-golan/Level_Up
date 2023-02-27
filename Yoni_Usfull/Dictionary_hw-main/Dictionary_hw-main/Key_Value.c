#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning (disable : 4996)


struct Item {
	int val;
	int key;
	struct Item* Next;
	struct Item* Prev;
};

struct Item* Head = NULL;
struct Item* Tail = NULL;
int Counter = 0;
struct Item* prevItem = NULL;


void push(int key, int val)
{

	struct Item* currentItem;


	currentItem = (struct Item*)malloc(sizeof(struct Item));
	currentItem->val = val;
	currentItem->key = key;
	Counter++;


	if (Head == NULL) {
		Head = currentItem;
		Tail = Head;
		currentItem->Next = NULL;
		currentItem->Prev = NULL;
		prevItem = currentItem;
	}
	else
	{
		Tail = currentItem;
		Tail->Prev = prevItem;
		Tail->Next = NULL;
		prevItem->Next = Tail;
		prevItem = currentItem;
	}
}

struct Item* search(int key)
{

	struct Item* currentItem = Head;
	struct Item* List = Head;

	while (List != NULL)
	{
		List = currentItem;
		currentItem = currentItem->Next;
		if (List->key == key) {
			
			printf("\nthe kay is:%d\nand the value is %d\n",List->key,List->val);
			return List;
		}
	}

}

void Remove(int key)
{
	struct Item* currentItem;
	struct Item* RemoveFromList;
	Counter--;

	RemoveFromList = search(key);
	if (Counter == 1) {
		free(RemoveFromList);
	}
	else {
		if (Head == RemoveFromList) {

			RemoveFromList->Next->Prev = NULL;
			Head = Head->Next;
			free(RemoveFromList);
		}
		else if (Tail == RemoveFromList) {
			
			RemoveFromList->Prev->Next = NULL;
			Tail = Tail->Prev;
			free(RemoveFromList);
		}
		else
		{
			currentItem = RemoveFromList;
			RemoveFromList->Next->Prev= currentItem->Prev;
			RemoveFromList->Prev->Next = currentItem->Next;
			free(RemoveFromList);
		}
	}

}

void PrintList()
{
	struct Item* print_Item = Head;

	while (print_Item != NULL)
	{
		printf("the key number:%d\tand its val:%d\n\n", print_Item->key, print_Item->val);
		print_Item = print_Item->Next;
	}
}


int main()
{
	char user = 1;
	int key;

	while (user != 'E') {
		printf("\nplease enter:\nE-exit\nI-insert key and val to struct\nS-Search a value By key\nP-print the list\nR-To Remove key\n");
		scanf(" %c", &user);

		switch (user) {
		case 'E':
			break;
		case 'I':
			push(2,4);
			push(3,6);
			push(4,8);
			push(5,10);
			push(20,40);

			break;
		case 'S':
			printf("Please enter key number you want to search:");
			scanf("%d", &key);
			search(key);
			break;
		case 'P':
			PrintList();
			break;
		case 'R':
			printf("Please enter key number you want to Remove:\t");
			scanf("%d", &key);
			Remove(key);
			break;
		default:
			printf("try again\n");
			break;
		}
	}

	return 0;

}