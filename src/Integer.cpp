#include "Number.h"
#include <cstdlib>
Integer::Integer(int value)
{
	this->value = value;
}

Integer::Integer(string value)
{
	this->value = atoi(value.c_str());
}

Number* Integer::simplify()
{
	return this;
}

string Integer::toString()
{
	ostringstream oss;
	oss << value;
	return oss.str();
}
double Integer::getEstimate()
{
	return (double) value;
}
