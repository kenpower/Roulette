#include "pch.h"
#include "../Roulette/Outcome.h"
#include "OutcomeUnitTests.h"

TEST(Outcome, Equals) {
	Outcome odd("Odd", 1);
	Outcome anotherOdd("Odd", 1);

	ASSERT_EQ(odd, anotherOdd);
	ASSERT_TRUE(odd == anotherOdd);
}

TEST(Outcome, NotEquals) {
	Outcome odd("Odd", 1);
	Outcome even("Even", 1);

	ASSERT_TRUE(odd != even);
}

TEST(Outcome, ToString) {
	Outcome odd("Odd", 5);
	
	ASSERT_EQ("Odd (5:1)", odd.toString());

	Outcome street("Street 1-2-3", 11);

	ASSERT_EQ("Street 1-2-3 (11:1)", street.toString());
}
