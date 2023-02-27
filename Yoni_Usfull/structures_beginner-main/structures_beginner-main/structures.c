#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


int main432432432()
{
	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Item kuku;
	struct Item kuku2;

	kuku.barcode = 111;
	kuku.price = 12;
		strcpy(kuku.name, "cola");
		strcpy(kuku.color, "black");


	kuku2.price = 9;
		strcpy(kuku2.name, "pepsi");
		strcpy(kuku2.color, "black");
		kuku2.price = 22;


		FILE* f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\ItemList.dat", "w");
		if (f != NULL) {

			fwrite(&kuku, sizeof(struct Item), 1, f);
			fwrite(&kuku2, sizeof(struct Item), 1, f);
			fclose(f);


			struct Item ItemToReead;
			FILE* f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\ItemList.dat", "r");
			if (f != NULL) {

				//how many structcher read
				int alreadyRead = fread(&ItemToReead,sizeof(struct Item),1,f);

				while (alreadyRead != 0)
				{
					alreadyRead = fread(&ItemToReead, sizeof(struct Item), 1, f);
				}
			
				fclose(f);
			}
		}

		//printf("Item: % s Price:%d\n\n", kuku.name, kuku.price);


		/*struct Item itemList[10];

		printf("pleas enter structer:\n");
		for (int i = 0; i < 2; i++)
		{			
			scanf("%d %s %s %d", &itemList[i].barcode, itemList[i].name, itemList[i].color, &itemList[i].price);
			printf("pleas enter enader structer:\n");
		}

		for (int i = 0; i < 2; i++)
		{
			printf("%d %s %s %d\n", itemList[i].barcode, itemList[i].name, itemList[i].color, itemList[i].price);
			
		}*/


		

	return 0;
}