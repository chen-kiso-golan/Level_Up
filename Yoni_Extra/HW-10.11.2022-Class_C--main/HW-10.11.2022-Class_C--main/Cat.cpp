#include <string.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

#include "Cat.h"
//class Cat : public Dog
//{
//private:
//	int CatGurimCount = 0;
//public:
//	int age = 0;
//
//	void PrintCatGurimCount();
//	void PrintCodeName_CatGurimCount_Age();
//};

void Cat::AddCatGurimCount() {
	CatGurimCount = CatGurimCount + 1;
}


void Cat::PrintCatGurimCount() {
	std::cout << "you have " << CatGurimCount << " Cat Gurim\n";
}

void Cat::PrintCodeName_CatGurimCount_Age() {
	PrintCode();
	PrintName();
	PrintCatGurimCount();
	std::cout << "your cat is " << age << " years old\n";
}