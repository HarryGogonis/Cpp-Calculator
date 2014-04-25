#include "Number.h"

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
	//TODO Implement Simplify
}


double Polynomial::getEstimate()
{
	//TODO IMPLEMENT
	return -1;
}
