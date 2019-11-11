#include "Table.h"
#include <algorithm>
#include <numeric>

void Table::placeBet(Bet bet)
{
	bets.push_back(bet);
}

string appendCommaIfNotEmpty(string str) {
	return str.empty() ? "" : str + ", ";
}

std::string Table::toString()
{
	string betsAsString = std::accumulate(bets.begin(), bets.end(),
		std::string(""),
		[](string firstPart, const Bet& bet) {return appendCommaIfNotEmpty(firstPart) + bet.toString(); }
	);

	return "Table with " + to_string(bets.size()) +" bets: ["+ betsAsString + "]" ;
}



bool Table::isValid()
{
	std::for_each(bets.cbegin(), bets.cend(),
		[this](const Bet& bet) {
			if (bet.getAmountBet() < minimum) {
				throw InvalidBetException("Bet: " + bet.toString() + " is below the table minimum of " + to_string(minimum));
			}
		});

	int totalBets = std::accumulate(bets.cbegin(), bets.cend(),
		0, 
		[](int sum, const Bet& bet) {return sum + bet.getAmountBet(); }
	);

	if (totalBets > limit) {
		throw InvalidBetException("Total bets (" + to_string(totalBets) + ") exceed table limit of " + to_string(limit));
	}


	return true;
}
