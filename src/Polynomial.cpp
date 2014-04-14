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
		oss << numbers[i] << " " << operations[i];
	}
	
	return oss.str();
}

Number* Polynomial::simplify()
{
}


double Polynomial::getEstimate()
{
	//TODO IMPLEMENT
	return -1;
}
