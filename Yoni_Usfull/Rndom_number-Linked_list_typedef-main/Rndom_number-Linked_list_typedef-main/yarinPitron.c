//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//
//typedef struct List
//{
//    int val;
//    struct List* next;
//    struct List* prev;
//}List;
//
//
//List* head = NULL;
//List* tail = NULL;
//
//
//
//void printLinkedList()
//{
//	List* currentL = head;
//	List* printL;
//	int count = 1;
//	while (currentL != NULL)
//	{
//		printL = currentL;
//		currentL = currentL->next;
//		printf("#%d - %d\n", count, printL->val);
//		count++;
//	}
//}
//
//
//
//void sort_linkList()
//{
//    List* currentL;
//    List* prevL = NULL;
//    List* nextL = NULL;
//    int ind;
//    int num;
//    int count = 0;
//    printf("insert item to list? 1 = yes | 0 = no : ");
//    scanf("%d", &ind);
//    while (ind == 1)
//    {
//        count++;
//        printf("please enter a number:");
//        scanf("%d", &num);
//        currentL = (List*)malloc(sizeof(List));
//        currentL->val = num;
//        if (head == NULL)
//        {
//            head = currentL;
//            tail = currentL;
//            currentL->next = NULL;
//            currentL->prev = NULL;
//        }
//        else
//        {
//            nextL = head;
//            prevL = NULL;
//            while (currentL->val > nextL->val)
//            {
//                prevL = nextL;
//                nextL = nextL->next;
//                if (nextL == NULL)
//                {
//                    break;
//                }
//            }
//            if (prevL == NULL)
//            {
//                head = currentL;
//                currentL->prev = NULL;
//                currentL->next = nextL;
//                nextL->prev = currentL;
//            }
//            else if (nextL == NULL)
//            {
//                tail = currentL;
//                currentL->next = NULL;
//                currentL->prev = prevL;
//                prevL->next = currentL;
//            }
//            else
//            {
//                currentL->prev = prevL;
//                currentL->next = nextL;
//                prevL->next = currentL;
//                nextL->prev = currentL;
//            }
//        }
//        printf("insert item to list? 1 = yes | 0 = no : ");
//        scanf("%d", &ind);
//    }
//    printf("done/skipped\n\n");
//    if (count > 0)
//    {
//        printf("print list? 1 = yes | 0 = no : ");
//        scanf("%d", &ind);
//        if (ind == 1)
//        {
//            printLinkedList();
//        }
//    }
//}
//
//int main()
//{
//
//    sort_linkList();
//
//    return 0;
//}