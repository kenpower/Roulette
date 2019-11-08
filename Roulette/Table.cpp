#include "Table.h"
#include <algorithm>
#include <numeric>

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

bool Table::isValid(const Wheel& wheel)
{
	std::for_each(bets.cbegin(), bets.cend(),
		[this, wheel](const Bet& bet) {
			if (bet.getAmountBet() < minimum) {
				throw InvalidBetException("Bet: " + bet.toString() + " is below the table minimum of " + to_string(minimum));
			}

			try {
				wheel.getOutcome(bet.getOutcome().getName());
			}
			catch (OutcomeNotFoundException) {
				throw  InvalidBetException("Bet: " + bet.toString() + " does not have an valid outcome");
			}
		});

	int totalBets = std::accumulate(bets.begin(), bets.end(),
		0, 
		[](int sum, const Bet& bet) {return sum + bet.getAmountBet(); }
	);

	if (totalBets > limit) {
		throw InvalidBetException("Total bets (" + to_string(totalBets) + ") exceed table limit of " + to_string(limit));
	}


	return true;
}
