#include "Number.h"
#include <stdexcept>

Log::Log(Number* base, Number* power)
{
	this->base = base;
	this->power = power;
}

Log::Log(int base, int power)
{
	if (base < 0 || power <= 0)
	{
		throw domain_error("Math Error");
	}
	this->base = base;
	this->power = power;
}

string Log::toString()
{
	ostringstream oss;
	oss << "log(" << base << "_" << power << ")";
	return oss.str();
}

Number* Log::simplify()
{
	if (base == power)
	{
		return new Integer(1);
	}
	return this;
}

double Log::getEstimate()
{
	return log(power.getEstimate())/log(base.getEstimate()));
}
