#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
/*
void read_file()
{
	int sumid = 0;
	struct Data {
		int id;
		int age;
	};

	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L11 - haim 290822\\linkedlist.dat", "r");
	struct Data a;

	if (f)
	{
		while (fread(&a, sizeof(struct Data), 1, f))
		{
			sumid = sumid + a.id;
		}
		printf("%d", sumid);
		fclose(f);
	}
	else
	{
		//error
	}
}



int main764874() {

//task1
	struct Data {
		int id;
		int age;
	};

	printf("how many Data structrs you want?\n");
	int size;
	scanf("%d", &size);

	struct Data* list;
	struct Data* ImHere;
	list = (struct Data*) malloc(sizeof(struct Data) * size);
    ImHere = list;

	for (int i = 0; i < size; i++) {
		printf("enter your id and age:\n");
		scanf("%d %d", &ImHere->id, &ImHere->age);
		ImHere++;
	}

	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L11 - haim 290822\\linkedlist.dat", "w");
	if (f)
	{
		fwrite(list, sizeof(struct Data), size, f);
		fclose(f);
	}
	else
	{
		// error message
	}

//task2 - לא עובדת מתאפס רק סיבוב אחד אחרי
	struct Data {
		int id;
		int age;
	};

	struct Data* origin;
	int read = 1;
	int SumId = 0;
	
	FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L11 - haim 290822\\linkedlist.dat", "r");
	if (f1)
	{
		
		while (read != 0)
		{
			
			origin = (struct Data*)malloc(sizeof(struct Data) * 1);
			read = fread(origin, sizeof(struct Data), 1, f1);
			SumId = SumId + origin->id;
			free(origin);
		}
		
		printf("the sum of your id is: %d", SumId);
		fclose(f1);
	}
	else
	{
		// error message
	}


//task2-yoni
	read_file();



					

	return 0;
} */