#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

/*
struct Item {
	int id;
	int val;
	struct Item* next;
};

struct Item* head = NULL;


freeLinkedList();

int main34242432324()
{

	int userResponse;

	printf("click 1 for add:\n click 2 for print:\n Click 3 for Exit");
	scanf("%d", &userResponse);


	struct Item* currentItem;
	struct Item* prevItem=NULL;

	while (userResponse == 1)
	{
		currentItem = malloc(sizeof(struct Item));

		if (head == NULL) {
			head = currentItem;
		}
		else
		{
			prevItem->next = currentItem;
		}

		scanf("%d %d", &currentItem->id, &currentItem->val);
		currentItem->next = NULL;

		printf("click 1 for add:\n click 2 for print:\n Click 3 for Exit");
		scanf("%d", &userResponse);

		prevItem = currentItem;

		freeLinkedList();
	}

	return 0;
}

freeLinkedList()
{
	struct Item* currenItem = head;
	struct Item* releaseItem = head;
	while (currenItem->next != NULL)
	{
		currenItem = currenItem->next;
	}
}

*/