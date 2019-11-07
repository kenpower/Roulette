#include "Table.h"

void Table::placeBet(Bet bet)
{
}

Bet Table::takeBet()
{
	Bet betToReturn = bets[0];
	bets.erase(bets.begin());
	return betToReturn;
}

bool Table::hasBets()
{
	return !bets.empty();
}

std::string Table::toString()
{
	return std::string();
}

bool Table::isValid()
{
	return false;
}
