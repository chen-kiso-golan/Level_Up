#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

//task1 
struct Item {
	int val;
	struct Item* next;
	struct Item* prev;
};

struct Item* head = NULL;
struct Item* tail = NULL;

//task2
void GenerateList() {

	struct Item* current;
	struct Item* prevA = NULL;
	time_t j = time(0);
	srand(j);

	for (int i = 0; i < 10; i++) {

		int a = rand();

		current = (struct Item*)malloc(sizeof(struct Item) * 1);
		current->val = a;
		if (head == NULL) {
			head = current;
			current -> prev = NULL;
		}
		else {
			prevA->next = current;
			current->prev = prevA;
		}
		current->next = NULL;
		prevA = current;
		tail = current;
		
	}
}

//task3
void GenerateXList(int x) {

	struct Item* current;
	struct Item* prevA = NULL;
	time_t j = time(0);
	srand(j);

	for (int i = 0; i < x; i++) {

		int a = rand();

		current = (struct Item*)malloc(sizeof(struct Item) * 1);
		current->val = a;
		if (head == NULL) {
			head = current;
			current->prev = NULL;
		}
		else {
			prevA->next = current;
			current->prev = prevA;
		}
		current->next = NULL;
		prevA = current;
		tail = current;

	}
}

//task4
void PrintList() {
	struct Item* current = head;
	struct Item* print = head;
	while (current->next != NULL) {
		print = current;
		current = current->next;
		printf("%d\n", print->val);
	}
	print = current;
	printf("%d\n", print->val);
}

//task5
void FreeList() {
	struct Item* current = head;
	struct Item* freeItem = head;
	while (current->next != NULL) {
		freeItem = current;
		current = current->next;
		free(freeItem);
	}
	freeItem = current;
	free(freeItem);
}

//task6
void FindVal(int y) {
	struct Item* current = head;
	struct Item* find = head;
	int count = 0;
	int county = 0;
	while (current != NULL) {
		find = current;
		if (find->val == y) {
			count++;
			county++;
			printf("i found your val (%d) in place number %d\n",y, count);
		}
		else {
			count++;
		}
		current = current->next;
	}
	printf("%d is in your list %d times\n",y,county);
}

//task7
void ReplaceVal(int n, int o) {
	struct Item* current = head;
	struct Item* find = head;
	struct Item* adress = NULL;
	while (current != NULL) {
		find = current;
		if (find->val == o) {
			find->val = n;
			adress = find;
		}
		current = current->next;
	}
	printf("your new list is:\n");
	PrintList();
	printf("your new num is in adrres: %p\n",adress);
	
}

//task8
void resetList() {
	
	if (head != NULL) {
		FreeList();
		struct Item* head = NULL;
		struct Item* tail = NULL;
	}
}

//task9
void InsertItem() {

	//printf("please enter a num to the list:\n (enter the num 10 if you want to stop)\n");
	int a = 1;
	//scanf("%d", &a);

	struct Item* current;
	struct Item* prevA = NULL;
	//int countRound = 0;

	while (a != 10) {

		printf("please enter a num to the list:\n (enter the num 10 if you want to stop)\n");
		//int a;
		scanf("%d", &a);
		
		current = (struct Item*)malloc(sizeof(struct Item) * 1);
		current->val = a;

			//the first 
			if (head == NULL && prevA == NULL && tail==NULL) {
				head = current;
				tail = current;
				current->prev = NULL;
				current->next = NULL;
				prevA = current;
			}
			//the second (head)
			/*else if (tail == NULL && prevA->val > current->val) {
				head = current;
				tail = prevA;
				head->prev = NULL;
				head->next = prevA;
				tail->prev = current;
				tail->next = NULL;
			}
			//the second (tail)
			else if (tail == NULL && prevA->val < current->val) {
				tail = current;
				head = prevA;
				tail->prev = prevA;
				tail->next = NULL;
				head->next = current;
				head->prev = NULL;
			}*/
		    //the third (scan all)
			else if (head != NULL && tail != NULL) {

				//in the midel
				struct Item* find = head;
				struct Item* back = NULL;
				while (find->val < current->val) {
					back = find;
					find = find->next;
					if (find == NULL) {
						break;
					}
				}
				//the num goes to the head
				if (back == NULL) {
					current->next = find;
					current->prev = back;
					find->prev = current;
					head = current;
				}
				//the num goes to the tail
				else if (find == NULL) {
					current->next = find;
					current->prev = back;
					back->next = current;
					tail = current;
				}
				//the num goes to the middel
				else {
					current->next = find;
					current->prev = back;
					find->prev = current;
					back->next = current;
				}
			
			}

	}

	PrintList();
	
}

int main()
{

//task2
	
	//GenerateList();

//task3
	//GenerateXList(11);

//task4
	//PrintList();

//task5
	//FreeList();

//task6
	//printf("please enter a val:\n");
	//int y;
	//scanf("%d", &y);
	//FindVal(y);

//task7
	//int n, o;
	//printf("please enter a new val:\n");
	//scanf("%d", &n);
	//printf("insted of an old val: \n");
	//scanf("%d", &o);
	//ReplaceVal(n,o);

//task8
	//resetList();

//task9
	InsertItem();


	return 0;
}
