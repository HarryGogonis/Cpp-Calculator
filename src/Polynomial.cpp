#include "Number.h"
#include "Operations.h"
#include <iostream>

Polynomial::Polynomial()
{
	numbers = vector<Number*>();
	operations = vector<char>();
}

Polynomial::Polynomial(vector<Number*> numbers, vector<char> operations)
{
	this->numbers=numbers;
	this->operations=operations;
}

Polynomial::Polynomial(Number* num1, char op, Number* num2) 
{
	Polynomial();
	numbers.push_back(num1);
	numbers.push_back(num2);
	operations.push_back(op);
}

Number* Polynomial::join(Polynomial* p2, char op)
{
	for (int i=0; i<p2->numbers.size(); i++)
	{
		numbers.push_back(p2->numbers[i]);
	}
	operations.push_back(op);	
	for (int i=0; i<p2->operations.size(); i++)
	{
		operations.push_back(p2->operations[i]);
	}
	return this->simplify();	
}

Number* Polynomial::push_back(Number* num, char op)
{
	numbers.push_back(num);
	operations.push_back(op);
	return this->simplify();
}

Polynomial::~Polynomial()
{
	
}

string Polynomial::toString()
{
	ostringstream oss;
	int capacity;
	
	if (numbers.size()>=operations.size())
		capacity = numbers.size();
	else 
		capacity = operations.size();

	for (int i=0; i<capacity; i++)
	{
		if (i<operations.size())
			oss << numbers[i] << " " << operations[i] << " ";
		else
			oss << numbers[i];
	}
	
	return oss.str();
}

Number* Polynomial::simplify()
{
	//cout << this << endl;
	/*
	for (int i=0; i<numbers.size();i++)
	{
		for (int j=(i+1);j<numbers.size();j++)
		{
			char firstOp_Left = operations[i-1];
			char firstOp_Right = operations[i];
			char secondOp_Left = operations[j-1];
			char secondOp_Right = operations[j];
			if (numbers[i]->getType() == numbers[j]->getType()){
				if (secondOp_Left = '+' && firstOp_Left != '*' && firstOp_Right != '*' && secondOp_Right != '*') {
					numbers.push_back(Operations::add(numbers[i],numbers[j]));
				}
				//cout << "(" << numbers[i] << "+" << numbers[j] << ")" << endl;
			}
		}
	}*/
	return this;
	//TODO Implement Simplify
}


double Polynomial::getEstimate()
{
	//TODO IMPLEMENT
	return -1;
}
