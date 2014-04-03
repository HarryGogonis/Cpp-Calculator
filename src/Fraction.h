/**
 * Represents a fraction
 * 
 */ 
#include "Number.h"

#define FRACTION_TYPE "Fraction"

class Fraction:public Number
{
	public:
		Number* num;
		Number* den;

		Fraction(Number*, Number*);
		//Fraction(int, int);
		//Fraction(string,string);

		string toString();
		string getType() { return FRACTION_TYPE; };
};
