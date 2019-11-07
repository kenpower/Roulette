#include "Bet.h"

Bet::Bet(int amount, Outcome outcome): outcome(outcome), amountBet(amount)
{
}

int Bet::winAmount()
{
	return amountBet + outcome.getOdds() * amountBet;
}

int Bet::loseAmount()
{
	return amountBet;
}

std::string Bet::toString() const
{
	return to_string(amountBet) + " on " + outcome.toString();
}
