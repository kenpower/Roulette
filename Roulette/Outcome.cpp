#include "Outcome.h"

bool Outcome::operator==(const Outcome& rhs) const
{
	return this->name.compare(rhs.name) == 0;
}

bool Outcome::operator!=(const Outcome& rhs) const
{
	return !(*this == rhs);
}

bool Outcome::operator<(const Outcome& rhs) const
{
	return this->odds < rhs.odds;
}

string Outcome::toString() const
{
	return "";
}
