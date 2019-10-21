#include "BinBuilder.h"
#include <string>

BinBuilder::BinBuilder()
{
}

void evenMoneyBets(Wheel&);
void straightBets(Wheel&);
void splitBets(Wheel&);
void streetBets(Wheel&);
void cornerBets(Wheel&);
void lineBets(Wheel&);
void dozenBets(Wheel&);
void columnBets(Wheel&);

void BinBuilder::buildBins(Wheel& wheel)
{	
	evenMoneyBets(wheel);
	straightBets(wheel);
	splitBets(wheel);
	streetBets(wheel);
	cornerBets(wheel);
	lineBets(wheel);
	dozenBets(wheel);
	columnBets(wheel);
}

void straightBets(Wheel& wheel)
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

void splitBets(Wheel& wheel)
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
void streetBets(Wheel& wheel)
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
		//todo
}

void cornerBets(Wheel& wheel)
{
	for (int row{ 0 }; row < 11; row++) {
		int firstCorner = 3 * row + 1;
		addCornerOutcome(firstCorner, firstCorner+1, firstCorner+3, firstCorner+4, wheel);

		int secondCorner = 3 * row + 2;
		addCornerOutcome(secondCorner, secondCorner + 1, secondCorner + 3, secondCorner + 4, wheel);
	}
}

string lineName(int start) {
	string name = "Line " + std::to_string(start);

	for (int number = start+1; number < start + 6; number++)
		name += "-" + std::to_string(number);

	return name;
}

void addLineOutcome(int start, Wheel& wheel) {
	Outcome outcome(lineName(start), 5);
	for (int number{ start }; number < start + 6; number++)
			wheel.addOutcome(number, outcome);
}

void lineBets(Wheel& wheel)
{
	for (int row{ 0 }; row < 11; row++) {
		addLineOutcome(3*row+1, wheel);
	}
}

string dozenName(int start) {
	string name = "Dozen " + std::to_string(start);

	for (int number = start + 1; number < start + 12; number++)
		name += "-" + std::to_string(number);

	return name;
}

void addDozenOutcome(int start, Wheel& wheel) {
	Outcome outcome(dozenName(start), 2);
	for (int number{ start }; number < start + 12; number++)
		wheel.addOutcome(number, outcome);
}

void dozenBets(Wheel& wheel)
{
	for (int dozenStart{ 1 }; dozenStart <26; dozenStart+=12){
		addDozenOutcome(dozenStart, wheel);
	}
}

string columnName(int start) {
	string name = "Column " + std::to_string(start) + "-" + std::to_string(start+33);

	return name;
}

void addColumnOutcome(int start, Wheel& wheel) {
	Outcome outcome(columnName(start), 2);
	for (int number{ start }; number < start + 34; number+=3)
		wheel.addOutcome(number, outcome);
}

void columnBets(Wheel& wheel)
{
	for (int columnStart{ 1 }; columnStart < 4; columnStart ++) {
		addColumnOutcome(columnStart, wheel);
	}
}

void addEvenOddOutcome(int number, Wheel& wheel )
{
	Outcome odd = Outcome("Odd", 1);
	Outcome even = Outcome("Even", 1);

	if (number % 2 == 0)
		wheel.addOutcome(number, even);
	else
		wheel.addOutcome(number, odd);
}

void addRedBlackOutcome(int number, Wheel& wheel)
{
	set<int> redNumbers = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };

	Outcome red = Outcome("Red", 1);
	Outcome black = Outcome("Black", 1);

	if (redNumbers.count(number) == 1)
		wheel.addOutcome(number, red);
	else
		wheel.addOutcome(number, black);
}

void addLowHighOutcome(int number, Wheel& wheel)
{
	Outcome high = Outcome("High", 1);
	Outcome low = Outcome("Low", 1);

	if (number < 19)
		wheel.addOutcome(number, low);
	else
		wheel.addOutcome(number, high);
}

void evenMoneyBets(Wheel& wheel)
{
	for (int number{ 1 }; number <= 36; number++) {
		addEvenOddOutcome(number, wheel);

		addRedBlackOutcome(number, wheel);

		addLowHighOutcome(number, wheel);
	}
}