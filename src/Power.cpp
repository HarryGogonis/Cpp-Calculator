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

		if (n==0)
			return new Integer(1);
	
		if (n<0) 
		{
			int result = x;
			for (int i=1; i<-n;i++)
				result *= x;
			return new Fraction(1,result);
		}
		
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
		Fraction* frac1 = (Fraction*) power;
		Integer* int2 = (Integer*) base;
		if (frac1->num == 1) 
			return (new Root(int2->getEstimate(),frac1->den))->simplify();
		else {
			int pow = frac1->num;
			int rootN = frac1->den;
			Number* root = Root(int2->value,rootN).simplify();
			return (new Power(root,new Integer(pow)))->simplify();
		}
	}
	return this;
}

Power::~Power()
{

}
