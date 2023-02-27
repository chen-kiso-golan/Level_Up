#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main687978()
{

	FILE* f;

	struct Student {
		char name[100];
		int age;

	};

	f = fopen("struct.bin", "w");

	struct Student stu;
	strcpy(stu.name, "Slomi");
	stu.age = 18;


	if (f != NULL)
	{
		fwrite(&stu, sizeof(struct Student), 1, f);

		fclose(f);
	}
	else
	{
		// problem
		// error message
	}

	struct Student newStu;

	FILE* f1 = fopen("struct.bin", "r");
	if (f != NULL)
	{
		int read = fread(&newStu, sizeof(struct Student), 1, f1);

		fclose(f1);

	}
	else
	{
		// problem
		// error message
	}

}
