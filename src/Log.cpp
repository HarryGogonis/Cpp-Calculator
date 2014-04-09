#include "Number.h"
#include <stdexcept>

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
	oss << "log_" << base << "(" << power << ")";
	return oss.str();
}

Number* Log::simplify()
{
	if (base == power)
	{
		return new Integer(1);
	}
	if ((power % base) == 0) //Checks if easy simplification is possible
	{
		return new Integer((int) (log(power) / log(base)));
	}
	return this;
}

double Log::getEstimate()
{
	return log(power) / log(base);
}
