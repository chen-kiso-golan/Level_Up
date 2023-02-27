#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)



void Log(char massage[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;

	timeinfo = localtime(&t);
	char str[100];
	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon +1, timeinfo->tm_year +1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);

	FILE* f = fopen("Yoni_log.log", "a");
	fputs("\n\n", f);
	fputs(str, f);
	fputs("\n\n", f);

	
	fclose(f);
}

void LogError(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", message);
	Log(newMessage);
}

void EventLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", message);
	Log(newMessage);
}

void text(char usernum[100])
{
	FILE* f1 = fopen("numbers.txt", "a");
	if (f1) {

		for (int i = 0; i < atoi(usernum); i++)
		{
			char usernum2[100];
			itoa(i, usernum2, 10);
			fputs(usernum2, f1);
			fputs("\n", f1);
		}
		fclose(f1);
	}
	else
	{
		LogError("the file did not open");	
		//error
	}
	
}



int main()
{
	EventLog("the program is Start");

	char user[100];
	printf("please enter a number:");
	scanf("%s", &user);


	Log(user);

	text(user);




	char str1[1000];

	FILE* f = fopen("numbers.txt", "r");

	while (fgets(str1, 100, f) != NULL)
	{
		printf("%s", str1);
	}

	fclose(f);

	EventLog("the program is End");

	return 0;
}