#include "Validate.h"
#include "Exception.h"
#include <regex>

using namespace std;



void Validate::validateStringAllDigits(std::string toValidate) const
{
	std::string digit = "0123456789";
	for (int i = 0; i < toValidate.length(); ++i)
		if (digit.find(toValidate.at(i)) == std::string::npos)
			throw ValidationDigitsException{ "Error validating the int values\n" };

}

void Validate::validateStringFloat(std::string toValidate) const
{
	try 
	{
		stof(toValidate);
	}
	catch (exception & e)
	{
		throw ValidationDigitsException{ "Error validating the float values\n" };
	}
}