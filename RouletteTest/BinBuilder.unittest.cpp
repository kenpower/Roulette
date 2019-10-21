#include "pch.h"
#include "gtest/gtest.h"
#include "../Roulette/BinBuilder.h"

TEST(StraightBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.StraightBets(wheel);

	ASSERT_EQ(Outcome("Number 0", 35), *wheel.get(0).begin());
	ASSERT_EQ(Outcome("Number 1", 35), *wheel.get(1).begin());
	ASSERT_EQ(Outcome("Number 36", 35), *wheel.get(36).begin());
	ASSERT_EQ(Outcome("Number 00", 35), *wheel.get(37).begin());

}