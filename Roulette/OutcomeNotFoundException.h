#pragma once
#include <stdexcept>

class OutcomeNotFoundException: public std::out_of_range
{
public:
	OutcomeNotFoundException(const string& msg) :std::out_of_range(msg) {}
};

