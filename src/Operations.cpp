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
	
	// Add two Irrationals of same type
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{	
		Irrational* ir1 = (Irrational*) firstNum;
		Irrational* ir2 = (Irrational*) secondNum;
		if(ir1->name == ir2->name){
			//TODO return Polynomial(2, "*", ir1->name);
		}
		else {
			//TODO return Polynomial(firstNum, "+", secondNum);
		}
	}
	
	
	//For any other case create Polynomial
	else 
	{
		// TODO return new Polynomial(firstNum,"+", secondNum);
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
	
	//Subtract two Irrationals of same type
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{	
		Irrational* ir1 = (Irrational*) firstNum;
		Irrational* ir2 = (Irrational*) secondNum;
		if(ir1->name == ir2->name)
			return new Integer(0);
		else {
			//TODO return Polynomial(firstNum, "-", secondNum);
		}
	}
	
	//For any other case create Polynomial
	else 
	{
		// TODO return new Polynomial(firstNum,"-", secondNum);
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
	}
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

	//Multiply two Powers
	else if(firstNum->getType() == POWER_TYPE && secondNum->getType() == POWER_TYPE)
	{
		Power* pow1 = (Power*) firstNum;
		Power* pow2 = (Power*) secondNum;
		if(pow1->base == pow2->base)
			return new Power(pow1->base, add(pow1->power, pow2->power));
		else{
			//TODO return new Polynomial(firstNum, "*", secondNum);
		}
	}
	
	//Multiply Two Irrationals of same type
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{	
		Irrational* ir1 = (Irrational*) firstNum;
		Irrational* ir2 = (Irrational*) secondNum;
		if(ir1->name == ir2->name)
			return new Power(firstNum, new Integer(2));
		else {
			//TODO return Polynomial(firstNum, "*", secondNum);
		}
	}
	
	//For any other case create Polynomial
	else 
	{
		// TODO return new Polynomial(firstNum,"*", secondNum);
	}

	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

Number* Operations::divide(Number* firstNum, Number* secondNum)
{
	//Dividing by Fraction is multiplying by inverse
	if (secondNum->getType() == FRACTION_TYPE){
		Fraction* f2 = (Fraction*) secondNum;
		return multiply(firstNum, Fraction(f2->den, f2->num).simplify());
		}

	//Dividing by Integer is multiplying by 1/Integer
	else if (secondNum->getType() == INTEGER_TYPE){
	  Integer* int2 = (Integer*) secondNum;
	  return multiply(firstNum, Fraction(1, int2->value).simplify());
	}

	//Division of 2 Logs
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

	//Divide two Powers
	else if(firstNum->getType() == POWER_TYPE && secondNum->getType() == POWER_TYPE)
	{
		Power* pow1 = (Power*) firstNum;
		Power* pow2 = (Power*) secondNum;
		if(pow1->base == pow2->base)
			return new Power(pow1->base, subtract(pow1->power, pow2->power));
		else{
			//TODO return new Polynomial(firstNum, "/", secondNum);
		}
	}
	
	//Divide two Irrationals of same type
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{	
		Irrational* ir1 = (Irrational*) firstNum;
		Irrational* ir2 = (Irrational*) secondNum;
		if(ir1->name == ir2->name)
			return new Integer(1);
		else {
			//TODO return Polynomial(firstNum, "/", secondNum);
		}
	}
	

	//For any other case create Polynomial
	else 
	{
		// TODO return new Polynomial(firstNum,"+", secondNum);
	}
	
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

