#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main4328989()
{

	struct Student {

		int age;
		char name[100];
		int classLevel;
	};

	struct Student s = { 20,"Amos", 1 };

	FILE* f = fopen("oneStudent.dat", "w");

	if (f) {
		fwrite(&s, sizeof(struct Student), 1, f);
		fclose(f);
	}
	else {
		// error
	}

	/////////////////////////////////////////////////////////

	//prepare memory


	struct Student* list;
	struct Student* currentStudent;

	int size = 3;
	list = malloc(sizeof(struct Student) * size);
	currentStudent = list; 

	currentStudent->age = 30;
	strcpy(currentStudent->name, "Matan");
	currentStudent->classLevel = 2;
	currentStudent++;

	currentStudent->age = 22;
	strcpy(currentStudent->name, "Amos");
	currentStudent->classLevel = 3;
	currentStudent++;

	currentStudent->age = 35;
	strcpy(currentStudent->name, "Amram");
	currentStudent->classLevel = 4;
	currentStudent++;

	currentStudent->age = 120;
	strcpy(currentStudent->name, "Yaacov");
	currentStudent->classLevel = 100;
	

	// save	Memory

	f = fopen("Stude.dat", "w");
	fwrite(list, sizeof(struct Student), size, f);
	fclose(f);

	free(list);
}