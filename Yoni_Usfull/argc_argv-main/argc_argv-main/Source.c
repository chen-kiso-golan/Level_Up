//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//struct Yoni
//{
//	int val;
//	struct Yoni* next;
//};
//
//struct Yoni* head = NULL;
//
//
//
//void PrintList()
//{
//	struct Yoni* currentyoni = head;
//	struct Yoni* print_yoni = head;
//
//	while (print_yoni->next != NULL)
//	{
//		print_yoni = currentyoni;
//		currentyoni = currentyoni->next;
//		printf("your Linked list is:%d\t", print_yoni->val);
//	}
//}
//
//
//void Find44()
//{
//	int count = 0;
//
//	struct Yoni* currentyoni = head;
//	struct Yoni* Find44 = head;
//
//	while (Find44->next != NULL)
//	{
//		Find44 = currentyoni;
//		currentyoni = currentyoni->next;
//		printf("your Linked list is:%d\t", Find44->val);
//		if (Find44->val == 44) {
//			count++;
//		}
//	}
//
//	printf("44 is in your list %d times\n", count);
//
//}
//
//void FindId()
//{
//	int id = 10;
//
//	int checkId = 0;
//
//	struct Yoni* currentyoni = head;
//	struct Yoni* List = head;
//
//	while (List->next != NULL)
//	{
//		List = currentyoni;
//		currentyoni = currentyoni->next;
//		printf("your Linked list is:%d\n", List->val);
//		if (List->val == id) {
//			checkId++;
//		}
//	}
//
//	printf("I found your id (10) in place number: %d\n", checkId + 1);
//
//}
//
//
//
//int main1231()
//{
//	int num_user;
//
//	printf("click 1 for add:\t  Click 100 for Exit\n");
//	scanf("%d", &num_user);
//
//	struct Yoni* currentyoni;
//	struct Yoni* prevyoni = NULL;
//
//	while (num_user != 100)
//	{
//		currentyoni = (struct Yoni*)malloc(sizeof(struct Yoni) * 1);
//
//		if (head == NULL) {
//			head = currentyoni;
//		}
//		else
//		{
//			prevyoni->next = currentyoni;
//		}
//		printf("enter valu for val:");
//		scanf("%d", &currentyoni->val);
//		currentyoni->next = NULL;
//
//		prevyoni = currentyoni;
//
//		printf("click 1 for add:\t  Click 100 for Exit\n");
//		scanf("%d", &num_user);
//	}
//
//
//	FindId();
//
//	return 0;
//}