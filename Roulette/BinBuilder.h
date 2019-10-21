#pragma once
#include "Wheel.h"

class BinBuilder
{

public:
	BinBuilder();
	void BuildBins(Wheel&);

	void straightBets(Wheel&);
	void splitBets(Wheel&);
	void streetBets(Wheel& wheel);
	void cornerBets(Wheel& wheel);
};

