#pragma once
#include <vector>
#include <map>
#include "Bin.h"
#include "OutcomeNotFoundException.h"

using namespace std;

class Wheel
{
private:
	vector<Bin> bins;
	static const int NUMBER_OF_BINS{ 38 };
	static const int ZEROZERO_INDEX{ 37 };

	map<string, Outcome> allOutcomes;

public:
	Wheel(bool = true);
	void addOutcome(int, Outcome);
	Bin next();
	Bin get(int);
	Bin get00();
	Outcome getOutcome(string) const;

};

