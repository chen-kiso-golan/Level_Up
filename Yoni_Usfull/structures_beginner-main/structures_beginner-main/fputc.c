#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


int main253253()
{
    ////r - open for reading
	////w- open for writin (override alredy existed data)
	////a-open for append to end of file

	///*taxk1
	
	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\data.txt";

	FILE* f = fopen(fileNema,"w");

	for (int i = 0; i < 100; i++)
	{
		if (f != NULL) {

			fputc('*', f);
			fputc('\n', f);
		}
		else {
			//eror
			f = fopen(fileNema, "r");
		}
	}
	fclose(f);
	//*/


	///*taxk1
	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\data2.txt";

	FILE* f = fopen(fileNema, "w");

	if (f != NULL) {
		for (int i = 0; i < 10; i++)
		{
		fputc('\n', f);

			for (int i = 0; i < 10; i++)
			{
				fputc('A', f);
			}	
		}
	}
	else {
		////eror
		f = fopen(fileNema, "r");
	}
	fclose(f);

	//*/


	///*taxk3

	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\data3.txt";

	FILE* f = fopen(fileNema, "w");

	if (f != NULL) {
		int line = 0;
		scanf("%d", &line);

		for (int i = 0; i < line; i++)
		{
		fputc('\n', f);

			for (int i = 0; i < 50; i++)
			{
				fputc('*', f);
			}
		}
	}
	else {
		////eror
		f = fopen(fileNema, "r");
	}
	fclose(f);

	//*/


	////*taxk4

	char* fileNema = "C:\\level-up\\c lesson-level up\\source\\repos\\24.08.2022\\index\\data4.txt";

	FILE* f = fopen(fileNema, "w");

	if (f != NULL) {

		int num_of_show = 0;
		char str[100];
		
		
		printf("enter the string you wont:");
		gets(str);
		int len = strlen(str);
		
		printf("enter number of row:");
		scanf("%d", &num_of_show);

		for (int i = 0; i < num_of_show; i++)
		{
			fputc('*', f);

			for (int j = 0; j < 10; j++)
			{
				fputc(str[j], f);
			}
		}
	}
	else {
		////eror
		f = fopen(fileNema, "r");
	}
	fclose(f);

	//*/
}
