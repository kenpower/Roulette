#include "BinBuilder.h"
#include <string>

BinBuilder::BinBuilder()
{
}

void BinBuilder::BuildBins(Wheel&)
{
}

void BinBuilder::straightBets(Wheel& wheel)
{
	for (int bin{ 0 }; bin <= 36; bin++) {
		std::string outcomeName = "Number " + std::to_string(bin);
		Outcome outcome(outcomeName, 35);
		wheel.addOutcome(bin, outcome);
	}

	Outcome outcome("Number 00", 35);
	wheel.addOutcome(37, outcome);
}

string splitName(int first, int second) {
	return "Split " + std::to_string(first) + "-" + std::to_string(second);
}

void addSplitOutcome(int first, int second, Wheel& wheel) {
	Outcome outcome(splitName(first, second), 17);
	wheel.addOutcome(first, outcome);
	wheel.addOutcome(second, outcome);
}

void createLeftRightSplitOutcomes(Wheel& wheel) {
	for (int row{ 0 }; row < 12; row++) {
		int firstColNumber = 3 * row + 1;
		int secondColNumber = firstColNumber + 1;
		addSplitOutcome(firstColNumber, secondColNumber, wheel);
		int thirdColNumber = firstColNumber + 2;
		addSplitOutcome(secondColNumber, thirdColNumber, wheel);
	}
}

void createUpDownSplitOutcomes(Wheel& wheel) {
	for (int firstNumber{ 1 }; firstNumber <= 33; firstNumber++) {
		int secondNumber = firstNumber + 3;
		addSplitOutcome(firstNumber, secondNumber, wheel);
	}
}

void BinBuilder::splitBets(Wheel& wheel)
{
	createLeftRightSplitOutcomes(wheel);
	createUpDownSplitOutcomes(wheel);
}
