#pragma once
#include <string>
#include "Outcome.h"

class Bet
{
private:
	int amountBet;
	Outcome outcome;

public:
	Bet(int amount, Outcome outcome);

	int winAmount();
	int loseAmount();
	std::string toString() const;

	bool operator==(const Bet& rhs) const { return this->toString().compare(rhs.toString()) == 0; }
};

