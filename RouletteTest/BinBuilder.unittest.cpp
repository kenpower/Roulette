#include "pch.h"
#include "gtest/gtest.h"
#include "../Roulette/BinBuilder.h"


TEST(StraightBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.straightBets(wheel);

	ASSERT_EQ(Outcome("Number 0", 35), *(wheel.get(0).begin()));
	ASSERT_EQ(Outcome("Number 1", 35), *(wheel.get(1).begin()));
	ASSERT_EQ(Outcome("Number 36", 35), *(wheel.get(36).begin()));
	ASSERT_EQ(Outcome("Number 00", 35), *(wheel.get(37).begin()));

}

TEST(SplitRowBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.splitBets(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Split 1-2", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 19-20", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 20-21", 17)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Split 35-36", 17)));
}

TEST(SplitColumnBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.splitBets(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Split 1-4", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 17-20", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 20-23", 17)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Split 33-36", 17)));

}