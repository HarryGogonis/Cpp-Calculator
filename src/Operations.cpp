#include "Operations.h"
#include <stdexcept>
#include <iostream>

/*
 * TODO
 * Minimize. For example, store firstNum->getType()
 * then in conditionals put the variable
 */

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
		return (new Fraction(num,den))->simplify();
	}

	//Add one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2->num + f2->den * int1->value;
	  return (new Fraction(newNum, f2->den))->simplify();
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->num + f1->den * int2->value;
	  return (new Fraction(newNum, f1->den))->simplify();
	}
	
	// Add two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if ((log1->base)->equals(log2->base))
		{
			Number* newPower = multiply(log1->power,log2->power);
			return (new Log(log1->base,newPower))->simplify();	
		}
		else {
			return new Polynomial(log1,'+',log2);
		}		

	}
	
	// Add two Irrationals of same type
	else if (firstNum->getType() == IRRATIONAL_TYPE
		&& secondNum->getType() == IRRATIONAL_TYPE)
	{	
		Irrational* ir1 = (Irrational*) firstNum;
		Irrational* ir2 = (Irrational*) secondNum;
		if(ir1->name == ir2->name){
			return new Polynomial(new Integer(2), '*', ir1);
		}
		else {
			return new Polynomial(firstNum, '+', secondNum);
		}
	}

	//Add two Polynomials
	else if (firstNum->getType() == POLYNOMIAL_TYPE && secondNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* p1 = (Polynomial*) firstNum;
		Polynomial* p2 = (Polynomial*) secondNum;
		return p1->join(p2,'+');
	}
	/*
		Polynomial* poly1 = (Polynomial*) firstNum;
		Polynomial* poly2 = (Polynomial*) secondNum;
		vector<Number*> nums1 = poly2->numbers;
		vector<Number*> nums2 = poly2->numbers;
		vector<Number*> notAdded;
		for(int j=0; j<nums1.size(); j++){
			int i = 0;
			bool a = false;
			while(i<nums2.size() && !a){
				if (nums2[i]->getType() == nums1[j]->getType()){
					nums2[i] = add(nums1[j], nums2[i]);
					a = true;
				}
				i++;
				if (i==nums2.size())
					notAdded.push_back(nums1[j]);
			}
		}
		for(int k=0; k<notAdded.size(); k++)
			poly2 = (Polynomial*) add(poly2, notAdded[k]);
		return new Polynomial(poly2->numbers, poly2->operations);
	}
	//Add a Polynomial and another Number
	else if(firstNum->getType() == POLYNOMIAL_TYPE ||)
	{
		Polynomial* poly1 = (Polynomial*) firstNum;
		vector<Number*> nums = poly1->numbers;
		int i = 0;
		bool a = false;
		while(i<nums.size() && !a){
			if (nums[i]->getType() == secondNum->getType()){
				nums[i] = add(nums[i], secondNum);
				a = true;
			}
			i++;
			if(i == nums.size()){
				nums.push_back(secondNum);
				poly1->operations.push_back('+');
			}
		}
		return new Polynomial(nums, poly1->operations);
	}
	else if (secondNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* poly2 = (Polynomial*) secondNum;
		vector<Number*> nums(poly2->numbers);
		vector<char> ops(poly2->operations);

		while (!nums.empty())
		{
			Number* num1 = nums.back();
			Number* num2 = firstNum;
		
			cout << num1 << " + " << num2 << " | " << ops.back() <<endl;
			if (num1->getType() == num2->getType())
			{
				if (ops.back() != '*')
					return add(num1,num2);
				
			}
			else 
				ops.pop_back();
			nums.pop_back();
		}*/
		/*
		int i = 0;
		bool a = false;
		while(i<nums.size() && !){
			if (nums[i]->getType() == firstNum->getType()){
				nums[i] = add(firstNum, nums[i]);
				a = true;
			}
			i++;
			if(i == nums.size()){
				nums.push_back(firstNum);
				poly2->operations.push_back('+');
			}

		}
		return new Polynomial(nums, poly2->operations);
	}
		*/
		
	else if(firstNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* p1 = (Polynomial*) firstNum;
		return p1->push_back(secondNum,'+');
	}
	//For any other case create Polynomial
	else 
	{
		return (new Polynomial(firstNum,'+', secondNum))->simplify();
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
		return (new Fraction(num,den))->simplify();
	}
	
	//Subtract one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2-> num - f2->den * int1->value;
	  return (new Fraction(newNum, f2->den))->simplify();
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->num - f1->den * int2->value;
	  return (new Fraction(newNum, f1->den))->simplify();
	}
	
	//Subtract two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		if ((log1->base)->equals(log2->base))
			{

				Number* newPower = divide(log1->power,log2->power);
				return (new Log(log1->base,newPower))->simplify();
			}
		else {
			return new Polynomial(log1,'+',log2);// OR Change-of-base?
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
			return new Polynomial(firstNum, '-', secondNum);
		}
	}
	
	else if (firstNum->getType() == POLYNOMIAL_TYPE && secondNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* p1 = (Polynomial*) firstNum;
		Polynomial* p2 = (Polynomial*) secondNum;
		return p1->join(p2,'-');
	}
	//For any other case create Polynomial
	else 
	{
		return new Polynomial(firstNum,'-', secondNum);
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
		return (new Fraction(num,den))->simplify();
	}
	
	//Multiply one Fraction and one Integer
	else if (firstNum->getType() == INTEGER_TYPE && secondNum->getType() == FRACTION_TYPE){
	  Integer* int1 = (Integer*) firstNum;
	  Fraction* f2 = (Fraction*) secondNum;
	  int  newNum = f2->num * int1->value;
	  return (new Fraction(newNum, f2->den))->simplify();
	}
	else if (firstNum->getType() == FRACTION_TYPE && secondNum->getType() == INTEGER_TYPE){
	  Fraction* f1 = (Fraction*) firstNum;
	  Integer* int2 = (Integer*) secondNum;
	  int  newNum = f1->num * int2->value;
	  return (new Fraction(newNum, f1->den))->simplify();
	}
	//Multiply two Logs
	else if (firstNum->getType() == LOG_TYPE
		&& secondNum->getType() == LOG_TYPE)
	{
		Log* log1 = (Log*) firstNum;
		Log* log2 = (Log*) secondNum;
		/*if (log1->power == log2->base)
			{
				return new Log(log1->base,log2->power);
			}
		else {*/
			return new Polynomial(log1,'*',log2); 
		//}		
	}

	//Multiply two Powers
	else if(firstNum->getType() == POWER_TYPE && secondNum->getType() == POWER_TYPE)
	{
		Power* pow1 = (Power*) firstNum;
		Power* pow2 = (Power*) secondNum;
		if(pow1->base == pow2->base)
			return new Power(pow1->base, add(pow1->power, pow2->power));
		else{
			return new Polynomial(firstNum, '*', secondNum);
		}
	}
	// Multiply two Roots
	else if (firstNum->getType() == ROOT_TYPE && secondNum->getType() == ROOT_TYPE)
	{
		Root* rt1 = (Root*) firstNum;
		Root* rt2 = (Root*) secondNum;
		if ((rt1->root)->equals(rt2->root))
		{
			Number* newBase = multiply(rt1->base,rt2->base);
			return Root(newBase,rt1->root).simplify();
			
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
			return new Polynomial(firstNum, '*', secondNum);
		}
	}
	
	else if (firstNum->getType() == POLYNOMIAL_TYPE && secondNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* p1 = (Polynomial*) firstNum;
		Polynomial* p2 = (Polynomial*) secondNum;
		return p1->join(p2,'*');
	}
	//For any other case create Polynomial
	return new Polynomial(firstNum,'*', secondNum);
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
			return new Polynomial(log1,'*',log2); 
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
			return new Polynomial(firstNum, '/', secondNum);
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
			return new Polynomial(firstNum, '/', secondNum);
		}
	}
	

	else if (firstNum->getType() == POLYNOMIAL_TYPE && secondNum->getType() == POLYNOMIAL_TYPE)
	{
		Polynomial* p1 = (Polynomial*) firstNum;
		Polynomial* p2 = (Polynomial*) secondNum;
		return p1->join(p2,'/');
	}
	//For any other case create Polynomial
	else 
	{
		return new Polynomial(firstNum,'+', secondNum);
	}
	
	//TODO For debugging
	throw  runtime_error("Number type not supported");
	return new Integer(-1);	
}

