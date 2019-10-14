#pragma once
#include <string>
using namespace std;

class Outcome
{
	string name;
	int odds;

public:
	Outcome(string t_name, int t_odds) {
		name = t_name;
		odds = t_odds;
	}

	bool operator==(const Outcome& rhs) const;
	bool operator!=(const Outcome& rhs) const;
	bool operator<(const Outcome& rhs) const;

	string toString() const;
};

