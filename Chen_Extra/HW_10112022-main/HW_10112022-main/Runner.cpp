#include <string.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

#include "Runner.h"

void Runner::Run() {

	list = new BroCode;
	list->play();
	std::cout << "\n\n\n";

	RunCat = new Cat;
	RunDog = new Dog;

	std::cout << "Cat Data:\n";
	RunCat->age = 15;
	RunCat->code = 28;
	strcpy_s(RunCat->name, "panda");
	RunCat->AddCatGurimCount();
	RunCat->AddCatGurimCount();
	RunCat->AddCatGurimCount();
	RunCat->AddCatGurimCount();
	RunCat->PrintCodeName_CatGurimCount_Age();
	std::cout << "\n\n\n";

	std::cout << "Dog Data:\n";
	RunDog->code = 10;
	strcpy_s(RunDog->name, "Kaza");
	RunDog->AddGurimCount();
	RunDog->AddGurimCount();
	RunDog->PrintCodeName_GurimCount();
	std::cout << "\n\n\n";

	std::cout << "have a nice day:\n";

	std::cout << "\n\n\n";
	
	delete list;
	delete RunDog;
	delete RunCat;


}