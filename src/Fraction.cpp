#include "Fraction.h"
//#include "Integer.h"

Fraction::Fraction(Number* num, Number* den)
{
	this->num = num;
	this->den = den;
}

/*
Fraction::Fraction(int num, int den)
{
	this->num = new Integer(num);
	this->den = new Integer(den);
}
*/

string Fraction::toString()
{
	ostringstream oss;
	oss << num << "/" << den;
	return oss.str();
}
