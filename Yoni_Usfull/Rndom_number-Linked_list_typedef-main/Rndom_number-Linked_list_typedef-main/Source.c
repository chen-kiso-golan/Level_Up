#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

struct Item
{
	int val;
	struct Item* Next;
	struct Item* Prev;
};

struct Item* head = NULL;
struct Item* tail = NULL;



void Printlist()
{
	int counter = 0;
		struct Item* currentItem = head;
		struct Item* print_Item = head;
	
		while (print_Item->Next != NULL)
		{
			print_Item = currentItem;
			currentItem = currentItem->Next;
			counter++;
			printf("#%d-%d\n",counter, print_Item->val);
		}
}



struct Item* findHigher(int val) {

	struct Item* ret = NULL;
	struct Item* curr = head;

	while (curr != NULL)
	{
		if (curr->val > val) {
			ret = curr;
			return ret;
		}
		curr = curr->Next;
	}
	return ret;
}


void AddItem()
{
	int num;
	int ind;

	struct Item* currentItem = NULL;	
	struct Item* kodemItem = NULL;

	printf("insert item to list? 1 = yes | 0 = no : ");
	scanf("%d", &ind);

	while (ind == 1)
	{
		printf("please enter number for struct:");
		scanf("%d", &num);

		currentItem = (struct Item*)malloc(sizeof(struct Item));
		currentItem->val = num;

		if (head == NULL) {
			head = currentItem;
			tail = currentItem;
			currentItem->Prev = NULL;
			currentItem->Next = NULL;
		}
		else
		{
			struct Item* highItem = findHigher(currentItem->val);
			if (highItem == head) {

				currentItem->Next = head;
				currentItem->Prev = NULL;
				head->Prev = currentItem;
				head = currentItem;

			}
			else if (highItem ==  NULL)
			{
				currentItem->Next = NULL;
				currentItem->Prev = tail;
				tail->Next = currentItem;
				tail = currentItem;
			}
			else
			{
				currentItem->Next = highItem;
				currentItem->Prev = highItem->Prev;
				highItem->Prev->Next = currentItem;
				highItem->Prev = currentItem;
			}

		}
			printf("insert item to list? 1 = yes | 0 = no : ");
			scanf("%d", &ind);

	}
	Printlist();
}






int main()
{
	
	
	AddItem();


	return 0;
}
