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

TEST(StreetBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.streetBets(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(1, wheel.get(2).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(1, wheel.get(3).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(0, wheel.get(4).count(Outcome("Street 1-2-3", 11)));

	ASSERT_EQ(1, wheel.get(34).count(Outcome("Street 34-35-36", 11)));
	ASSERT_EQ(1, wheel.get(35).count(Outcome("Street 34-35-36", 11)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Street 34-35-36", 11)));
}

TEST(CornerBets, BinBuilder) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.cornerBets(wheel);

	Outcome corner1234 = Outcome("Corner 1-2-4-5", 8);
	ASSERT_EQ(1, wheel.get(1).count(corner1234));
	ASSERT_EQ(1, wheel.get(2).count(corner1234));
	ASSERT_EQ(1, wheel.get(4).count(corner1234));
	ASSERT_EQ(1, wheel.get(5).count(corner1234));

	Outcome corner5689 = Outcome("Corner 5-6-8-9", 8);
	ASSERT_EQ(1, wheel.get(5).count(corner5689));
	ASSERT_EQ(1, wheel.get(6).count(corner5689));
	ASSERT_EQ(1, wheel.get(8).count(corner5689));
	ASSERT_EQ(1, wheel.get(9).count(corner5689));

	Outcome corner32_36 = Outcome("Corner 32-33-35-36", 8);
	ASSERT_EQ(1, wheel.get(32).count(corner32_36));
	ASSERT_EQ(1, wheel.get(33).count(corner32_36));
	ASSERT_EQ(1, wheel.get(35).count(corner32_36));
	ASSERT_EQ(1, wheel.get(36).count(corner32_36));

	ASSERT_EQ(0, wheel.get(0).count(corner32_36));
	ASSERT_EQ(0, wheel.get(1).count(corner32_36));
	ASSERT_EQ(0, wheel.get(31).count(corner32_36));

}
