#include "Number.h"
#include"Operations.h"
#include <stdio.h>
#include <math.h>

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
	oss << base << "^(" << power << ")";
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
	
	else if(base->getType() == FRACTION_TYPE && power->getType() == INTEGER_TYPE)
	{
		Fraction* f1 = (Fraction*) base;
		Integer* int2 = (Integer*) power;
		return Operations::divide(new Power(f1->num, int2->value), new Power(f1->den, int2->value));
	}

	else return this;
}

Power::~Power()
{

}
