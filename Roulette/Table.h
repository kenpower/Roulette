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

	//hide underlying collection type from clients
	using BetCollection = std::vector<Bet>;
	BetCollection bets;

public:
	Table(BetCollection _bets, int _limit = DEFAULT_LIMIT, int _minimum = DEFAULT_MINIMUM)
		: bets(_bets), limit(_limit), minimum(_minimum) {}

	void placeBet(Bet bet);


	using const_iterator = BetCollection::const_iterator;
	const_iterator cbegin() const { return bets.begin(); }
	const_iterator cend() const { return bets.end(); }

	std::string toString();

	bool isValid();

};

