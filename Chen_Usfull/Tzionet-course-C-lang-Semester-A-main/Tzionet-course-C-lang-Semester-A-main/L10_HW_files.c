//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//int main7858764() {
//
//	/*
//	//task1
//
//		int arr[10];
//		for (int i = 0; i < 10; i++) {
//			printf("pleas enter a number:\n");
//			scanf("%d", &arr[i]);
//		}
//		printf("thank you!\n");
//
//		FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW1.bin", "w");
//		if (f == NULL) {
//			//EROR
//		}
//		else {
//			fwrite(arr, sizeof(int), 10, f);
//			fclose(f);
//		}
//
//
//	//task2
//		int arr[4];
//		int sum = 0;
//		for (int i = 0; i < 4; i++) {
//			printf("pleas enter a number:\n");
//			scanf("%d", &arr[i]);
//			sum = sum + arr[i];
//		}
//		printf("thank you!\n");
//
//		int arr1[3];
//		int sum1 = 0;
//		for (int i = 0; i < 3; i++) {
//			printf("pleas enter a number:\n");
//			scanf("%d", &arr1[i]);
//			sum1 = sum1 + arr1[i];
//		}
//		printf("thank you!\n");
//
//		FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW2.bin", "w");
//		if (f == NULL) {
//			//EROR
//		}
//		else {
//			if (sum1 > sum) {
//				fwrite(arr1, sizeof(int), 3, f);
//				fclose(f);
//			}
//			else if (sum > sum1) {
//				fwrite(arr, sizeof(int), 4, f);
//				fclose(f);
//			}
//
//		}
//
//
//	//task3
//		struct Thing {
//			int val;
//			char name[100];
//			short answer;
//		};
//
//		struct Thing a1;
//		printf("please enter a val:\n");
//		scanf("%d", &a1.val);
//		printf("please enter a name:\n");
//		scanf("%s", &a1.name);
//
//		if (a1.val > 10 && strlen(a1.name) > 5) {
//			a1.answer = 1;
//		}
//		else {
//			a1.answer = 0;
//		}
//		printf("%hu\n",a1.answer);
//
//
//		struct Thing a2;
//		printf("please enter a val:\n");
//		scanf("%d", &a2.val);
//		printf("please enter a name:\n");
//		scanf("%s", &a2.name);
//
//		if (a2.val > 10 && strlen(a2.name) > 5) {
//			a2.answer = 1;
//		}
//		else {
//			a2.answer = 0;
//		}
//		printf("%hu\n", a2.answer);
//
//		struct Thing a3;
//		printf("please enter a val:\n");
//		scanf("%d", &a3.val);
//		printf("please enter a name:\n");
//		scanf("%s", &a3.name);
//
//		if (a3.val > 10 && strlen(a3.name) > 5) {
//			a3.answer = 1;
//		}
//		else {
//			a3.answer = 0;
//		}
//		printf("%hu\n", a3.answer);
//
//		FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW3.bin", "w");
//		if (f == NULL) {
//			//eror
//		}
//		else {
//			fwrite(&a1, sizeof(struct Thing), 1, f);
//			fwrite(&a2, sizeof(struct Thing), 1, f);
//			fwrite(&a3, sizeof(struct Thing), 1, f);
//			fclose(f);
//		}
//
//
////task4+5 --- לא מצליח לחשב נכון
//
//	int arr[] = { 10,11,12,13,14,15,16,17,18,19,20 };
//	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW4.bin", "w");
//		if (f == NULL) {
//			//eror
//		}
//		else {
//			fwrite(arr, sizeof(int), 9, f);
//			fclose(f);
//		}
//
//		
//		f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L10 - haim 280822\\HW4.bin", "r");
//		if (f == NULL) {
//			//eror
//		}
//		else {
//			int count = 0;
//			int sum = 0;
//			int newarr[20];
//			int read = 1;
//			while (read > 0) {
//				read = fread(&newarr, sizeof(int), 1, f);
//				sum = sum + newarr[count];
//				count++;
//			}
//			fclose(f);
//			printf("the count: %d\n the sum: %d\n", count, sum);
//		}
//
//		/*----------------------------------------------- haims answer
//		 void Targil5(){
//
//	    FILE* f = fopen("yarinhw4.bin", "r");
//        int* buffer =(int*) malloc(sizeof(int)*20);
//	    if (f)
//	       {
//	    	int read = 0;
//		    int count;
//	    	int sum = 0;
//	      	while (read = fread(buffer, sizeof(int), 1, f)>0);
//	        	{
//			     count++;
//		       	 sum = sum + buffer;
//			     printf("%d", buffer);
//		        }
//		   fclose(f);
//	       }
//	    else
//	      {
//	    	// problem
//		    // error message
//       	  }
//
//     -----------------------------------------------------
//
//		
////task6 ---- נתקע אחרי הכנסה של מבנה אחד
//    
//    struct Thing {
//	  int val;
//	  char name[100];
//	  short answer;
//    };
//
//	int size;
//	printf("how many structrs do you want:\n");
//	scanf("%d", &size);
// 
//	struct Thing* list;
//	struct Thing* ImHere;
//	list = malloc(sizeof(struct Thing) * size);
//	ImHere = list;
//	int sum = 0;
//
//	
//	for (int i = 0; i < size; i++) {
//		printf("please enter val name:\n");
//		scanf("%d %s", ImHere->val, ImHere->name);
//		if (ImHere->val > 10 && strlen(ImHere->name) > 5) {
//			ImHere->answer = 1;
//		}
//		else {
//			ImHere->answer = 0;
//		}
//		sum = sum + (ImHere->val);
//		ImHere++;
//	}
//
//	printf("the sum of val is: %d", sum);
//
//	//*/
//
//	return 0;
//
//}