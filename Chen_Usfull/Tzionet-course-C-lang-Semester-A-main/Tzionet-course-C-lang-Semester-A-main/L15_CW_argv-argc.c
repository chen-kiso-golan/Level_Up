//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//
//void textcopy(char* filesrc, char* fileDest)
//{
//	int count = 0;
//	int read = 0;
//	char tmp;
//	char* memory;
//	FILE* fsrc;
//	FILE* fdest;
//
//	fsrc = fopen(filesrc, "r");
//	if (filesrc) {
//		while ((read = fread(&tmp, sizeof(char), 1, fsrc)) > 0)
//		{
//			count = count + read;
//		}
//		fclose(fsrc);
//	}
//	else
//	{
//		//eror
//	}
//
//	memory = malloc(sizeof(char) * count);
//
//	fsrc = fopen(filesrc, "r");
//	if (filesrc) {
//		fread(memory, sizeof(char), count, fsrc);
//		fclose(fsrc);
//	}
//	else
//	{
//		//eror
//		return;
//	}
//
//
//
//	fdest = fopen(fileDest, "w");
//	if (fdest) {
//
//		fwrite(memory, sizeof(char), count, fdest);
//		fclose(fdest);
//	}
//	else
//	{
//		//eror
//	}
//}
//
//
//
//int main(int argc, char* argv[])
//{
//  //task 1-12
//	//textcopy("C:\\level - up\\c lesson - level up\\source\\repos\\4.9.2022\\argc_argv\\x64\\Debug\\testcopy.txt", "C:\\level - up\\c lesson - level up\\source\\repos\\4.9.2022\\argc_argv\\x64\\Debug\\testcopy_yoni.txt");
//
//	//textcopy(argv[1], argv[2]);
//
//  //task 13
//	return 0;
//}