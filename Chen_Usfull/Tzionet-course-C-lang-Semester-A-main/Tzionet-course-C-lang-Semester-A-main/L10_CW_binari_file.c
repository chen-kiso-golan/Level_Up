//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//
//int main879696() {
///*
////task1
//	//printf("please enter a number of short type:\n");
//	short user = 4;
//	//scanf("%hu",&user);
//
//	FILE* f1;
//	f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\VS code files\\280822\\task1.bin", "w");
//	if (f1 != NULL)
//	{
//		fwrite(&user, sizeof(short), 1, f1);
//		fclose(f1);
//	}
//	else {//eror
//	};
//
////task2
//
//	short UserMult;
//
//	
//	f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\VS code files\\280822\\task1.bin", "r");
//	if (f1 != NULL)
//	{
//		fread(&UserMult, sizeof(short), 1, f1);
//		printf("your num mult by itself is: %d", UserMult * UserMult);
//		fclose(f1);
//	}
//	else {//eror
//	};
//
////task3
//
//	int user;
//
//	FILE* f2;
//	f2 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\VS code files\\280822\\task2.bin", "w");
//	if (f2 != NULL)
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			printf("please enter a number:\n");
//			scanf("%d", &user);
//			fwrite(&user, sizeof(int), 1, f2);
//			fclose(f2);
//		}
//	}
//	else {//eror
//	};
//
////task4
//	int text;
//	int sum = 0;
//
//	FILE* f1;
//	f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\VS code files\\280822\\amir.bin", "r");
//	if (f1 != NULL)
//	{
//		for (int i = 0; i < 10; i++) {
//			fread(&text, sizeof(int), 1, f1);
//			sum = sum + text;
//			printf("the num is: %d\n", text);
//		}
//		printf("the sum is: %d", sum);
//		fclose(f1);
//	}
//	else {//eror
//	};
//
//
////task5
//
//	struct Item {
//		int barcode;
//		int price;
//		char name[100];
//		char color[100];
//	};
//
//	struct Item something;
//	something.barcode = 5875;
//	something.price = 18;
//	strcpy(something.name, "cofee");
//	strcpy(something.color, "black");
//	
//	FILE* f5;
//	f5 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\VS code files\\280822\\task5.bin", "w");
//	if (f5 != NULL)
//	{
//			fwrite(&something, sizeof(struct Item), 1, f5);
//			fclose(f5);
//		
//	}
//	else {//eror
//	};
//
//
//
//	*/
//
//
//
//	return 0;
//}