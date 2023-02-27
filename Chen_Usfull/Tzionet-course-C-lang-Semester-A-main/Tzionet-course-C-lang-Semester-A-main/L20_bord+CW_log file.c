//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//
//void Log(char message[100]) {
//
//	time_t t;
//	time(&t);
//	struct tm* timeinfo;
//
//	timeinfo = localtime(&t);
//	char strTime[100];
//	sprintf(strTime, "%d.%d.%d-%d:%d:%d ", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//
//	FILE* f = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L20 - haim 110922\\log.log", "a");
//	fputs(strTime, f);
//	fputs(message, f);
//	fputs("\n", f);
//	fclose(f);
//}
//
//void LogError(char message[100]) {
//	char newMassage[100];
//	sprintf(newMassage, "ERROR - %s", message);
//	Log(newMassage);
//}
//
//void LogEvent(char message[100]) {
//	char newMassage[100];
//	sprintf(newMassage, "EVENT - %s", message);
//	Log(newMassage);
//}
//
//
//void txtFile(int intmessage2) {
//
//	FILE* f1 = fopen("C:\\Users\\behap\\Desktop\\tsionet\\all the class\\L20 - haim 110922\\numbers.txt", "a");
//	if (!f1) {
//		LogError("the opening of the file numbers has failed. such file has not been found.\n");
//	}
//	else {
//		LogEvent("the opening of the file numbers has started.\n");
//		for (int i = 0; i <= intmessage2; i++) {
//			char charUser[20];
//			itoa(i, charUser, 10);
//			fputs(charUser, f1);
//			fputs("\n", f1);
//		}
//		LogEvent("the opening of the file numbers has ended.\n");
//	}
//	
//	fclose(f1);
//}
//
//int main() {
//
////CW1
//
//	LogEvent("the program of writing the users number has started.\n");
//
//	int numUser;
//	char charUser[20];
//	printf("enter a num:\n");
//	scanf("%d", &numUser);
//	itoa(numUser, charUser, 10);
//	Log(charUser);
//	
//	LogEvent("the program of writing the users number has ended.\n");
//
//	//---------------
//
//	txtFile(numUser);
//
//	//---------------
//
////bord
//
//	//FILE* f = fopen("myProg.log", "w");
//
//	//fputs("line1\n", f);
//	//fputs("line1\n", f);
//	//fputs("line1\n", f);
//	//fclose(f);
//
//
//	//char str[1000];
//
//	//f = fopen("myProg.log", "r");
//
//	//while (fgets(str, 1000, f) != NULL)
//	//{
//	//	printf("%s", str);
//	//}
//
//	//fclose(f);
//
//
//	return 0;
//}