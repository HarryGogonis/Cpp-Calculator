#include "Number.h"

Integer::Integer(int value)
{
	this->value = value;
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
