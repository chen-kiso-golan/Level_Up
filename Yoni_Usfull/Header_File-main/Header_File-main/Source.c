#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning (disable : 4996)

#include "Header_struct.h"

#define FILE_NAME "new.bin"
#define Version 1


t_Item* Head = NULL;
t_Item* Tail = NULL;
int Counter = 0;

t_Item* NewItem(int val, int key)
{
	t_Item* ret = (t_Item*)malloc(sizeof(t_Item));

	ret->key = key;
	ret->val = val;
	ret->Next = NULL;
	ret->Prev = NULL;
	Counter++;

	if (Head == NULL) {
		Head = ret;
		Tail = ret;
	}
	else
	{
		ret->Prev = Tail;
		Tail->Next = ret;
		Tail = ret;
	}

	return ret;
}

t_Item* search(int key)
{

	t_Item* currentItem = Head;
	t_Item* List = Head;

	while (List != NULL)
	{
		List = currentItem;
		currentItem = currentItem->Next;
		if (List->key == key) {

			printf("\nthe kay is:%d\nand the value is %d\n", List->key, List->val);
			return List;
		}
		else if (currentItem == NULL) {
			printf("***");
			return;
		}
	}

}

void Update(int key, int val) {

	t_Item* currentItem = Head;
	t_Item* List = Head;

	while (List != NULL)
	{
		List = currentItem;
		currentItem = currentItem->Next;
		if (List->key == key) {

			List->val = val;
			printf("\nthe kay is:%d\nand the new val is %d\n", List->key, List->val);

			return;
		}
		else if (currentItem == NULL) {
			printf("\nthe key is not found!!!\n");
			return;
		}
	}
}

void Remove(int key)
{
	t_Item* currentItem;
	t_Item* RemoveFromList;
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
			RemoveFromList->Next->Prev = currentItem->Prev;
			RemoveFromList->Prev->Next = currentItem->Next;
			free(RemoveFromList);
		}
	}

}

void freeMemory()
{
	t_Item* curr = Head;
	while (curr != NULL)
	{
		curr = curr->Next;
		free(Head);
		Head = curr;
	}

}





int main() {

	t_headerFile fileHeader;
	fileHeader.version = 1;
	fileHeader.serialNum = 2222;
	fileHeader.ItemCount = 0;

char user = 1;
	int key;
	int val;
	FILE* f;



	while (user != 'E') {
		printf("\n\nplease enter:\nE-exit\nA-insert key and val to struct\nF-Search a value By key\nU-Updata key and valu from the last search\nD-To Remove the chozen key\nS-save the list with the header\nL-print the list By name of file");
		scanf(" %c", &user);

		switch (user) {
		case 'E':
			break;
		case 'A':
			printf("Please enter value number and key number you want to add:\n");
			scanf("%d %d",&val, &key);
			NewItem(val, key);
			break;
		case 'F':
			printf("Please enter key number you want to search and print:");
			scanf("%d", &key);
			search(key);
			break;
		case 'U':
			printf("Please enter key number and a new val number you want to add:\n");
			scanf("%d %d", &key, &val);
			Update(key, val);
			break;
		case 'D':
			printf("Please enter key number you want to Remove:\t");
			scanf("%d", &key);
			Remove(key);
			break;
		case 'S':
			f = fopen(FILE_NAME, "w");
			if (!f)
			{
				// error
				return 1;
			}

			int write = fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
			t_Item* curr = Head;
			while (curr->Next != NULL)
			{
				write = fwrite(curr, sizeof(t_Item), 1, f);
				curr = curr->Next;
			}
			fclose(f);

			freeMemory();

			break;
		case 'L':
			f = fopen(FILE_NAME, "r");
			if (!f)
			{
				//error
				return 1;
			}

			t_headerFile headreOfFile;
			int read = fread(&headreOfFile, sizeof(t_headerFile), 1, f);

			for (int i = 0; i < headreOfFile.ItemCount; i++)
			{
				curr = (t_Item*)malloc(sizeof(t_Item));
				read = fread(curr, sizeof(t_Item), 1, f);
				t_Item* addItem = (curr->val, curr->key);
			}
			break;

		default:
			printf("try again\n");
			break;
		}
	}
	return 0;

}