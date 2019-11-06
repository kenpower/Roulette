#pragma once
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
	std::string toString();
};
