#pragma once
#include <iostream>

class Validate
{
public:
	Validate() {};
	void validateStringAllDigits(std::string toValidate) const;
	void validateStringFloat(std::string toValidate) const;
};