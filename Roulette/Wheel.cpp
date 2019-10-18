#include <stdlib.h>
#include "Wheel.h"

const int NUMBER_OF_BINS{ 38 };

Wheel::Wheel(bool randomSeed) : bins(NUMBER_OF_BINS, Bin{})
{
	if (!randomSeed) {
		srand(1);
	}

}

void Wheel::addOutcome(int index, Outcome outcome)
{
	bins[index].insert(outcome);
}

Bin Wheel::next()
{
	int randomIndex = rand() % NUMBER_OF_BINS;

	return this->get(randomIndex);
}

Bin Wheel::get(int index)
{
	return bins[index];
}
