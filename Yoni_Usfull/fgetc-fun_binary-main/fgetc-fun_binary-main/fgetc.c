#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main()
{
	FILE* f;
	int zero='0';
	int countI = 0;
	int num_count;

	f = fopen("C:\\level-up\\c lesson-level up\\source\\repos\\21.08.2022\\HW3.txt", "r");
	if (f != NULL)
	{
		char ch = fgetc(f);

		while (ch != EOF)
		{

			if (ch != 'c' && ch != 'i') {
				num_count = ch - zero;
			}			
			else {
			
				if (ch == 'i') {

					int* New_Memory_Int = malloc(sizeof(int) * num_count);
					int* OriginalC = New_Memory_Int;
					for (int i = 0; i < num_count; i++)
					{
						printf("please enter number to memory for int:\n");
						scanf("%d", New_Memory_Int);
						New_Memory_Int++;
					}
					free(OriginalC);
				}

				else {
					char* New_Memory_char = malloc(sizeof(char) * num_count);
					char* OriginalI = New_Memory_char;
					for (int i = 0; i < num_count; i++)
					{
						printf("please enter number to memory for char:\n");
						scanf(" %c", New_Memory_char);
						New_Memory_char++;
					}
					free(OriginalI);
				}
			}
			ch = fgetc(f);
		}
		fclose(f);	
	}
	else
	{
		// problem
		// error message
	}
}