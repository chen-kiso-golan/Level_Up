#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

int uncreas(int num) {
	num++;

	return num;
}

int main() {

	int i = 11;
	i= uncreas(i);
	printf("%d", i);


	return 0;
}