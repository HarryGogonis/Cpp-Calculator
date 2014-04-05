#include "Number.h"
#include <stdexcept>

Fraction::Fraction(Number* num, Number* den)
{
	this->num = num;
	this->den = den;
}

Fraction::Fraction(int num, int den)
{
	if (den == 0)
		throw domain_error("Divide by 0 error");

	this->num = new Integer(num);
	this->den = new Integer(den);
}

string Fraction::toString()
{
	ostringstream oss;
	oss << num << "/" << den;
	return oss.str();
}
