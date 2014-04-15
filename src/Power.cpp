#include "Number.h"
#include"Operations.h"
#include <stdio.h>
#include <math.h>
#include <stdexcept>

Power::Power(Number* base, Number* power)
{
	// TODO throw excpetion for negitive roots?
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
		//return Operations::divide(new Power(f1->num, int2->value), new Power(f1->den, int2->value));
		double ans = pow(base->getEstimate(), power->getEstimate());
		return (new Fraction(ans))->simplify();
	}
	else if(power->getType() == FRACTION_TYPE && base->getType() == INTEGER_TYPE)
	{
		// TODO this might be a sloppy solution
		Fraction* f1 = (Fraction*) power;
		Integer* int2 = (Integer*) base;
		double ans = pow(base->getEstimate(), power->getEstimate());
		return (new Fraction(ans))->simplify();
	}
	else return this;
}

Power::~Power()
{

}
