#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

#include "ball.h"
#include "car.h"
#include "Blog.h"

int main()
{

	////**********Q1 Ball***********
	//ball mondi;

	//mondi.jump();
	//strcpy_s(mondi.color, "red");
	//mondi.size = 10;
	//mondi.radios = 3.14;

	
	//std::cout << "the color is: " << mondi.color << "\n";
	//std::cout << "the size is: " << mondi.size<< "\n";
	//std::cout << "the radios is: " << mondi.radios;


	////**********Q2 Ball***********
	//car car1(3623451);

	//for (int i = 0; i < 5; i++) {
	//	car1.Drive(i+10);
	//}
	//strcpy_s(car1.color, "Blue");
	//strcpy_s(car1.NameOfCar, "Nissan");

	//car1.PlaceInCar = 5;

	//car1.PrintStatus();



	////**********Q4 Ball***********

	char str[] = "yoni.txt";
	char strText[] = "we are family, and we work very hard";
	char strText1[] = "yoni is a good name for a child";

	Blog FamilyBlog(str, 50);

	std::cout << FamilyBlog.name<<"\n";
	

	FamilyBlog.AddLine(strText);
	FamilyBlog.AddLine(strText1);
	FamilyBlog.AddLine(strText1);
	FamilyBlog.SaveInFile();
	FamilyBlog.LodeFromFile();
	FamilyBlog.Print();


}

