#include <string.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

#include "Dog.h"

void Dog::AddGurimCount() {
	GurimCount = GurimCount +1;
}


void Dog::PrintGurimCount() {
	std::cout << "you have " << GurimCount << " Dog Gurim\n";
}

void Dog::PrintCodeName_GurimCount() {
	PrintCode();
	PrintName();
	PrintGurimCount();
}