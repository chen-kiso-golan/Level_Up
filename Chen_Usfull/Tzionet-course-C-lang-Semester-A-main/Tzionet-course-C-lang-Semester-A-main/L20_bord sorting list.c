//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#pragma warning (disable : 4996)
//
//typedef struct ItemNum {
//	int num;
//	struct ItemNum* Next;
//	struct ItemNum* Prev;
//}t_ItemNum;
//
//t_ItemNum* Head = NULL;
//t_ItemNum* Tail = NULL;
//t_ItemNum* prevItem;
//
//void Add(int num)
//{
//	t_ItemNum* currentItem;
//
//	currentItem = (t_ItemNum*)malloc(sizeof(t_ItemNum));
//	currentItem->num = num;
//
//	if (Head == NULL) {
//		Head = currentItem;
//		Tail = Head;
//		currentItem->Next = NULL;
//		currentItem->Prev = NULL;
//		prevItem = currentItem;
//	}
//	else
//	{
//
//		Head = currentItem;
//		Head->Prev = prevItem;
//		Head->Next = NULL;
//		prevItem->Next = Head;
//		prevItem = currentItem;
//	}
//}
//
//
//void PrintList()
//{
//	t_ItemNum* print_Item = Tail;
//
//	if (print_Item != NULL)
//	{
//		while (print_Item != NULL) {
//			printf("the structer number is: %d\n", print_Item->num);
//			print_Item = print_Item->Next;
//		}
//	}
//	else if (print_Item == NULL) {
//		printf("the list has ended.\n");
//	}
//
//
//int main() {
//
//
//
//
//
//
//
//
//	return 0;
//}