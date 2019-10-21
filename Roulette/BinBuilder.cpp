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

string streetName(int first, int second, int third) {
	return "Street " + std::to_string(first) + "-" + std::to_string(second) + "-" + std::to_string(third);
}

void addStreetOutcome(int first, int second, int third, Wheel& wheel) {
	Outcome outcome(streetName(first, second, third), 11);
	wheel.addOutcome(first, outcome);
	wheel.addOutcome(second, outcome);
	wheel.addOutcome(third, outcome);

}
void BinBuilder::streetBets(Wheel& wheel)
{
	for (int row{ 0 }; row < 12; row++) {
		int firstColNumber = 3 * row + 1;
		int secondColNumber = firstColNumber + 1;
		int thirdColNumber = firstColNumber + 2;
		addStreetOutcome(firstColNumber,secondColNumber, thirdColNumber, wheel);
	}
}

string cornerName(int first, int second, int third, int fourth) {
	return "Corner " 
		+ std::to_string(first) 
		+ "-" + std::to_string(second) 
		+ "-" + std::to_string(third)
		+ "-" + std::to_string(fourth);
}

void addCornerOutcome(int first, int second, int third, int fourth,  Wheel& wheel) {
	Outcome outcome(cornerName(first, second, third, fourth), 8);
	wheel.addOutcome(first, outcome);
	wheel.addOutcome(second, outcome);
	wheel.addOutcome(third, outcome);
	wheel.addOutcome(fourth, outcome);

}

void createCorner(int first, int second, int third, int fourth, Wheel& wheel) {

}
void BinBuilder::cornerBets(Wheel& wheel)
{
	for (int row{ 0 }; row < 11; row++) {
		int firstCorner = 3 * row + 1;
		addCornerOutcome(firstCorner, firstCorner+1, firstCorner+3, firstCorner+4, wheel);

		int secondCorner = 3 * row + 2;
		addCornerOutcome(secondCorner, secondCorner + 1, secondCorner + 3, secondCorner + 4, wheel);
	}
}