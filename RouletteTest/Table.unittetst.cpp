#include "pch.h"
#include "gtest/gtest.h"
#include "../Roulette/Table.h"
#include "../Roulette/Bet.h"
#include "../Roulette/Wheel.h"
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

TEST(Table, IsValidAllBetsAboveMin) {
	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 5, outcome };
	Bet bet2{ 6, outcome };

	const int minimumBet{ 5 };

	Table table({ bet1, bet2 }, 100, minimumBet);
	
	
	EXPECT_TRUE(table.isValid(wheel));
}

TEST(Table, IsValidOneBetBelowMin) {

	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 5, outcome };
	Bet bet2{ 6, outcome };

	const int minimumBet{ 6 };

	Table table({ bet1, bet2 }, 100, minimumBet);
	
	EXPECT_THROW(table.isValid(wheel), InvalidBetException);
}

TEST(Table, IsValidBetsBelowTableMax) {
	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 5, outcome };
	Bet bet2{ 5, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_TRUE(table.isValid(wheel));
}

TEST(Table, IsInvalidOneBetAboveTableMax) {
	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 5, outcome };
	Bet bet2{ 15, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_THROW(table.isValid(wheel), InvalidBetException);
}

TEST(Table, IsInvalidSumOfBetsAboveTableMax) {
	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 6, outcome };
	Bet bet2{ 6, outcome };

	const int tableMax{ 10 };

	Table table({ bet1, bet2 }, tableMax);

	EXPECT_THROW(table.isValid(wheel), InvalidBetException);
}

TEST(Table, IsValidBetOutcomeExists) {

	Outcome outcome("Street 1-2-3", 11);
	Wheel wheel;
	wheel.addOutcome(1, outcome);

	Bet bet1{ 5, outcome };


	const int tableMax{ };

	Table table({ bet1 });


	EXPECT_TRUE(table.isValid(wheel));
}

TEST(Table, IsInvalidBetOutcomeNotExists) {

	Outcome outcome("Street 1-2-3", 11);
	Bet bet1{ 5, outcome };


	const int tableMax{ };

	Table table({ bet1 });

	Wheel wheel;

	EXPECT_THROW(table.isValid(wheel), InvalidBetException);
}



//TODO
//isValid - throw
//toString
