#pragma once
#include <vector>
#include "Bin.h"

using namespace std;

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

