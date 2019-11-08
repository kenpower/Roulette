#pragma once

#pragma once
#include <stdexcept>

class InvalidBetException : public std::domain_error
{
public:
	InvalidBetException(const std::string& msg):std::domain_error(msg) {}
};
