#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

/*
int main9879068()
{
	//r - open for reading
	//w- open for writin (override alredy existed data)
	//a-open for append to end of file

	//TASK1

	char* fileNema = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\task1\\task1.txt";
	FILE* f = fopen(fileNema, "w");
	if (f != NULL) {

		for (int i = 0; i < 10; i++)
		{
			fputc('*', f);
			fputc('\n', f);
		}

	}
	else
	{
		//eror
		//f = fopen(fileNema, "r");
	}
	fclose(f);

	//TASK2
	char* fileNema1 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\task1\\task2.txt";
	FILE* f1 = fopen(fileNema1, "w");
	if (f1 != NULL) {

		for (int i = 0; i < 10; i++)
		{
			for (int i1 = 0; i1 < 10; i1++)
			{
				fputc('A', f1);
			}
			fputc('\n', f1);
		}
	}
	else
	{
		//eror
		//f = fopen(fileNema1, "r");
	}
	fclose(f1);

	//TASK3
	char* fileNema2 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\task1\\task3.txt";
	FILE* f2 = fopen(fileNema2, "w");
	if (f2 != NULL) {

		printf("enter a number of rows:\n");
		int x;
		scanf("%d", &x);

		for (int i = 0; i < x; i++)
		{
			for (int i1 = 0; i1 < 50; i1++)
			{
				fputc('*', f2);
			}
			fputc('\n', f2);
		}
	}
	else
	{
		//eror
		//f2 = fopen(fileNema2, "r");
	}
	fclose(f2);
	

	//TASK4
	char* fileNema3 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\task1\\task4.txt";
	FILE* f3 = fopen(fileNema3, "w");
	if (f3 != NULL) {

		printf("enter a string you like:\n");
		char str[100];
		gets(str);
		int str1 = strlen(str);

		printf("enter a number of rows:\n");
		int x;
		scanf("%d", &x);


		for (int i = 0; i < x; i++)
		{

			for (int j = 0; j < str1; j++)
			{
				fputc(str[j], f3);
			}
			fputc('\n', f3);
		}
	}
	else
	{
		//eror
		//f3 = fopen(fileNema2, "r");
	}
	fclose(f3);


	return 0;
}
*/