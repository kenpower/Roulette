#include "Outcome.h"

bool Outcome::operator==(const Outcome& rhs) const
{
	return this->toString().compare(rhs.toString()) == 0;
}

bool Outcome::operator!=(const Outcome& rhs) const
{
	return !(*this == rhs);
}

bool Outcome::operator<(const Outcome& rhs) const
{
	return this->toString().compare(rhs.toString()) < 0;
}

string Outcome::toString() const
{
	return name + " (" + std::to_string(odds) + ":1)";
}
