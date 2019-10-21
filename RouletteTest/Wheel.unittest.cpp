#include "pch.h"
#include "gtest/gtest.h"
#include "../Roulette/Wheel.h"

TEST(WheelAddOutcomes, Wheel) {

	Wheel wheel;

	Outcome odd("Odd", 5);
	Outcome even("Even", 5);
	Outcome street123("Street 1-2-3", 11);

	wheel.addOutcome(10, odd);
	wheel.addOutcome(10, street123);

	Bin bin = wheel.get(10);

	ASSERT_EQ(2, bin.size());
	EXPECT_EQ(1, bin.count(odd));
	EXPECT_EQ(1, bin.count(even));

	wheel.addOutcome(37, even);

	bin = wheel.get(37);

	ASSERT_EQ(1, bin.size());
	EXPECT_EQ(1, bin.count(even));

	bin = wheel.get(0);

	ASSERT_EQ(0, bin.size());
}

TEST(WheelAddUniqueOutcomes, Wheel) {

	Wheel wheel;
	Outcome odd("Odd", 5);

	wheel.addOutcome(10, odd);
	wheel.addOutcome(10, odd);

	Bin bin = wheel.get(10);

	ASSERT_EQ(1, bin.size());
	EXPECT_EQ(1, bin.count(odd));
}


TEST(WheelGetRandomBin, Wheel) {

	Wheel wheel(false);
	
	Outcome odd("Odd", 5);
	Outcome zeroZero("ZeroZero", 36);

	// with a seed of 1, rand()%38 give sequence 3, 37, 26, 14, 17, 30, 2, 22, 20, 30,
	wheel.addOutcome(3, odd);
	wheel.addOutcome(37, zeroZero);

	Bin bin = wheel.next();

	ASSERT_EQ(1, bin.size());
	EXPECT_EQ(1, bin.count(odd));

	bin = wheel.next();

	ASSERT_EQ(1, bin.size());
	EXPECT_EQ(1, bin.count(zeroZero));

}

TEST(OnlyGetsValidBins, Wheel) {

	Wheel wheel;

	for (int i{ 0 }; i < NUMBER_OF_BINS; i++) {
		Outcome outcome("Dummy outcome", 1);
		wheel.addOutcome(i, outcome);
	}

	for (int i{ 0 }; i <= 1000; i++) {
		wheel.next();
	}

}

TEST(EventuallyGetsAllBins, Wheel) {

	set<Bin> uniqueBinsRetrieved;
	Wheel wheel;

	for (int i{ 0 }; i < NUMBER_OF_BINS; i++) {
		Outcome outcome("Test outcome", i);
		wheel.addOutcome(i, outcome);
	}

	for (int i{ 0 }; i <= 1000; i++) {
		Bin bin = wheel.next();
		uniqueBinsRetrieved.insert(bin);
	}

	ASSERT_EQ(NUMBER_OF_BINS, uniqueBinsRetrieved.size());
}