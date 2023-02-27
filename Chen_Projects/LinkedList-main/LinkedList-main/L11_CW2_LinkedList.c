#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

struct task3 {
	int val;
	struct task3* next;
};
struct task3* head = NULL;

void freeLinkedList() {
	struct task3* current = head;
	struct task3* releas = head;
	while (current != NULL) {
		releas = current;
		current = current->next;
		free(releas);
	}
}

void PrintList() {
	struct task3* current = head;
	struct task3* print = head;
	while (current != NULL) {
		print = current;
		current = current->next;
		printf("%d\n", print->val);
	}
}

void Find44() {
	struct task3* current = head;
	struct task3* find = head;
	int count = 0;
	while (current != NULL) {
		find = current;
		if (find->val == 44) {
			count++;
		}
		current = current->next;
	}
	printf("44 is in your list %d times\n", count);
}

void FindId() {
	struct task3* current = head;
	struct task3* findid = head;
	int count = 0;
	int id = 10;
	while (current != NULL) {
		findid = current;
		current = current->next;
		if (findid->val != 10) {
			count++;
		}
		else {
			printf("i found your id (10) in place number %d\n", count+1);
			count++;
		}

	}
}

int structCount()
{
	struct task3* currentI = head;
	struct task3* prevI;
	int count = 0;
	while (currentI != NULL)
	{
		prevI = currentI;
		currentI = currentI->next;
		count++;
	}
	return count;
}

void SaveToFile(int size)
{
	struct Value
	{
		int Val;
	};
	
	struct task3* currentI = head;
	struct task3* prevI;
	
	struct Value* origin;
	struct Value* currentV;
	
	origin = malloc(sizeof(struct Value) * size);
	currentV = origin;
	for (int i = 0; i < size; i++)
	{
		prevI = currentI;
		currentI = currentI->next;
		currentV->Val = prevI->val;
		currentV++;
	}
	currentV = origin;
	
	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L11 - haim 290822\\hm7", "w");
	if (!f)
	{
		// ERROR
	}
	else
	{
		int write = fwrite(currentV, sizeof(struct Value), size, f);
		fclose(f);
	}
	free(origin);
}


int main(){

//task3

	struct task3* current;
	struct task3* prev = NULL; 

	int user;
	printf("please enter a number to val:\n");
	scanf("%d", &user);

	while (user != 100) {
		current = (struct task3*)malloc(sizeof(struct task3));
		current->val = user;
		if (head == NULL) {
			head = current;
		}
		else {
			prev->next = current;
		}
		prev = current;
		current->next = NULL;
		printf("please enter a number to val:\n");
		scanf("%d", &user);
	}

//task4

	PrintList();

//task5

	Find44();

//task6

	FindId();

//task7-yarins answer

	int userResponse;
	printf("save to file? 1 = yes | 0 = no:");
	scanf("%d", &userResponse);
	if (userResponse == 1)
	{
		SaveToFile(structCount());
		printf("saved\n\n");
	}
	else
	{
		printf("skipped saving\n\n");
	}

//the end

	freeLinkedList();

return 0;
}