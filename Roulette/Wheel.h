#pragma once
#include <vector>
#include "Bin.h"

using namespace std;



class Wheel
{
private:
	vector<Bin> bins;
	static const int NUMBER_OF_BINS{ 38 };

public:
	Wheel(bool = true);
	void addOutcome(int, Outcome);
	Bin next();
	Bin get(int);
};

