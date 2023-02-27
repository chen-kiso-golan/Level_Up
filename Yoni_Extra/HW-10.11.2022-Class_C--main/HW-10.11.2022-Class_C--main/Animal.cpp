#include <string.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)


#include "Animal.h"

void Animal::PutInCode(int acode) {
	code = acode;
}

void Animal::PutName(char aname[Max_name]) {
	strcpy_s(name, aname);
}

void Animal::PrintCode() {
	std::cout << "this is your Animal code man: " << code<< "\n";
}

void Animal::PrintName() {
	std::cout << "this is your Animal name man: " << name << "\n";
}