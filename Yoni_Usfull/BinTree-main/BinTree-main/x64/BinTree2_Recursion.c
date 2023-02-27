#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)



//typedef struct Details
//{
//	int age;
//	//char name[100];
//	//char address[100];
//}t_Details;

typedef struct Leaf
{
	int val;
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	//t_Details Details;

}t_Leaf;

t_Leaf* Root = NULL;


typedef struct QueueItem {

	t_Leaf* leaf;
	struct QueueItem* Next;
	struct QueueItem* Prev;

} TQueueItem;

TQueueItem* Queue_Head = NULL;
TQueueItem* Queue_Tail = NULL;
TQueueItem* Queue_Prev = NULL;



void Queue_Push(t_Leaf* leaf)
{
	TQueueItem* currentItem = (TQueueItem*)malloc(sizeof(TQueueItem));

	currentItem->leaf = leaf;

	if (Queue_Head == NULL) {

		Queue_Head = currentItem;
		Queue_Tail = currentItem;
		Queue_Prev = currentItem;
		currentItem->Next = NULL;
		currentItem->Prev = NULL;
	}
	else
	{
		Queue_Tail = currentItem;
		Queue_Tail->Next = NULL;
		Queue_Tail->Prev = Queue_Prev;
		Queue_Prev->Next = Queue_Tail;
		Queue_Prev = currentItem;

	}
}

void AddItem(t_Leaf* curr, int val)
{
	t_Leaf* NewLeaf = (t_Leaf*)malloc(sizeof(t_Leaf));

	NewLeaf->val = val;
	NewLeaf->Left = NULL;
	NewLeaf->Right = NULL;

	if (Root == NULL) {
		Root = NewLeaf;
		NewLeaf->Parent = NULL;
		NewLeaf->level = 0;
	}
	else
	{
		if (curr == NULL) {
			curr = Root;
		}
			if (curr->val < val) {

					if (curr->Right == NULL) {
						//add info
						curr->Right = NewLeaf;
						NewLeaf->Parent = curr;
					}
					else
					{
						AddItem(curr->Right,val);
					}
			}
			else
			{
					if (curr->Left == NULL) {
						//add info
						curr->Left = NewLeaf;
						NewLeaf->Parent = curr;
					}
					else
					{
						AddItem(curr->Left, val);
					}
			}

	}

}


void printTree(t_Leaf* leaf)
{
	if (leaf == NULL) {
		return;
	}
	
	printTree(leaf->Left);

	printf("%d  ", leaf->val);

	printTree(leaf->Right);
}


void printTreeOpozit(t_Leaf* leaf)
{
	if (leaf == NULL) {
		return;
	}

	printTreeOpozit(leaf->Right);

	printf("%d  ", leaf->val);

	printTreeOpozit(leaf->Left);
}

//void BuildTree()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		t_Details* details = (t_Details*)malloc(sizeof(t_Details));
//		details->age = i;
//		AddItem(*details);
//	}
//}
//
//TQueueItem* Queue_Pop()
//{
//	TQueueItem* FreeHead = Queue_Head;
//
//	if (Queue_Head->Prev != NULL) {
//
//		Queue_Head = Queue_Head->Prev;
//		Queue_Head->Next = NULL;
//	}
//
//	return FreeHead;
//}
//
//void Queue_Status()
//{
//	TQueueItem* print_Item = Queue_Head;
//
//	while (print_Item != NULL)
//	{
//		printf("the list form head to tail is:%d\n", print_Item->leaf->Details.age);
//		printf("the list pointer:%p\n\n", print_Item);
//		print_Item = print_Item->Next;
//	}
//	Queue_Head = NULL;
//	Queue_Tail = NULL;
//	Queue_Prev = NULL;
//
//}
//
//void Queue_Clear()
//{
//	TQueueItem* Clear_Item = Queue_Head;
//
//	while (Clear_Item != NULL)
//	{
//		free(Clear_Item);
//		Clear_Item = Clear_Item->Next;
//	}
//
//}
//
//

int main()
{

	AddItem(NULL,3);
	AddItem(NULL, 9);
	AddItem(NULL, 4);
	AddItem(NULL, 2);
	AddItem(NULL, 1);

	printTree(Root);
	printf("\n");
	printTreeOpozit(Root);
}
