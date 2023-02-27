//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#pragma warning (disable : 4996)
//
//#define FILE_NAME "Data3.bin"
//#define Version 1
//
//
//typedef struct s_Item {
//	int val;
//	int key;
//	struct s_Item* Next;
//	struct s_Item* Prev;
//}t_Item;
//
//typedef struct {
//	int version;
//	int serialNum;
//	int ItemCount;
//	char reserve[100];
//
//}t_headerFile;
//
//t_Item* Head = NULL;
//t_Item* Tail = NULL;
//int Counter = 0;
//
////t_headerFile fileHeader;
////fileHeader.version = 1;
////fileHeader.serialNum = 123;
////fileHeader.ItemCount = Counter;
//
//t_Item* NewItem(int val, int key)
//{
//	t_Item* ret = (t_Item*)malloc(sizeof(t_Item));
//
//	ret->key = key;
//	ret->val = val;
//	ret->Next = NULL;
//	ret->Prev = NULL;
//	Counter++;
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
//t_Item* search(int key)
//{
//
//	t_Item* currentItem = Head;
//	t_Item* List = Head;
//
//	while (List != NULL)
//	{
//		List = currentItem;
//		currentItem = currentItem->Next;
//		if (List->key == key) {
//
//			printf("\nthe kay is:%d\nand the value is %d\n", List->key, List->val);
//			return List;
//		}
//		else if (currentItem == NULL) {
//			printf("*");
//			return;
//		}
//	}
//
//}
//
//void Update(int key, int val) {
//
//	t_Item* currentItem = Head;
//	t_Item* List = Head;
//
//	while (List != NULL)
//	{
//		List = currentItem;
//		currentItem = currentItem->Next;
//		if (List->key == key) {
//
//			List->val = val;
//			printf("\nthe kay is:%d\nand the new val is %d\n", List->key, List->val);
//
//			return;
//		}
//		else if (currentItem == NULL) {
//			printf("\nthe key is not found!!!\n");
//			return;
//		}
//	}
//}
//
//void Remove(int key)
//{
//	t_Item* currentItem;
//	t_Item* RemoveFromList;
//	Counter--;
//
//	RemoveFromList = search(key);
//	if (Counter == 1) {
//		free(RemoveFromList);
//	}
//	else {
//		if (Head == RemoveFromList) {
//
//			RemoveFromList->Next->Prev = NULL;
//			Head = Head->Next;
//			free(RemoveFromList);
//		}
//		else if (Tail == RemoveFromList) {
//
//			RemoveFromList->Prev->Next = NULL;
//			Tail = Tail->Prev;
//			free(RemoveFromList);
//		}
//		else
//		{
//			currentItem = RemoveFromList;
//			RemoveFromList->Next->Prev = currentItem->Prev;
//			RemoveFromList->Prev->Next = currentItem->Next;
//			free(RemoveFromList);
//		}
//	}
//
//}
//
//void SaveFile(filename) {
//	FILE* f = fopen("filename", "w");
//	if (!f) {
//		// error
//		return 1;
//	}
//
//	//write the header into file
//	t_headerFile fileHeader;
//	fileHeader.version = 1;
//	fileHeader.serialNum = 123;
//	fileHeader.ItemCount = Counter;
//
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
//}
//
//void ReadFile(filename) {
//
//	// read from file
//	FILE* f = fopen("filename", "r");
//	if (!f) {
//		// error
//		return;
//	}
//
//	t_headerFile headerOfFile;
//	int read = fread(&headerOfFile, sizeof(t_headerFile), 1, f);
//
//	if (read == 0) {
//		return;
//	}
//
//	//build the list
//	Head = NULL;
//	Tail = NULL;
//
//	for (int i = 0; i < headerOfFile.ItemCount; i++)
//	{
//		t_Item* curr = (t_Item*)malloc(sizeof(t_Item), 1, f);
//		read = fread(curr, sizeof(t_Item), 1, f);
//		NewItem(curr->val, curr->key);
//	}
//	
//}
//
//void PrintList()
//{
//	/*t_headerFile headerOfFile;
//	printf("the header is:\n");
//	printf("version: %d | serialNum: %d | ItemCount: %d\n", headerOfFile.version, headerOfFile.serialNum, headerOfFile.ItemCount);*/
//
//	t_Item* print_Item = Head;
//
//	while (print_Item != NULL) {
//		printf("key: %d  val: %d\n", print_Item->key, print_Item->val);
//		print_Item = print_Item->Next;
//	}
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
//int main() {
//
//	char user = 1;
//	int key;
//	int val;
//	char filename[20];
//
//	while (user != 'E') {
//		printf("\nplease enter:\nE-exit\nA-insert key and val to struct\nF-Search a value By key\nU-Updata key and valu from the last search\nD-To Remove the chozen key\nS-save the list with the header\nL-print the list By name of file\n");
//		scanf(" %c", &user);
//
//		switch (user) {
//		case 'E':
//			break;
//		case 'A':
//			printf("Please enter value number and key number you want to add:\n");
//			scanf("%d %d", &val, &key);
//			NewItem(val, key);
//			break;
//		case 'F':
//			printf("Please enter key number you want to search and print:");
//			scanf("%d", &key);
//			search(key);
//			break;
//		case 'U':
//			printf("Please enter key number and a new val number you want to add:\n");
//			scanf("%d %d", &key, &val);
//			Update(key, val);
//			break;
//		case 'D':
//			printf("Please enter key number you want to Remove:\n");
//			scanf("%d", &key);
//			Remove(key);
//			break;
//		case 'S':
//			printf("Please enter a file name you want to save:\n");
//			scanf("%s", &filename);
//			SaveFile(filename);
//			break;
//		case 'L':
//			printf("Please enter a file name you want to print:\n");
//			scanf("%s", &filename);
//			ReadFile(filename);
//			PrintList();
//			break;
//		default:
//			printf("try again\n");
//			break;
//		}
//	}
//	return 0;
//
//}