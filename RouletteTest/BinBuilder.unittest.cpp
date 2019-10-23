#include "pch.h"
#include "gtest/gtest.h"
#include "../Roulette/BinBuilder.h"

TEST(DISABLED_BinBuilder, StraightBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	ASSERT_EQ(1, wheel.get(0).count(Outcome("Number 0", 35)));
	ASSERT_EQ(1, wheel.get(1).count(Outcome("Number 1", 35)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Number 36", 35)));
	ASSERT_EQ(1, wheel.get00().count(Outcome("Number 00", 35)));
}

TEST(DISABLED_BinBuilder, SplitRowBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Split 1-2", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 19-20", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 20-21", 17)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Split 35-36", 17)));
}

TEST(DISABLED_BinBuilder, SplitColumnBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Split 1-4", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 17-20", 17)));
	ASSERT_EQ(1, wheel.get(20).count(Outcome("Split 20-23", 17)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Split 33-36", 17)));
}

TEST(DISABLED_BinBuilder, StreetBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	ASSERT_EQ(1, wheel.get(1).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(1, wheel.get(2).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(1, wheel.get(3).count(Outcome("Street 1-2-3", 11)));
	ASSERT_EQ(0, wheel.get(4).count(Outcome("Street 1-2-3", 11)));

	ASSERT_EQ(1, wheel.get(34).count(Outcome("Street 34-35-36", 11)));
	ASSERT_EQ(1, wheel.get(35).count(Outcome("Street 34-35-36", 11)));
	ASSERT_EQ(1, wheel.get(36).count(Outcome("Street 34-35-36", 11)));
}

TEST(DISABLED_BinBuilder, CornerBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

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

TEST(DISABLED_BinBuilder, LineBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	Outcome line123456 = Outcome("Line 1-2-3-4-5-6", 5);
	ASSERT_EQ(1, wheel.get(1).count(line123456));
	ASSERT_EQ(1, wheel.get(2).count(line123456));
	ASSERT_EQ(1, wheel.get(3).count(line123456));
	ASSERT_EQ(1, wheel.get(4).count(line123456));
	ASSERT_EQ(1, wheel.get(5).count(line123456));
	ASSERT_EQ(1, wheel.get(6).count(line123456));

	Outcome line31_36 = Outcome("Line 31-32-33-34-35-36", 5);
	ASSERT_EQ(1, wheel.get(31).count(line31_36));
	ASSERT_EQ(1, wheel.get(32).count(line31_36));
	ASSERT_EQ(1, wheel.get(33).count(line31_36));
	ASSERT_EQ(1, wheel.get(34).count(line31_36));
	ASSERT_EQ(1, wheel.get(35).count(line31_36));
	ASSERT_EQ(1, wheel.get(36).count(line31_36));

	ASSERT_EQ(0, wheel.get(0).count(line31_36));
	ASSERT_EQ(0, wheel.get(1).count(line31_36));
	ASSERT_EQ(0, wheel.get(30).count(line31_36));

}

TEST(DISABLED_BinBuilder, DozenBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	Outcome dozen1_12 = Outcome("Dozen 1-2-3-4-5-6-7-8-9-10-11-12", 2);
	ASSERT_EQ(1, wheel.get(1).count(dozen1_12));
	ASSERT_EQ(1, wheel.get(5).count(dozen1_12));
	ASSERT_EQ(1, wheel.get(9).count(dozen1_12));
	ASSERT_EQ(1, wheel.get(10).count(dozen1_12));
	ASSERT_EQ(1, wheel.get(12).count(dozen1_12));


	Outcome dozen25_36 = Outcome("Dozen 25-26-27-28-29-30-31-32-33-34-35-36", 2);
	ASSERT_EQ(1, wheel.get(25).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(29).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(30).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(34).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(35).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(36).count(dozen25_36));

	ASSERT_EQ(0, wheel.get(0).count(dozen25_36));
	ASSERT_EQ(0, wheel.get(1).count(dozen25_36));
	ASSERT_EQ(0, wheel.get(24).count(dozen25_36));

}

TEST(DISABLED_BinBuilder, ColumnBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	Outcome column1_34 = Outcome("Column 1-34", 2);
	ASSERT_EQ(1, wheel.get(1).count(column1_34));
	ASSERT_EQ(1, wheel.get(13).count(column1_34));
	ASSERT_EQ(1, wheel.get(34).count(column1_34));

	Outcome dozen25_36 = Outcome("Column 3-36", 2);
	ASSERT_EQ(1, wheel.get(3).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(15).count(dozen25_36));
	ASSERT_EQ(1, wheel.get(36).count(dozen25_36));

	ASSERT_EQ(0, wheel.get(0).count(dozen25_36));
	ASSERT_EQ(0, wheel.get(1).count(dozen25_36));
	ASSERT_EQ(0, wheel.get(35).count(dozen25_36));
}

TEST(DISABLED_BinBuilder, EvenMoneyBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	Outcome red = Outcome("Red", 1);
	Outcome black = Outcome("Black", 1);
	Outcome odd = Outcome("Odd", 1);
	Outcome even = Outcome("Even", 1);
	Outcome high = Outcome("High", 1);
	Outcome low = Outcome("Low", 1);

	ASSERT_EQ(1, wheel.get(1).count(red));
	ASSERT_EQ(1, wheel.get(1).count(odd));
	ASSERT_EQ(1, wheel.get(1).count(low));

	ASSERT_EQ(0, wheel.get(1).count(black));
	ASSERT_EQ(0, wheel.get(1).count(even));
	ASSERT_EQ(0, wheel.get(1).count(high));

	ASSERT_EQ(1, wheel.get(18).count(red));
	ASSERT_EQ(1, wheel.get(18).count(even));
	ASSERT_EQ(1, wheel.get(18).count(low));

	ASSERT_EQ(1, wheel.get(19).count(red));
	ASSERT_EQ(1, wheel.get(19).count(odd));
	ASSERT_EQ(1, wheel.get(19).count(high));

	ASSERT_EQ(1, wheel.get(36).count(red));
	ASSERT_EQ(1, wheel.get(36).count(even));
	ASSERT_EQ(1, wheel.get(36).count(high));

	ASSERT_EQ(0, wheel.get(0).count(red));
	ASSERT_EQ(0, wheel.get(0).count(black));
	ASSERT_EQ(0, wheel.get(0).count(even));
	ASSERT_EQ(0, wheel.get(0).count(odd));
	ASSERT_EQ(0, wheel.get(0).count(high));
	ASSERT_EQ(0, wheel.get(0).count(low));

}

TEST(DISABLED_BinBuilder, FiveBets) {
	BinBuilder binBuilder;
	Wheel wheel;

	binBuilder.buildBins(wheel);

	Outcome five = Outcome("00-0-1-2-3", 6);

	ASSERT_EQ(1, wheel.get(0).count(five));
	ASSERT_EQ(1, wheel.get(1).count(five));
	ASSERT_EQ(1, wheel.get(2).count(five));
	ASSERT_EQ(1, wheel.get(3).count(five));
	ASSERT_EQ(1, wheel.get00().count(five));

	ASSERT_EQ(0, wheel.get(4).count(five));
	ASSERT_EQ(0, wheel.get(36).count(five));

}
