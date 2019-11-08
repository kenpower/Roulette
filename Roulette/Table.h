#pragma once
#include<vector>
#include "Bet.h"
#include "Wheel.h"


class Table
{
	static const int DEFAULT_LIMIT{ 100 };
	static const int DEFAULT_MINIMUM{ 2 };
	const int limit;
	const int minimum;

	std::vector<Bet> bets;

public:
	Table(const std::vector<Bet> _bets, int _limit = DEFAULT_LIMIT, int _minimum = DEFAULT_MINIMUM)
		: bets(_bets), limit(_limit), minimum(_minimum) {}

	void placeBet(Bet bet);

	Bet takeBet();

	bool hasBets();

	std::string toString();

	bool isValid(const Wheel& wheel);

};

