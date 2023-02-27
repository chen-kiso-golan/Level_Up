//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#include <time.h>
//#pragma warning(disable:4996)
//
//struct Item
//{
//	int val;
//	struct Item* Next;
//	struct Item* Prev;
//};
//
//struct Item* head = NULL;
//struct Item* tail = NULL;
//
//
////task 2
//void GenerateList()
//{
//
//	time_t j = time();
//	srand(j);
//	
//
//	struct Item* currentItem;
//	struct Item* kodemItem = NULL;
//
//	for (int i = 0; i < 10; i++)
//	{
//		currentItem = (struct Item*)malloc(sizeof(struct Item) * 1);
//		currentItem->val = rand();
//
//		if (head == NULL) {
//			head = currentItem;
//			tail = currentItem;
//			currentItem->Prev = NULL;
//			currentItem->Next = NULL;
//		}
//		else
//		{
//			currentItem->Next = NULL;
//			currentItem->Prev = kodemItem;
//
//			kodemItem->Next = currentItem;
//		}
//
//		kodemItem = currentItem;
//	}
//	tail = currentItem;
//}
//
//
// //task 3
//void GenerateXList(int x)
//{
//
//	time_t j = time();
//	srand(j);
//	
//
//	struct Item* currentItem = NULL;
//		
//	struct Item* kodemItem = NULL;
//
//	for (int i = 0; i < x; i++)
//	{
//		currentItem = (struct Item*)malloc(sizeof(struct Item) * 1);
//		currentItem->val = rand();
//
//		if (head == NULL) {
//			head = currentItem;
//			tail = currentItem;
//			currentItem->Prev = NULL;
//			currentItem->Next = NULL;
//		}
//		else
//		{
//			currentItem->Next = NULL;
//			currentItem->Prev = kodemItem;
//
//			kodemItem->Next = currentItem;
//		}
//
//		kodemItem = currentItem;
//	}
//	tail = currentItem;
//}
//
//
//// task 4
//void Printlist()
//{
//	int counter = 0;
//		struct Item* currentItem = head;
//		struct Item* print_Item = head;
//	
//		while (print_Item->Next != NULL)
//		{
//			print_Item = currentItem;
//			currentItem = currentItem->Next;
//			counter++;
//			printf("%d-%d\n",counter, print_Item->val);
//		}
//}
// 
//// task 5
//void freelist()
//{
//
//	struct Item* currentItem = head;
//	struct Item* Free_Item = head;
//
//	while (Free_Item->Next != NULL)
//	{
//		Free_Item = currentItem;
//		currentItem = currentItem->Next;
//		free(Free_Item);
//	}
//}
//
//
////task6
//struct Item* Findval(int Findval)
//{
//	struct Item* ret = NULL;
//	struct Item* currentItem = head;
//
//		while (currentItem != NULL)
//		{
//			if (currentItem->val == Findval) {
//				ret = currentItem;
//			}
//			currentItem = currentItem->Next;
//		}
//	return ret;
//}
//
////task7
//struct Item* ChangeVal(int oldVal,int newVal)
//{
//
//	struct Item* ret = Findval(oldVal);
//	if (ret != NULL)
//	{
//		 return ret->val = newVal;
//	}
//}
//
//
////task8
//void ResetList()
//{
//	if (head != NULL) {
//		 freelist();
//		 head = NULL;
//		 tail = NULL;
//	}
//}
//
//
////task9
//struct Item* InsertNewItem()
//{
//	int num;
//
//
//	struct Item* currentItem;
//	struct Item* HabaItem=NULL;
//	struct Item* kodemItem = NULL;
//
//	for (int i = 0; i < 5; i++)
//	{
//
//	printf("please enter value to structur");
//	scanf("%d", num);
//
//		currentItem = (struct Item*)malloc(sizeof(struct Item) * 1);
//		currentItem->val = num;
//		HabaItem = head;
//
//
//		while (currentItem != NULL)
//		{
//			if (head == NULL) {
//				head = currentItem;
//				tail = currentItem;
//				currentItem->Prev = NULL;
//				currentItem->Next = NULL;
//			}
//			else if(currentItem->val > HabaItem->val){
//
//				kodemItem = HabaItem;
//				HabaItem = HabaItem->Next;
//				
//		
//
//				currentItem->Next = NULL;
//				currentItem->Prev = kodemItem;
//
//				kodemItem->Next = currentItem;
//			}
//
//		}
//		kodemItem = currentItem;
//	}
//	tail = currentItem;
//}
//
//
//
//
//
//int main()
//{
//	
//	
//
//
//
//	return 0;
//}
//
