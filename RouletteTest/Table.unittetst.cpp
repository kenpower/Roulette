#include "pch.h"
#include <array>
#include "gtest/gtest.h"
#include "../Roulette/Table.h"
#include "../Roulette/Bet.h"
#include "../Roulette/Wheel.h"
using namespace std;

TEST(Table, IsValidAllBetsAboveMin) {
	Outcome outcome("Street 1-2-3", 11);

	Bet bet1{ 5, outcome };
	Bet bet2{ 6, outcome };

	const int minimumBet{ 5 };

	Table table({ bet1, bet2 }, 100, minimumBet);
	
	
	EXPECT_TRUE(table.isValid());
}

TEST(Table, IsValidOneBetBelowMin) {

	Outcome outcome("Street 1-2-3", 11);

	Bet bet1{ 5, outcome };
	Bet bet2{ 6, outcome };

	const int minimumBet{ 6 };

	Table table({ bet1, bet2 }, 100, minimumBet);
	
	EXPECT_THROW(table.isValid(), InvalidBetException);
}

TEST(Table, IsValidBetsBelowTableMax) {
	Outcome outcome("Street 1-2-3", 11);

	Bet bet1{ 5, outcome };
	Bet bet2{ 5, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_TRUE(table.isValid());
}

TEST(Table, IsInvalidOneBetAboveTableMax) {
	Outcome outcome("Street 1-2-3", 11);

	Bet bet1{ 5, outcome };
	Bet bet2{ 15, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_THROW(table.isValid(), InvalidBetException);
}

TEST(Table, IsInvalidSumOfBetsAboveTableMax) {
	Outcome outcome("Street 1-2-3", 11);

	Bet bet1{ 6, outcome };
	Bet bet2{ 6, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_THROW(table.isValid(), InvalidBetException);
}

TEST(Table, ToStringNoBets) {

	Table table({ });

	EXPECT_EQ("Table with 0 bets: []",table.toString());
}
TEST(Table, ToStringTwoBets) {

	Outcome street("Street 1-2-3", 11);
	Outcome even("Even", 1);

	Bet bet1{ 5, street };
	Bet bet2{ 10, even };


	Table table({ bet1, bet2 });

	//test does not care which order the bets are reported
	string betString1 = bet1.toString() + ", " + bet2.toString();
	string betString2 = bet2.toString() + ", " + bet1.toString();

	set<string> expectedStrings{ "Table with 2 bets: [" + betString1 + "]" ,  "Table has 2 bets: [" + betString2 + "]" };

	EXPECT_EQ("Table with 2 bets: [" + betString1 + "]", table.toString());
	EXPECT_EQ(1, expectedStrings.count(table.toString()));
}

TEST(Table, IteratorWhenEmpty) {

	Table table({});

	EXPECT_EQ(table.cbegin(), table.cend());

}

TEST(Table, IteratorWhenBets) {
	Outcome street("Street 1-2-3", 11);
	Outcome even("Even", 1);

	Bet bet1{ 5, street };
	Bet bet2{ 10, even };


	Table table({ bet1 });

	table.placeBet(bet2);

	EXPECT_EQ(1, std::count(table.cbegin(), table.cend(), bet1));
	EXPECT_EQ(1, std::count(table.cbegin(), table.cend(), bet2));

}

TEST(Table, PlaceBet) {
	Outcome street("Street 1-2-3", 11);
	Outcome even("Even", 1);

	Bet bet1{ 5, street };
	Bet bet2{ 10, even };


	Table table({ bet1 });

	table.placeBet(bet2);

	EXPECT_EQ(1, std::count(table.cbegin(), table.cend(), bet1));
	EXPECT_EQ(1, std::count(table.cbegin(), table.cend(), bet2));

}



