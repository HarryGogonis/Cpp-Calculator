#include "Number.h"

Power::Power(Number* base, Number* power)
{
	this->base = base;
	this->power = power;
}

Power::Power(int base, int power)
{
	this->base = new Integer(base);
	this->power = new Integer(power);
}

string Power::toString()
{
	ostringstream oss;
	oss << base << "^(" << power << ")0";
	return oss.str();
}

double Power::getEstimate()
{
	return pow(base->getEstimate(), power->getEstimate());
}

Number* Power::simplify()
{
	if (base->getType() == INTEGER_TYPE && power->getType() == INTEGER_TYPE)
	{
		return new Integer((int) pow(base->getEstimate(), power->getEstimate()));
	}
	return this;
}

Power::~Power()
{
	delete base;
	delete power;
}
