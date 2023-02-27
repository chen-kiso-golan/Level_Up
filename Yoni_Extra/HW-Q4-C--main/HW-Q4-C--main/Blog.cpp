#include "Blog.h"

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#pragma warning(disable:4996)


Blog::Blog(char aname[100], int aBlogSize) {

	strcpy_s(this->name, aname);
	this->text = new char[aBlogSize];
	this->BlogSize = aBlogSize;
	this->TextEnd = this->text;

}

void Blog::AddLine(char* ptext) {
	int i = this->TextEnd - this->text;

	if ((this->TextEnd - this->text) < this->BlogSize) {
		strcpy(this->TextEnd, ptext);
		this->TextEnd = this->TextEnd + strlen(ptext);
		strcpy(this->TextEnd, ". ");
		this->TextEnd = this->TextEnd + 2;
	}
	LineCount++;
}

void Blog::SaveInFile() {
	FILE* f = fopen(name, "w");

	if (!f) {
		//error
	}
	else
	{
		fputs(text, f);
		fclose(f);
	}
}

void Blog::LodeFromFile() {
	char LoadText[1000];
	FILE* f = fopen(name, "r");

	if (!f) {
		//error
	}
	else
	{
		fgets(LoadText,1000, f);
		fclose(f);
	}
}



void Blog::Print() {
	std::cout << text<<"\n\n\n\n";
}
