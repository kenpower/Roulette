#include "Bet.h"

Bet::Bet(int amount, Outcome outcome): outcome(outcome)
{
}

int Bet::winAmount()
{
	return 0;
}

int Bet::loseAmount()
{
	return 0;
}

std::string Bet::toString()
{
	return std::string();
}
