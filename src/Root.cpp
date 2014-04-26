#include "Number.h"
#include"Operations.h"
#include <iostream>
#include <math.h>
#include <stdexcept>

Root::Root(Number* base, Number* n)
{
	if (n->getEstimate() == 0)
		throw domain_error("Cannot take 0th root");
	// TODO throw excpetion for negitive roots?
	if ((int)n->getEstimate() % 2 == 0 && base->getEstimate() < 0)
		throw domain_error("Cannot take even root of negitive number");
	this->base = base;
	this->root = n;
}

Root::Root(int base, int n)
{
	if (n == 0)
		throw domain_error("Cannot take 0th root");
	if (n % 2 == 0 && base < 0)
		throw domain_error("Cannot take even root of negitive number");
	this->base = new Integer(base);
	this->root = new Integer(n);
}

string Root::toString()
{
	ostringstream oss;
	oss << root<< "rt:" << base;
	return oss.str();
}

double Root::getEstimate()
{
	return pow(base->getEstimate(), 1/root->getEstimate());
}
Number* Root::simplify()
{
	// TODO Simplify
	// TODO Generalize for Numbers*
	if (base->getType() == INTEGER_TYPE && root->getType() == INTEGER_TYPE)
	{

		const int x = base->getEstimate();
		const int n = root->getEstimate();
		if (x==0)
			return new Integer(0);
		if (x==1)
			return new Integer(x);
		if (x>0)
		{
			for (int i=0; i<x/2+1; i++)
			{
				int temp = 1;
				if (n>0) {
					for (int j=0; j<n; j++)
						temp *= i;
					if (temp == x) 
						return new Integer(i);
				}
				else {
					for (int j=0; j<-n; j++)
						temp *= i;
					if (temp == x) 
						return new Fraction(1,i);
				}

			}
		}
		if (n % 2 != 0)
		{
			for (int i=0; i<-x/2+1; i++)
			{
				int temp = 1;

				if (n>0) {
					for (int j=0; j<n; j++)
						temp *= i;
					if (temp == -x) 
						return new Integer(-i);
				}
				else {
					for (int j=0; j<-n; j++)
						temp *= i;
					if (temp == -x) 
						return new Fraction(-1,i);
				}

			}
		}
	}
	
	return this;
}
// TODO Deconstructor
Root::~Root()
{

}
