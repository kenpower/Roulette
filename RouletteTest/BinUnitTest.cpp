#include "pch.h"
#include "../Roulette/Outcome.h"
#include "../Roulette/Bin.h"

TEST(Bin, Constructor) {

	Outcome even("Even", 2);
	Outcome street("Street 1-2-3", 11);

	Bin firstBin{ even, street };

	EXPECT_EQ(2, firstBin.size());

	EXPECT_EQ(1, firstBin.count(even));
	EXPECT_EQ(1, firstBin.count(street));


	Outcome odd("Street 1-2-3", 11);

	Bin secondBin{ odd, even };

	EXPECT_EQ(2, secondBin.size());

	EXPECT_EQ(1, secondBin.count(even));
	EXPECT_EQ(1, secondBin.count(odd));
}

TEST(Bin, UniqueOutcomes) {

	Outcome even("Even", 2);
	Outcome street("Street 1-2-3", 11);

	Bin firstBin{ even, street, even };

	EXPECT_EQ(2, firstBin.size());

	EXPECT_EQ(1, firstBin.count(even));
	EXPECT_EQ(1, firstBin.count(street));

}
