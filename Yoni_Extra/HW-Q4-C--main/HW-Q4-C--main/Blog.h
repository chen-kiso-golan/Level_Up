#pragma once


class Blog
{
public:
	char name[100];
	char * text;
	int BlogSize;
	
	char * TextEnd;
	int LineCount;
	Blog(char name[100], int aBlogSize);
	
	void SaveInFile();
	void LodeFromFile();
	void AddLine(char* ptext);
	void Print();
};

