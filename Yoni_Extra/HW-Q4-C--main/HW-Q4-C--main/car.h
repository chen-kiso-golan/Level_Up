#pragma once



class car
{
public:
	
	int km=0;
	char color[10];
	char NameOfCar[10];
	int NumCar=0;
	int PlaceInCar=0;
	int countDrive=0;

	car(int aNumCar);
	void Drive(int akm);
	void PrintStatus();


};

