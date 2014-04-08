#include "Number.h"
#include <stdexcept>

Log::Log(Number* base, Number* power)
{
	this->base = base;
	this->power = power;
}

Log::Log(int base, int power)
{
	if (base == 0 || power == 0)
	{
		throw domain_error("Math Error");
	}
	this->base = new Integer(base);
	this->power = new Integer(power);
}

string Log::toString()
{
	ostringstream oss;
	oss << "log(" << base << "_" << power << ")";
	return oss.str();
}
