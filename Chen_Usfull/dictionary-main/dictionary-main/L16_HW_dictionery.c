#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable:4996)


struct Item {
	int key;
	int val;
	struct Item* Next;
	struct Item* Prev;
};
struct Item* Head = NULL;
struct Item* Tail = NULL;
struct Item* prevItem = NULL;


void Add(int key, int val)
{
	struct Item* currentItem;

	currentItem = (struct Item*)malloc(sizeof(struct Item));
	currentItem->key = key;
	currentItem->val = val;

	if (Head == NULL) {
		Head = currentItem;
		Tail = Head;
		currentItem->Next = NULL;
		currentItem->Prev = NULL;
		prevItem = currentItem;
	}
	else
	{
		Head = currentItem;
		Head->Prev = prevItem;
		Head->Next = NULL;
		prevItem->Next = Head;
		prevItem = currentItem;
	}
}

struct Item* Search (key) {

	struct Item* current = Head;
	while (current->key != key) {
		current = current->Prev;
	}
	return current;
}

void Remove(key) {

	struct Item* RemoveItem = Search(key);
	if (RemoveItem != Head && RemoveItem != Tail) {
		RemoveItem->Prev->Next = RemoveItem->Next;
		RemoveItem->Next->Prev = RemoveItem->Prev;
		free(RemoveItem);
	}
	else if (RemoveItem == Head) {
		RemoveItem->Prev->Next = NULL;
		Head = RemoveItem->Prev;
		free(RemoveItem);
	}
	else if (RemoveItem == Tail) {
		RemoveItem->Next->Prev = NULL;
		Tail = RemoveItem->Next;
		free(RemoveItem);
	}
	
}

void PrintList()
{
	struct Item* print_Item = Tail;

	while (print_Item != NULL) {
		printf("key: %d  val: %d\n", print_Item->key, print_Item->val);
		print_Item = print_Item->Next;
	}
}


int main() {

	char user = 1;
	
	while (user != 'E') {
			printf("please enter:\nE-exit\nI-insert new key and val\nS-search for a key\nL-print all\n");
			scanf(" %c", &user);
	
			switch (user) {
			case 'E':
				break;
			case 'I':
				int keyUser;
				int valUser;
				printf("enter a key:\n");
				scanf("%d", &keyUser);
				printf("enter a val:\n");
				scanf("%d", &valUser);
				Add(keyUser, valUser);
				break;
			case 'S':
				int keyUser1;
				printf("enter a key you want to find:\n");
				scanf("%d", &keyUser1);
				struct Item* UserKey = Search(keyUser1);
				printf("the val of your key is: %d\n", UserKey->val);
				break;
			case 'L':
				PrintList();
				break;
			default:
				printf("try again\n");
				break;
		} 
			
	}


	return 0;
}