#pragma once
#include <set>
#include "Outcome.h"

using namespace std;

class Bin : public set<Outcome>
{
public:
	Bin(std::initializer_list<Outcome>);



};
