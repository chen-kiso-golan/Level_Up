#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


int main()
{

	
	/*struct Item    //not working
	{
		char one[100];
		char two[100];
		char tree[100];
		char fhore[100];
		char five[100];
	};

	struct Item kuku;

	strcpy(kuku.one, "a");
	strcpy(kuku.two, "b");
	strcpy(kuku.tree, "c");
	strcpy(kuku.fhore, "d");
	strcpy(kuku.five, "e");

	FILE* f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\StarList.txt", "w");
	if (f != NULL) {

		fwrite(&kuku, sizeof(struct Item), 1, f);

		fclose(f);
	}*/


	/*task1
	
	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\StarList.txt";

	FILE* f = fopen(fileNema, "w");

	if (f != NULL) {
		
		

		for (int row = 1; row <= 5; row++)
		{
			for (int star = 0; star < row; star++)
			{
				fputc('*', f);
			}
			fputc('\n', f);
		}
	}
	else {
		//eror
		f = fopen(fileNema, "r");
	}
	fclose(f);

	//*/



	/*task2

	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\NumberList.txt";

	FILE* f = fopen(fileNema, "w");

	if (f != NULL) {


		int numplus = '1';
		for (int row = 0; row < 4; row++)
		{
			for (int i = 0; i < 10; i++)
			{
				fputc(numplus, f);
			}
			numplus++;
			fputc('\n', f);
		}
	}
	else {
		//eror
		f = fopen(fileNema, "r");
	}
	fclose(f);

	//*/



	/*task3
	printf("please enter num of file you want:");
	int num=1;
	int admin_num_of_file = 4;
	

	char str1[100];
	char str2[200] = "file";

	for (int i = 0; i < admin_num_of_file; i++)
	{
		sprintf(str1, "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\%s%d%s", str2, num, ".txt");
		num++;
		char* fileNema = str1;

		FILE* f = fopen(fileNema, "w");

		if (f != NULL) {


			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					fputc('*', f);
				}

				fputc('\n', f);
			}
		}
		else {
			//eror
		}
		
		fclose(f);
	}
//*/


/*task4
	
	struct Car
	{
		char Name[100];
		char Model[10];
		int On_Road;
		int car_Number;
	};

	struct Car nisan;

	
	strcpy(nisan.Name, "nisan");
	strcpy(nisan.Model, "Alamera");
	nisan.On_Road = 2003;
	nisan.car_Number = 3623451;

	printf(" the name of your car is: %s\n the  model is: %s\n the yaer on road is: %d\n the car number is: %d\n\n", nisan.Name, nisan.Model, nisan.On_Road, nisan.car_Number);
//*/


	/*task5

	struct Car
	{
		char Name[100];
		char Model[10];
		int On_Road;
		int car_Number;
	};

	struct Car nisan[4];

	printf("pleas enter data of car:\n");

	for (int i = 0; i < 2; i++)
	{
		scanf("%s %s %d %d", nisan[i].Name, nisan[i].Model, &nisan[i].On_Road, &nisan[i].car_Number);
	}

	for (int i = 0; i < 2; i++)
	{
		printf("Name:%s Model:%s On_Road:%d Car_Number:%d", nisan[i].Name, nisan[i].Model, nisan[i].On_Road, nisan[i].car_Number);
		printf("\n");
	}

	//*/



	/*task6

	struct Item
	{
		char name[10];
		char symbol[2];
		char code[3];
	};

	struct Item yoyo;
	strcpy(yoyo.name, "yoni");
	strcpy(yoyo.symbol, "wo");
	strcpy(yoyo.code, "524");

	
	FILE* f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\yoyoItem.txt", "w");

	if (f != NULL) {

		fwrite(&yoyo, sizeof(struct Item), 1, f);

	}
	else
	{
		//eror
	}
		fclose(f);
	
		//*/



			///*task7

		struct Item
		{
			char name[10];
			char symbol[2];
			char code[3];
		};

		struct Item yoyo[2];
		
		printf("pleas enter data of car:\n");

		for (int i = 0; i < 2; i++)
		{
			scanf("%s %s %s", yoyo[i].name, yoyo[i].symbol, yoyo[i].code);


		}


		FILE* f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\yoyoI.txt", "w");

		if (f != NULL) {

			fwrite(&yoyo, sizeof(struct Item), 1, f);

		}
		else
		{
			//eror
		}
		fclose(f);

		//*/

	return 0;
}