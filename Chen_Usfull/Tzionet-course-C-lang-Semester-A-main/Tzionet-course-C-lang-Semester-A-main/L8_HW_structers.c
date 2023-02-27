//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdlib.h>
//#pragma warning(disable : 4996)
//
//
//int main869866()
//{
//	/*
////task1
//	char* f1 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\HW\\HW.txt";
//	FILE* f = fopen(f1, "w");
//	if (f != NULL) {
//		for (int row = 1; row <= 5; row++) {
//			for (int stars = 1; stars <= row; stars++) {
//				fputc('*', f);
//			}
//			fputc('\n', f);
//		}
//	}
//	else {
//		//eror
//	}
//	fclose(f);
//
//
////task2
//	char* f2 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\HW\\HW2.txt";
//	FILE* f = fopen(f2, "w");
//	if (f != NULL) {
//		int num = '1';
//		for (int row = 1; row <= 4; row++) {
//			for (int inside = 1; inside <= 10; inside++) {
//				fputc(num, f);
//			}
//			num++;
//			fputc('\n', f);
//		}
//	}
//	else {
//		//eror
//	}
//	fclose(f);
//
//
//
////TASK3
//		//new code:
//		//char str1[100];
//		//char str2[200] = "abanibioboebe";
//		//sprintf(str1, "theformat%d%s%d%s", 234, str2, 2 + 2, "maoz");
//		//printf("%s", str1);
//
//	printf("enter a number of file:\n");
//	int user;
//	scanf("%d", &user);
//	int num = 1;
//
//	for (int i = 0; i < user; i++) {
//
//		char str1[100];
//		sprintf(str1, "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\HW\\file%d.txt", num);
//
//		char* f3 = str1;
//		FILE* f = fopen(f3, "w");
//		if (f != NULL) {
//			for (int j = 0; j < user; j++) {
//				fputc('*', f);
//			}
//		}
//		else {
//			//eror
//		}
//		fclose(f);
//		num++;
//	}
//
//
////TASK4
//	struct Car {
//		char Name[100];
//		char Model[10];
//		int Year;
//		int CarNum;
//	};
//
//	struct Car c1;
//	strcpy(c1.Name,"suzuki");
//	strcpy(c1.Model, "blano");
//	c1.Year = 2020;
//	c1.CarNum = 2222111;
//
//	printf("%s,%s,%d,%d", c1.Name, c1.Model, c1.Year, c1.CarNum);
//
//
////TASK5
//	struct Car {
//		char Name[100];
//		char Model[10];
//		int Year;
//		int CarNum;
//	};
//
//	struct Car CarList[2];
//	for (int i = 0; i < 2; i++) {
//		printf("please enter your car: name model year car-num\n");
//		scanf("%s %s %d %d", CarList[i].Name, CarList[i].Model, &CarList[i].Year, &CarList[i].CarNum);
//	}
//
//	for (int i = 0; i < 2; i++) {
//		printf("your cars are:\n %s %s %d %d\n", CarList[i].Name, CarList[i].Model, CarList[i].Year, CarList[i].CarNum);
//	}
//	*/
//
//	//TASK6
//	struct Task {
//		char Name[10];
//		char Symbol[2];
//		char Code[3];
//	};
//
//	struct Task t1;
//	strcpy(t1.Name, "waahat");
//	strcpy(t1.Symbol, "bb");
//	strcpy(t1.Code, "a3a");
//
//	char str1[100];
//	strcpy(str1, t1.Name);
//	char str2[100];
//	strcpy(str2, t1.Symbol);
//	char str3[100];
//	strcpy(str3, t1.Code);
//
//	int NameLen = strlen(t1.Name);
//	int SymbolLen = strlen(t1.Symbol);
//	int CodeLen = strlen(t1.Code);
//
//	char* f6 = "C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L8 - haim 240822\\HW\\HW6.txt";
//	FILE* f = fopen(f6, "w");
//	if (f != NULL) {
//
//		for (int i = 0; i < NameLen; i++) {
//			fputc(str1[i], f);
//		}
//		fputs('\n', f);
//
//		for (int i = 0; i < SymbolLen; i++) { //????
//			fputc(str2[i], f);
//		}
//		fputs('\n', f);
//
//		for (int i = 0; i < CodeLen; i++) {
//			fputc(str3[i], f);
//		}
//	}
//	else {
//		//eror
//	}
//	fclose(f);
//
//
//	return 0;
//}