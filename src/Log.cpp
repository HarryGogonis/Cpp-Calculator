#include "Number.h"
#include <stdexcept>

Log::Log(Number* base, Number* power)
{
	if (base->getEstimate() < 0 || power->getEstimate() <= 0)
	{
		throw domain_error("Math Error");
	}
	this->base = base;
	this->power = power;
}

Log::Log(int base, int power)
{
	if (base < 0 || power <= 0)
	{
		throw domain_error("Math Error");
	}
	this->base = new Integer(base);
	this->power = new Integer(power);
}

string Log::toString()
{
	ostringstream oss;
	oss << "log_" << base << "(" << power << ")";
	return oss.str();
}

Number* Log::simplify()
{
	if (base->getEstimate() == power->getEstimate())
	{
		return new Integer(1);
	}
	if (power->getType() == INTEGER_TYPE
		&& base->getType() == INTEGER_TYPE)
	{
		if (((int)power->getEstimate() % (int)base->getEstimate()) == 0)
		{
			return new Integer((int) (log(power->getEstimate()) / log(base->getEstimate())));
		}
	}
	return this;
}

double Log::getEstimate()
{
	return (double)(log(power->getEstimate()) / log(base->getEstimate()));
}
