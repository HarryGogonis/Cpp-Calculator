/**
 * Standard int represented as a Number
 */ 
#include "Number.h"

#define TYPE "Integer"

class Integer:public Number
{
	public:
		int value;

		Integer(int);
	
		string toString();
		string getType() { return TYPE; };
};
