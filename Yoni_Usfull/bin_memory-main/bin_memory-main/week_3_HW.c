//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#pragma warning(disable:4996)
//
//void Targil5();
//
//int main()
//{
//	/*task 1
//	int arr[10];
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("please enter number for array:");
//		scanf("%d", &arr[i]);
//	}
//	
//	FILE* f = fopen("HomeWork_task1.dat", "w");
//
//	if (f)
//	{
//		int written = fwrite(arr, sizeof(int), 10, f);
//
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//	//*/
//
//
//	/*task 2
//	int arr1[4];
//	int arr2[8];
//	int sum1 = 0;
//	int sum2 = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("please enter 4 number for array:");
//		scanf("%d", &arr1[i]);
//		sum1 = sum1 + arr1[i];
//		printf("%d", sum1);
//	}
//
//	for (int i = 0; i < 8; i++)
//	{
//		printf("please enter 8 number for array:");
//		scanf("%d", &arr2[i]);
//		sum2 = sum2 + arr2[i];
//	}
//
//	FILE* f = fopen("HomeWork_task2.dat", "w");
//
//	if (f)
//	{
//		if (sum1 > sum2) {
//			int written = fwrite(arr1, sizeof(int), 10, f);
//		}
//		else
//		{
//			int written = fwrite(arr2, sizeof(int), 10, f);
//		}
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//	//*/
//
//
//
//	/*task 3
//	
//	struct MyStudent
//	{
//		int val;
//		char name [100];
//		short answer;
//	};
//
//
//	struct MyStudent item[3];
//
//	
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("Please Enter val number and name:\n");
//		scanf("%d %s", &item[i].val, item[i].name);
//
//			if (item[i].val > 10 && strlen(item[i].name) > 5) {
//				item[i].answer = '1'; // i put 'asci' valu to sea it on the document:)
//			}
//			else
//			{
//				item[i].answer = '0'; // i put 'asci' valu to sea it on the document:)
//			}
//	}
//	FILE* f = fopen("HomeWork_task3.dat", "w");
//
//	if (f)
//	{
//		int written = fwrite(item, sizeof(struct MyStudent), 3, f);
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//	//*/
//
//
//	/*task 4
//	int arr[10] = {2,4,6,8,10,1,3,5,7,9};
//
//	
//
//	FILE* f = fopen("HomeWork_task4.dat", "w");
//
//	if (f)
//	{
//		int written = fwrite(arr, sizeof(int), 10, f);
//
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//	//*/
//
//
//
//	///*task 5
//
//void Targil5();
//	
//	//*/
//
//	///*task 6
//	struct MyStudent
//	{
//		int val;
//		char name[100];
//		short answer;
//	};
//
//
//	struct MyStudent item[3];
//
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("Please Enter val number and name:\n");
//		scanf("%d %s", &item[i].val, item[i].name);
//
//		if (item[i].val > 10 && strlen(item[i].name) > 5) {
//			item[i].answer = '1'; // i put 'asci' valu to sea it on the document:)
//		}
//		else
//		{
//			item[i].answer = '0'; // i put 'asci' valu to sea it on the document:)
//		}
//	}
//	FILE* f = fopen("HomeWork_task3.dat", "w");
//
//	if (f)
//	{
//		int written = fwrite(item, sizeof(struct MyStudent), 3, f);
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//	//*/
//	}
//
//void Targil5()
//{
//
//	FILE* f = fopen("yarinhw4.bin", "r");
//
//	int* buffer =(int*) malloc(sizeof(int)*20);
//	
//
//	if (f)
//	{
//		int read = 0;
//		int count;
//		int sum = 0;
//		while (read = fread(buffer, sizeof(int), 1, f)>0);
//		{
//			count++;
//			sum = sum + buffer;
//			printf("%d", buffer);
//		}
//		
//
//		fclose(f);
//	}
//	else
//	{
//		// problem
//		// error message
//	}
//
//}