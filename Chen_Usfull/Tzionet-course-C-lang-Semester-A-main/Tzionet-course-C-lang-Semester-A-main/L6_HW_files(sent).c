#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

/*
int main87978() {

//HW6 - last quetion, sent to haim as a mini test
	
	FILE* f;
	f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L6 - haim 220822\\HW2_3.txt", "r");
	
	//if the file is not found
	if (f == NULL) {
		printf("error, could not find your file");
	}
	
	//if the file is found
	else {
		char read = fgetc(f);
		
		while (read != EOF) {
			char NumOf = read - '0';
			read = fgetc(f);
			
			if (read == 'c') {
				char* NewCharMemory = malloc(sizeof(char) * NumOf);
				char* OriginalC = NewCharMemory;
				printf("you now have %d new char type memory\n please enter their values:\n", NumOf);
				for (int i = 0; i < NumOf; i++) {
					scanf(" %c", NewCharMemory);
					NewCharMemory++;
				}
				printf("thank you!\n");
				free(OriginalC);
				read = fgetc(f);	
			}
			
			else if (read == 'i') {
				int* NewIntMemory = malloc(sizeof(int) * NumOf);
				int* OriginalI = NewIntMemory;
				printf("you now have %d new intiger type memory\n please enter their values:\n", NumOf);
				for (int i = 0; i < NumOf; i++) {
					scanf("%d", NewIntMemory);
					NewIntMemory++;
				}
				printf("thank you!\n");
				free(OriginalI);
				read = fgetc(f);
			}
		}
	}
	fclose(f);


	return 0;
}

*/