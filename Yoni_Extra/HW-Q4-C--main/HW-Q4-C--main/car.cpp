#include <iostream>
#include <string.h>
#pragma warning(disable:4996)


#include "car.h"

car::car(int aNumCar) {

	NumCar = aNumCar;
}

void car::Drive(int akm) {
	km = km + akm;
	countDrive++;
}

void car::PrintStatus() {
	std::cout << "the name of car is "<<NameOfCar <<"\n";
	std::cout << "the number of car is: " << NumCar << "\n";
	std::cout << "the color of car is: " << color << "\n";
	std::cout << "you have " << PlaceInCar << " place in your car\n";
	std::cout << "you drive with your car " << km << "km\n";
	std::cout << "you Drive in your car: " << countDrive<< " times\n";
	std::cout << "your Avarge km per drive is: " << km/countDrive << "km\n";
}