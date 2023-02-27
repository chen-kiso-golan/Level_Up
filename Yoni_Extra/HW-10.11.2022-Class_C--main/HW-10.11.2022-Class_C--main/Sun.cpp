#include <string.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

#include "Sun.h"

void Sun::FatherAge() {
	std::cout <<"the new and virtual age of your Father is: "<< this->Age + 10<<"\n\n\n\n";
}