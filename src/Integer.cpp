#include "Integer.h"

Integer::Integer(int value)
{
	this->value=value;
}

string Integer::toString()
{
	ostringstream oss;
	oss << value;
	return oss.str();
}
