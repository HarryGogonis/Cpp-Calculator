#include "Number.h"
#include <stdexcept>

Fraction::Fraction(Integer* num, Integer* den)
{
	if (den->value == 0)
		throw domain_error("Divide by 0 error");
	this->num = num->value;
	this->den = den->value;
}

Fraction::Fraction(int num, int den)
{
	if (den == 0)
		throw domain_error("Divide by 0 error");

	this->num = num;
	this->den = den;
}

Fraction::Fraction(double input)
{	
	stringstream ss;
	ss << input;

	int count = ss.str().length();
	const int factor = pow(10,count-2);
	
	Fraction* temp = new Fraction((input * factor), factor);
	return temp->simplify();
}


/*Fraction::~Fraction()
 {
 //TODO Test
 if (num != 0)
 delete num;
 if (den != 0)
 delete den;
 num = 0;
 den = 0;
 }*/

Number* Fraction::simplify()
{
	if (num % den == 0)
		return new Integer(num / den);

	// Reduce fraction
	int i;
	if (num > den)
		i = num / 2;
	else
		i = den / 2;

	for (i; i > 1; i--)
	{
		if (num % i == 0 && den % i == 0)
			return new Fraction(num / i, den / i);
	}

	return this;
}

string Fraction::toString()
{
	ostringstream oss;
	oss << num << "/" << den;
	return oss.str();
}

double Fraction::getEstimate()
{
	return (double) (num) / (double) (den);
}

