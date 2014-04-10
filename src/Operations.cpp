#include "Operations.h"
#include <stdexcept>

Number* Operations::add(Number* firstNum, Number* secondNum)
{
	// Add two Integers
	if (firstNum->getType() == INTEGER_TYPE
		&& secondNum->getType() == INTEGER_TYPE) 
	{
		Integer* int1 = (Integer*) firstNum;
		Integer* int2 = (Integer*) secondNum;
		return new Integer(int1->value + int2->value);
	}
	// Add two Fractions
	else if (firstNum->getType() == FRACTION_TYPE
		&& secondNum->getType() == FRACTION_TYPE)
		
	{
		Fraction* f1 = (Fraction*) firstNum;
		Fraction* f2 = (Fraction*) secondNum;
		int num = f1->num * f2->den + f2->num * f1->den;
		int den = f1->den * f2->den;
		return Fraction(num,den).simplify();
	}

	//Add one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2->den * int1->value;
	  return add(Fraction(newNum, f2->den).simplify(), secondNum);
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->den * int2->value;
	  return add(firstNum, Fraction(newNum, f1->den).simplify());
	}
	
	// Add two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if (log1->base == log2->base)
			{
				return Operations::multiply(log1->power,log2->power);
			}
		else {
			// TODO return new Polynomial(log1,"+",log2);
		}		

	}
	
	// Add two Irrationals
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{
		if (firstNum->name == secondNum->name){
			//TODO return new Polynomial(2, "*", firstNum->name)
		}
	}
	else 
	{
		// TODO return new Polynomial(num1,"+",num2);
	}
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
	
	
}

Number* Operations::subtract(Number* firstNum, Number* secondNum)
{
	//Subtract two Integers
	if (firstNum->getType() == INTEGER_TYPE
		&& secondNum->getType() == INTEGER_TYPE) 
	{
		Integer* int1 = (Integer*) firstNum;
		Integer* int2 = (Integer*) secondNum;
		return new Integer(int1->value - int2->value);
	}

	//Subtract two Fractions
	else if (firstNum->getType() == FRACTION_TYPE
		&& secondNum->getType() == FRACTION_TYPE)
		
	{
		Fraction* f1 = (Fraction*) firstNum;
		Fraction* f2 = (Fraction*) secondNum;
		int num = f1->num * f2->den - f2->num * f1->den;
		int den = f1->den * f2->den;
		return Fraction(num,den).simplify();
	}
	
	//Subtract one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2->den * int1->value;
	  return subtract(Fraction(newNum, f2->den).simplify(), secondNum);
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->den * int2->value;
	  return subtract(firstNum, Fraction(newNum, f1->den).simplify());
	}
	
	//Subtract two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if (log1->base == log2->base)
			{

				return Operations::divide(log1->power,log2->power);
			}
		else {
			// TODO return new Polynomial(log1,"+",log2); OR Change-of-base?
		}		

	}
	
	//Subtract two Irrationals
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{
		
	}
	else 
	{
		// TODO return new Polynomial(num1,"+",num2);
	}
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

Number* Operations::multiply(Number* firstNum, Number* secondNum)
{
	//Multiply two Integers
	if (firstNum->getType() == INTEGER_TYPE
		&& secondNum->getType() == INTEGER_TYPE) 
	{
		Integer* int1 = (Integer*) firstNum;
		Integer* int2 = (Integer*) secondNum;
		return new Integer(int1->value * int2->value);
	}

	//Multiply two Fractions
	else if (firstNum->getType() == FRACTION_TYPE
		&& secondNum->getType() == FRACTION_TYPE)
		
	{
		Fraction* f1 = (Fraction*) firstNum;
		Fraction* f2 = (Fraction*) secondNum;
		int num = f1->num * f2->num;
		int den = f1->den * f2->den;
		return Fraction(num,den).simplify();
	}
	
	//Multiply one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2->num * int1->value;
	  return Fraction(newNum, f2->den).simplify();
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->num * int2->value;
	  return Fraction(newNum, f1->den).simplify();
	
	//Multiply two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if (log1->power == log2->base)
			{
				return new Log(log1->base,log2->power);
			}
		else {
			// TODO return new Polynomial(log1,"*",log2); 
		}		

	}
	
	//Multiply Two Irrationals
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{
		
	}
	else 
	{
		// TODO return new Polynomial(num1,"+",num2);
	}
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

Number* Operations::divide(Number* firstNum, Number* secondNum)
{
	if (firstNum->getType() == INTEGER_TYPE
		&& secondNum->getType() == INTEGER_TYPE) 
	{
		Integer* int1 = (Integer*) firstNum;
		Integer* int2 = (Integer*) secondNum;
		return new Integer(int1->value / int2->value);
	}

	else if (firstNum->getType() == FRACTION_TYPE
		&& secondNum->getType() == FRACTION_TYPE)
		
	{
		Fraction* f1 = (Fraction*) firstNum;
		Fraction* f2 = (Fraction*) secondNum;
		int num = f1->num * f2->den;
		int den = f1->den * f2->num;
		return Fraction(num,den).simplify();
	}
	
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if (log1->power == log2->base)
			{
				return new Log(log1->base,log2->power);
			}
		else {
			// TODO return new Polynomial(log1,"*",log2); 
		}		

	}
	
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{
		
	}
	else 
	{
		// TODO return new Polynomial(num1,"+",num2);
	}
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

