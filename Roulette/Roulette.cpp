// Roulette.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Outcome.h"

int main()
{
	Outcome a("Odd", 2);
	Outcome b("Street 1-2-3", 11);

	if (a == b) {
		//do something
	}

    std::cout << "Hello World!\n";

}

