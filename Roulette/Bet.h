#pragma once
#include <string>
#include "Outcome.h"
#include "InvalidBet.h"

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

	int getAmountBet() const { return amountBet; };
	Outcome getOutcome() const { return outcome; }
};

