#include "pch.h"
#include "../Roulette/Outcome.h"
#include "../Roulette/Bet.h"

TEST(Bet, WinAmount) {
	Outcome even("even", 1);
	Outcome street("Street 1-2-3", 11);

	Bet firstBet{ 2, even };

	EXPECT_EQ(4, firstBet.winAmount());

	Bet secondBet{ 2, street };

	EXPECT_EQ(24, secondBet.winAmount());
}

TEST(Bet, LoseAmount) {
	Outcome even("even", 1);
	Outcome street("Street 1-2-3", 11);

	Bet firstBet{ 2, even };

	EXPECT_EQ(2, firstBet.loseAmount());

	Bet secondBet{ 5, street };

	EXPECT_EQ(5, secondBet.loseAmount());
}

TEST(Bet, toString) {
	Outcome street("Street 1-2-3", 11);

	Bet firstBet{ 42, street };

	EXPECT_EQ("42 on Street 1-2-3 (11:1)", firstBet.toString());
}
