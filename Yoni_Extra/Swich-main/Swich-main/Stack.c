//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//
//#pragma warning (disable : 4996)
//
//struct Item {
//	int val;
//	int val2;
//	int id;
//	struct Item* Next;
//	struct Item* Prev;
//
//};
//
//struct Item* Head = NULL;
//struct Item* Tail = NULL;
//int Id_Counter = 0;
//struct Item* prevItem = NULL;
//
//
//void push(int val, int val2)
//{
//
//	struct Item* currentItem;
//
//
//	currentItem = (struct Item*)malloc(sizeof(struct Item));
//	currentItem->val = val;
//	currentItem->val2 = val2;
//	Id_Counter++;
//	currentItem->id = Id_Counter;
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
//	struct Item* print_Item = Tail;
//
//	while (print_Item != NULL)
//	{
//		printf("this is structer number:%d and its vals:%d\t %d\n\n", print_Item->id, print_Item->val, print_Item->val2);
//		print_Item = print_Item->Next;
//	}
//}
//
//
//struct Item* pop()
//{
//	struct Item* FreeHead = Head;
//
//	if (Head != NULL) {
//
//		Head = Head->Prev;
//		Head->Next = NULL;
//		prevItem = Head;
//	}
//
//	return FreeHead;
//
//};
//
//
////#define use_if
//
//int main()
//{
//	time_t i = time();
//	srand(i);
//
//
//#ifdef use_if
//
//	char num = 0;
//
//	while (num != 4)
//	{
//		printf("choose one of the numbers:\n 1 = add two random numbers to head\n 2 = print the list \n 3 = Remove Tail from the list\n 4 = exit the progrem\n");
//		//num = getch();
//		scanf(" %d", &num);
//
//		if (num == 1) {
//			push(rand(), rand());
//		}
//		else if (num == 2) {
//			PrintList();
//		}
//		else if (num == 3) {
//			struct Item* Item = pop();
//			printf("%d %d\n\n\n", Item->val, Item->val2);
//			free(Item);
//			PrintList();
//		}
//	}
//#else
//
//	struct Item* Item = pop();
//
//	char user = 1;
//
//	while (user != 'E') {
//		printf("\n\nplease enter:\nE-exit\nI-insert 2 random vals\nP-pop and print the poped vals\nL-print all\nB-insert 20 vals\nZ-pop 10 vals and prints their sum\n");
//		scanf(" %c", &user);
//
//		switch (user) {
//		case 'E':
//			break;
//		case 'I':
//			push(rand() % 100 , rand() % 100);
//			break;
//		case 'P':
//			Item = pop();
//			printf("\nI poped the vals: %d  %d\n", Item->val, Item->val2);
//			//free(Item);
//			break;
//		case 'L':
//			PrintList();
//			break;
//		case 'B': 
//			for (int i = 0; i < 20; i++)
//		{
//			push(rand() % 100, rand() % 100);
//		}
//			break;
//		case 'Z':
//			int sum1 = 0;
//			int sum2 = 0;
//
//			for (int i = 0; i < 10; i++) {	
//				Item = pop();
//				printf("I poped the vals: %d  %d\n", Item->val, Item->val2);
//						sum1 = sum1 + Item->val;
//						sum2 = sum2 + Item->val2;
//						free(Item);
//			}
//				printf("\nthe val sum1 is: %d\nthe val2 sum2 is:%d\n", sum1, sum2);
//			break;
//	
//		default:
//			printf("try again\n");
//			break;
//		}
//
//	}
//
//#endif
//
//	return 0;
//}
