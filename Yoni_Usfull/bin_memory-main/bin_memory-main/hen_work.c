#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main321211()
{

	////task1
	printf("please enter a number of short type:\n");
	short user;
	scanf("%hu",&user);

	FILE* f;
	f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\28.08.2022\\bin_memory\\bin_memory\\task1.bin", "w");
	if (f != NULL)
	{
		fwrite(&user, sizeof(short), 1, f);
		fclose(f);
	}
	else {
		//eror
	};

	//task2

	int UserMult;
	int sum = 0;
	

	FILE* f1;
	f1 = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\28.08.2022\\bin_memory\\bin_memory\\task1.bin", "r");
	if (f1 != NULL)
	{
		int read = fread(&UserMult, sizeof(short), 1, f1);
		sum = UserMult * UserMult;
		printf("your num mult by itself is: %d", sum);
		fclose(f1);
	}
	else {//eror
	};

}