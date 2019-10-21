#pragma once
#include "Wheel.h"

class BinBuilder
{

public:
	BinBuilder();
	void BuildBins(Wheel&);

	void straightBets(Wheel&);
	void splitBets(Wheel&);
};

