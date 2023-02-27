//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//
//
//typedef struct Details
//{
//	int age;
//	//char name[100];
//	//char address[100];
//}t_Details;
//
//typedef struct Leaf
//{
//	//int val;
//	int level;
//	struct Leaf* Left;
//	struct Leaf* Right;
//	struct Leaf* Parent;
//
//	t_Details Details;
//}t_Leaf;
//
//t_Leaf* Root = NULL;
//
//
//typedef struct QueueItem {
//
//	t_Leaf* leaf;
//	struct QueueItem* Next;
//	struct QueueItem* Prev;
//
//} TQueueItem;
//
//TQueueItem* Queue_Head = NULL;
//TQueueItem* Queue_Tail = NULL;
//TQueueItem* Queue_Prev = NULL;
//
//
//
//void Queue_Push(t_Leaf* leaf)
//{
//	TQueueItem* currentItem = (TQueueItem*)malloc(sizeof(TQueueItem));
//
//	currentItem->leaf = leaf;
//
//	if (Queue_Head == NULL) {
//
//		Queue_Head = currentItem;
//		Queue_Tail = currentItem;
//		Queue_Prev = currentItem;
//		currentItem->Next = NULL;
//		currentItem->Prev = NULL;
//	}
//	else
//	{
//		Queue_Tail = currentItem;
//		Queue_Tail->Next = NULL;
//		Queue_Tail->Prev = Queue_Prev;
//		Queue_Prev->Next = Queue_Tail;
//		Queue_Prev = currentItem;
//
//	}
//}
//
//void AddItem(t_Details Item)
//{
//	t_Leaf* curr = (t_Leaf*)malloc(sizeof(t_Leaf));
//
//	curr->Details = Item;
//	Queue_Push(curr);
//
//	if (Root == NULL) {
//		Root = curr;
//		curr->Left = NULL;
//		curr->Right = NULL;
//		curr->Parent = NULL;
//		curr->level = 0;
//	}
//	else if (Root->Right==NULL)
//	{
//		Root->Right = curr;
//		curr->Right = NULL;
//		curr->Left = NULL;
//		curr->Parent = Root;
//		curr->level = 1;
//		
//	}
//	else if (Root->Left == NULL)
//	{
//		Root->Left= curr;
//		curr->Right = NULL;
//		curr->Left = NULL;
//		curr->Parent = Root;
//		curr->level = 1;
//	
//	}
//}
//
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
//
//
//int main()
//{
//	t_Details d1, d2, d3;
//	d1.age = 10;
//	d2.age = 20;
//	d3.age = 30;
//
//	AddItem(d1);
//	AddItem(d2);
//	AddItem(d3);
//
//	//BuildTree();
//	Queue_Status();
//
//}
//
//
////t_Leaf Leaf;
////Leaf.Details.age = 23;
////strcpy(Leaf.Details.address, "brazil");