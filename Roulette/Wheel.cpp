#include <stdlib.h>
#include <time.h>
#include "Wheel.h"

Wheel::Wheel(bool randomSeed) : bins(NUMBER_OF_BINS, Bin{})
{
	srand(time(NULL));

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

Bin Wheel::get00()
{
	return bins[ZEROZERO_INDEX];
}
