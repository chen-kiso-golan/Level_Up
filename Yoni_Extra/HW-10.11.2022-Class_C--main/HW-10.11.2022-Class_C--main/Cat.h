#pragma once
#include "dog.h"
class Cat : public Dog
{
private:
	int CatGurimCount = 0;
public:
	int age = 0;
	void AddCatGurimCount();
	void PrintCatGurimCount();
	void PrintCodeName_CatGurimCount_Age();
};

