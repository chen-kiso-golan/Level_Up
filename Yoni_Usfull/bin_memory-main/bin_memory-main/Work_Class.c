#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main4324321()
{
	/*// task1
	FILE* f;

	short a;
	scanf("%hu", &a);

	f = fopen("num_user.bin", "w");
	// scanf "%hu" insted %d

	if (f != NULL)
	{
		fwrite(&a, sizeof(short), 1, f);

		fclose(f);
	}
	else
	{
		// problem
		// error message
	}
	//*/
	

	/*// task2

	FILE* f;
	int sum = 0;
	short a;

	scanf("%hu", &a);

	f = fopen("num_user.bin", "w");
	// scanf "%hu" insted %d

	if (f != NULL)
	{
		fwrite(&a, sizeof(short), 1, f);

		fclose(f);
	}
	else
	{
		// problem
		// error message
	}

	FILE* f1 = fopen("num_user.bin", "r");
	if (f != NULL)
	{
		int read = fread(&a, sizeof(short), 1, f1);
		sum = a * a;
		printf("%d", sum);
		fclose(f1);

	}
	else
	{
		// problem
		// error message
	}
	//*/


	/*// task3
	FILE* f;

	int a;

	f = fopen("num_array.bin", "w");


	if (f != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			fwrite(&a, sizeof(int), 1, f);
			scanf("%d", &a);
			a++;
		}	
		fclose(f);
	}
	else
	{
		// problem
		// error message
	}
	//*/



	/*// task4

	FILE* f;
	int a;
	int sum = 0;
	int read=1; // must dfine read num 1

	f = fopen("amir.bin", "r");


	if (f != NULL)
	{

		while (read != 0) { // posibol to to it for loop: for(int i = 0; i<10; i++)
			read = fread(&a, sizeof(int), 1, f);
			printf("%d\n", a);
			sum = sum + a;
		}
		printf("%d", sum);
		fclose(f);
	}
	else
	{
		// problem
		// error message
	}
	//*/



	///*// task5

		FILE* f;
		int a;
		int read = 1;
	
		struct Item {
			int barcode;
			int price;
			char name[100];
			char color[100];
		};

		struct Item prodact;
		prodact.barcode = 585;
		prodact.price = 18;
		strcpy(prodact.name, "cofee");
		strcpy(prodact.color, "black");

		f = fopen("yoni.bin", "w");


		if (f != NULL)
		{
			fwrite(&prodact, sizeof(struct Item), 1, f);
			
			
			fclose(f);
		}
		else
		{
			// problem
			// error message
		}

		f = fopen("yoni.bin", "r");
			if (f != NULL)
			{
				while (read != 0) {
					read = fread(&prodact, sizeof(struct Item), 1, f);	
				}
				printf("%d\n", prodact.barcode);
				
				fclose(f);
			}
			else
			{
				// problem
				// error message
			}
		//*/

}







