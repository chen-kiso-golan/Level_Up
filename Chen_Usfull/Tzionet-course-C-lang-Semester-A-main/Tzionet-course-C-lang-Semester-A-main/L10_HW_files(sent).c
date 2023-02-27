//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//
//#define TASK1
////#define TASK3
//
//int main6857647454() {
//
////task1
//
//#ifdef TASK1
//	int arr[10];
//	for (int i = 0; i < 10; i++) {
//		printf("pleas enter a number:\n");
//		scanf("%d", &arr[i]);
//	}
//	printf("thank you!\n");
//
//	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW1.bin", "w");
//	if (f == NULL) {
//		//EROR
//	}
//	else {
//		fwrite(arr, sizeof(int), 10, f);
//		fclose(f);
//	}
//#endif
//
//
////task3
//
//#ifdef TASK3
//	struct Thing {
//		int val;
//		char name[100];
//		short answer;
//	};
//
//	struct Thing a1;
//	printf("please enter a val:\n");
//	scanf("%d", &a1.val);
//	printf("please enter a name:\n");
//	scanf("%s", &a1.name);
//
//	if (a1.val > 10 && strlen(a1.name) > 5) {
//		a1.answer = 1;
//	}
//	else {
//		a1.answer = 0;
//	}
//	printf("%hu\n", a1.answer);
//
//
//	struct Thing a2;
//	printf("please enter a val:\n");
//	scanf("%d", &a2.val);
//	printf("please enter a name:\n");
//	scanf("%s", &a2.name);
//
//	if (a2.val > 10 && strlen(a2.name) > 5) {
//		a2.answer = 1;
//	}
//	else {
//		a2.answer = 0;
//	}
//	printf("%hu\n", a2.answer);
//
//	struct Thing a3;
//	printf("please enter a val:\n");
//	scanf("%d", &a3.val);
//	printf("please enter a name:\n");
//	scanf("%s", &a3.name);
//
//	if (a3.val > 10 && strlen(a3.name) > 5) {
//		a3.answer = 1;
//	}
//	else {
//		a3.answer = 0;
//	}
//	printf("%hu\n", a3.answer);
//
//	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW3.bin", "w");
//	if (f == NULL) {
//		//eror
//	}
//	else {
//		fwrite(&a1, sizeof(struct Thing), 1, f);
//		fwrite(&a2, sizeof(struct Thing), 1, f);
//		fwrite(&a3, sizeof(struct Thing), 1, f);
//		fclose(f);
//	}
//#endif
//
//
//
//
//	return 0;
//}