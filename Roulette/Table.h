#pragma once
#include<vector>
#include "Bet.h"


class Table
{
	const int LIMIT = 100;
	const int MINIMUM = 1;

	std::vector<Bet> bets;

public:
	Table(const std::vector<Bet> _bets) : bets(_bets) {}

	void placeBet(Bet bet);

	Bet takeBet();

	bool hasBets();

	std::string toString();

	bool isValid();

};

