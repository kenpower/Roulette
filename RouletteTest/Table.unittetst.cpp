#include "pch.h"
#include "../Roulette/Table.h"
#include "../Roulette/Bet.h"

using namespace std;

TEST(Table, hasBetsWhenEmpty) {
	Table table({  });

	EXPECT_FALSE(table.hasBets());

}

TEST(Table, hasBetsWhenSome) {

	Bet bet{ 2, Outcome("Street 1-2-3", 11) };
	
	Table table({ bet });

	EXPECT_TRUE(table.hasBets());

}

TEST(Table, TakeOneBet) {

	Bet bet{ 2, Outcome("Street 1-2-3", 11) };

	Table table({ bet });

	Bet takenBet = table.takeBet();

	EXPECT_EQ(bet, takenBet);
	EXPECT_FALSE(table.hasBets());
}

TEST(Table, TakeTwoBets) {

	Bet bet1{ 5, Outcome("Street 1-2-3", 11) };
	Bet bet2{ 2, Outcome("Street 1-2-3", 11) };

	Table table({ bet1, bet2 });

	//Using a set to collect the bets from the table but Bet does not have a operatot<() defined
	//so we create one here to inject into the set.
	auto betComparator = [](const auto lhs, const auto rhs) {
		return lhs.toString().compare(rhs.toString()) > 0; };

	std::set<Bet, decltype(betComparator)> bets({
		table.takeBet(),table.takeBet()},
		betComparator
		);

	EXPECT_TRUE(bets.count(bet1) == 1);
	EXPECT_TRUE(bets.count(bet2) == 1);
}

TEST(Table, HasBetsEmpty) {

	Table table({});
	
	EXPECT_FALSE(table.hasBets());
}

TEST(Table, HasBetsNotEmpty) {

	Bet bet1{ 2, Outcome("Street 1-2-3", 11) };

	Table table({ bet1 });

	EXPECT_TRUE(table.hasBets());
}

TEST(Table, HasBetAfterTakeAll) {

	Bet bet1{ 2, Outcome("Street 1-2-3", 11) };

	Table table({ bet1 });

	while (table.hasBets()) {
		table.takeBet();
	}

	EXPECT_FALSE(table.hasBets());
}

TEST(Table, IsValidWithAllValidBets) {

	//TODO
	EXPECT_FALSE(true);
}

//TODO
//isValid - throw
//toString
