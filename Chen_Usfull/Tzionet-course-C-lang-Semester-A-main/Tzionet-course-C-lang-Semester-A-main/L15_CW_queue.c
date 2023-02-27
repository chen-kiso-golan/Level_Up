#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

struct Item {
	int val;
	int val2;
	int id;
	struct Item* Next;
	struct Item* Prev;

};

struct Item* Head = NULL;
struct Item* Tail = NULL;
int Id_Counter = 0;
struct Item* prevItem = NULL;


void push(int val, int val2)
{

	struct Item* currentItem;


	currentItem = (struct Item*)malloc(sizeof(struct Item));
	currentItem->val = val;
	currentItem->val2 = val2;
	Id_Counter++;
	currentItem->id = Id_Counter;

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


void PrintList()
{
	struct Item* print_Item = Tail;

	if (print_Item != NULL)
	{
		while (print_Item != NULL) {
			printf("this is structer number:%d and its vals:%d\t %d\n\n", print_Item->id, print_Item->val, print_Item->val2);
			print_Item = print_Item->Next;
		}
	}
	else if (print_Item == NULL) {
		printf("i have nothing to print\n");
	}
}


struct Item* pop() 
{
	struct Item* FreeTail = Tail;
	if (Tail->Next != NULL) {
		Tail = Tail->Next;
		Tail->Prev = NULL;
	}
		
	return FreeTail;
};

int main()
{
	time_t i = time();
	srand(i);



	int num = 0;

	while (num != 4)
	{
		printf("choose one of the numbers:\n 1 = add two random numbers to head\n 2 = print the list \n 3 = Remove Tail from the list\n 4 = exit the progrem\n");
		scanf("%d", &num);

		if (num == 1) {
			push(rand(), rand());
		}
		else if (num == 2) {
			PrintList();
		}
		else if (num == 3) {
			struct Item* Item = pop();
			printf("I poped the vals: %d  %d\n", Item->val, Item->val2);
			free(Item);
		}
	}

	return 0;
}