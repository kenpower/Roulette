#include "Table.h"

void Table::placeBet(Bet bet)
{
}

Bet Table::takeBet()
{
	return Bet(0, Outcome("",0));
}

bool Table::hasBets()
{
	return false;
}

std::string Table::toString()
{
	return std::string();
}

bool Table::isValid()
{
	return false;
}
