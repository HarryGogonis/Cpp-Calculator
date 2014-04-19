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
/* TODO
Power::Power(string base, string power)
{

}
*/

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
//		return new Integer((int) pow(base->getEstimate(), power->getEstimate()));
		const int x = base->getEstimate();
		const int n = power->getEstimate();
		int result = x;
		for (int i=1; i<n; i++)
			result *= x;
		return new Integer(result);
	}
	
	else if(base->getType() == FRACTION_TYPE && power->getType() == INTEGER_TYPE)
	{	
		Fraction* f1 = (Fraction*) base;
		Integer* int2 = (Integer*) power;
		Number* result = f1;
		const int n = int2->getEstimate();
		for (int i=1; i<n; i++)
			result = Operations::multiply(result,base);
		return result;
	}
	else if(power->getType() == FRACTION_TYPE && base->getType() == INTEGER_TYPE)
	{
		// TODO this might be a sloppy solution. Should return root!
		Fraction* f1 = (Fraction*) power;
		Integer* int2 = (Integer*) base;
		double ans = pow(base->getEstimate(), power->getEstimate());
		return (new Fraction(ans))->simplify();
	}
	else throw runtime_error("Power couldn't be simplified");
	// Segfault
	return this;
}

Power::~Power()
{

}
