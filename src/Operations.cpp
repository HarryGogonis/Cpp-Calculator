#include "Operations.h"

Number* Operations::add(Number* firstNum, Number* secondNum)
{
	// Add two Integers
	if (firstNum->getType() == INTEGER_TYPE
		&& secondNum->getType() == INTEGER_TYPE) 
	{
		return new Integer( ((Integer*) firstNum)->value 
				  + ((Integer*) secondNum)->value);	
	}
	// Add two Fractions
	else if (firstNum->getType() == FRACTION_TYPE
		&& secondNum->getType() == FRACTION_TYPE)
		
	{
		Fraction* f1 = (Fraction*) firstNum;
		Fraction* f2 = (Fraction*) secondNum;
		int num = f1->num * f2->den + f2->num * f1->den;
		int den = f1->den * f2->den;
		return new Fraction(num,den);
	}
	
	// Add two logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if (log1->base == log2->base)
			{
				int result = log1->power * log2->power;
				return new Log(log1->base, result);
			}
		else {
			// TODO return new Polynomial(log1,"+",log2);
		}		

	}
	return new Integer(-1);	
	
	
}
