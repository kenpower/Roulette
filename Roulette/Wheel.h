#pragma once
#include <vector>
#include "Bin.h"

using namespace std;

const int NUMBER_OF_BINS{ 38 };

class Wheel
{
private:
	vector<Bin> bins;

public:
	Wheel(bool = true);
	void addOutcome(int, Outcome);
	Bin next();
	Bin get(int);
};

