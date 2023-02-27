//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//
//int main98098980()
//{
///*
//	int a = 190;
//	int b = 290;
//	int c = 390;
//
//	FILE* f;
//	f = fopen("data.bin", "w");
//
//	if (f != NULL)
//	{
//		fwrite(&a, sizeof(int), 1, f);
//		fwrite(&b, sizeof(int), 1, f);
//		fwrite(&c, sizeof(int), 1, f);
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//	FILE* f = fopen("data.bin", "r");
//	if (f != NULL)
//	{
//		int read = fread(&c, sizeof(int), 1, f);
//		printf("%d\t", c);
//		read = fread(&c, sizeof(int), 1, f);
//		printf("%d\t", c);
//		read = fread(&c, sizeof(int), 1, f);
//		printf("%d", c);
//
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//
//
////----------------------------------------------
//
//
//	struct Student {
//		char name[100];
//		int age;
//	};
//
//	struct Student stu;
//	strcpy(stu.name, "Slomi");
//	stu.age = 18;
//
//	FILE* f;
//	f = fopen("struct.bin", "w");
//
//	if(f != NULL)
//	{
//		fwrite(&stu, sizeof(struct Student), 1, f);
//
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//	struct Student newStu;
//
//	FILE* f1 = fopen("struct.bin", "r");
//	if(f != NULL)
//	{
//		int read = fread(&newStu, sizeof(struct Student), 1, f1);
//		fclose(f1);
//
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//
//
//
//
//
//
//
////--------------------------------------------------
//
//	int arr[5] = { 23,44,56,100,1009 };
//	FILE* f = fopen("arrat.dat", "w");
//
//	if (f != NULL)
//	{
//		//arr = &arr[0]
//		int written = fwrite(arr, sizeof(int), 5, f);
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//	f = fopen("arrat.dat", "r");
//
//	if (f != NULL)
//	{
//
//		int read = fread(arr, sizeof(int), 5, f);
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//*/
//	return 0;
//}