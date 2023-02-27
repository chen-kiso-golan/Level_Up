#pragma once
#include "Animal.h"


class Dog : public Animal
{
private:
	int GurimCount=0;
public:
	void AddGurimCount();
	void PrintGurimCount();
	void PrintCodeName_GurimCount();
};

