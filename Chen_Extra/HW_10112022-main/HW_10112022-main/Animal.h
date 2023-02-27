#pragma once

#define Max_name 100
class Animal
{
public:
	int code;
	char name[Max_name];

	void PutInCode(int acode);
	void PrintCode();
	void PutName(char aname[Max_name]);
	void PrintName();
};

