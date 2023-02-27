#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


int main543532432()
{
	struct Worker
	{	
		char name[100];
		int age;
		char id[10];
	};

	
	struct Worker itemList[5];

	printf("pleas enter structer:\n");
	for (int i = 0; i < 2; i++)
	{
		scanf("%d %s %s", &itemList[i].age, itemList[i].name, itemList[i].id);	
	}

	for (int i = 0; i < 2; i++)
	{
		printf("%d %s %s\n", itemList[i].age, itemList[i].name, itemList[i].id);
	}


	

	return 0;
}