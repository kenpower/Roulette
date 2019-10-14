#include "Outcome.h"

bool Outcome::operator==(const Outcome& rhs) const
{
	return this->name.compare(rhs.name) == 0;
}

string Outcome::toString() const
{
	return "";
}
