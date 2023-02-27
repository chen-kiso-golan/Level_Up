//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#pragma warning (disable : 4996)
//
//#include "Header_struct.h"
//
//#define FILE_NAME "Data3.bin"
//#define Version 1
//
////// sample for creating instance of typedef vs struct
////struct s_Item s;
////t_Item s1;
//
//
//t_Item* Head = NULL;
//t_Item* Tail = NULL;
//
//t_Item* NewItem(int val, int key)
//{
//	t_Item* ret= (t_Item*)malloc(sizeof(t_Item));
//
//	ret->key = key;
//	ret->val = val;
//	ret->Next = NULL;
//	ret->Prev = NULL;
//
//	if (Head == NULL) {
//		Head = ret;
//		Tail = ret;
//	}
//	else
//	{
//		ret->Prev = Tail;
//		Tail->Next = ret;
//		Tail = ret;
//	}
//
//	return ret;
//}
//
//t_Item2* NewItem2(int val, int key, int id)
//{
//	t_Item2* ret = (t_Item2*)malloc(sizeof(t_Item2));
//
//	ret->key = key;
//	ret->val = val;
//	ret->id = id;
//	ret->Next = NULL;
//	ret->Prev = NULL;
//
//	if (Head == NULL) {
//		Head = ret;
//		Tail = ret;
//	}
//	else
//	{
//		ret->Prev = Tail;
//		Tail->Next = ret;
//		Tail = ret;
//	}
//
//	return ret;
//}
//
//void freeMemory()
//{
//	t_Item* curr = Head;
//	while (curr != NULL)
//	{
//		curr = curr->Next;
//		free(Head);
//		Head = curr;
//	}
//
//}
//
//
//
//
//
//int main()
//{
//	//init
//	Head = NULL;
//	Tail = NULL;
//
//	//crearte 10 item
//	t_headerFile fileHeader;
//	fileHeader.ItemCount = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		NewItem(i * 100, i);
//		fileHeader.ItemCount++;
//	}
//	fileHeader.version = Version;
//	fileHeader.serialNum = 12345;
//
//
//
//	// save in file
//	FILE* f = fopen(FILE_NAME, "w");
//	if (!f) {
//		// error
//		return 1;
//	}
//
//	//write the header into file
//	fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
//
//	//write all iteams into file
//	t_Item* curr = Head;
//	while (curr != NULL)
//	{
//		fwrite(curr, sizeof(t_Item), 1, f);
//		curr = curr->Next;
//	}
//	fclose(f);
//
//	freeMemory();
//
//
//	// read from file
//	 f = fopen(FILE_NAME, "r");
//	if (!f) {
//		// error
//		return 1;
//	}
//
//	t_headerFile headerOfFile;
//	int read = fread(&headerOfFile, sizeof(t_headerFile), 1, f);
//
//		if (read == 0) {
//			return 1;
//		}
//	//build the list
//		Head = NULL;
//		Tail = NULL;
//
//		if (headerOfFile.version == 1) {
//		t_Item* curr;
//		int id = 0;
//
//			for (int i = 0; i < headerOfFile.ItemCount; i++)
//			{
//				curr = (t_Item*)malloc(sizeof(t_Item), 1, f);
//				read = fread(curr, sizeof(t_Item), 1, f);
//				t_Item2* newI = NewItem2(curr->val, curr->key, id);
//				
//				id++;
//
//				free(curr);
//			}
//		}
//		else if (headerOfFile.version == 2) {
//			//convert process
//			t_Item2* curr;
//			for (int i = 0; i < headerOfFile.ItemCount; i++)
//			{
//				curr = (t_Item2*)malloc(sizeof(t_Item2), 1, f);
//				read = fread(curr, sizeof(t_Item2), 1, f);
//				NewItem2(curr->val, curr->key, curr->id);
//
//				free(curr);
//			}
//		}
//
//	//free 
//	freeMemory();
//
//	return 0;
//}
//
