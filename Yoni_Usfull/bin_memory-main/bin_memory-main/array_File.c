#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main65463453()
{
	
	int arr[5] = { 23,44,56,100,1009 };
	int arr2[5];
	FILE* f = fopen("array.dat", "w");

	if (f != NULL)
	{
		//arr = &arr[0]
		int written = fwrite(arr, sizeof(int), 5, f);
		fclose(f);
	}
	else
	{
		// problem
		// error message
	}

		f = fopen("array.dat", "r");

		if (f != NULL)
		{
			
			int read = fread(arr, sizeof(int), 5, f);
			int read1 = fread(arr2, sizeof(int), 2, f);
			fclose(f);
		}
		else
		{
			// problem
			// error message
		}
}







