#pragma once

#pragma once
#include <stdexcept>

class InvalidBet : public std::domain_error
{
public:
	InvalidBet(const std::string& msg):std::domain_error(msg) {}
};
