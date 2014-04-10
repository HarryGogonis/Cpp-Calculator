#ifndef _NUMBER_H_
#define _NUMBER_H_

#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define FRACTION_TYPE "Fraction"
#define INTEGER_TYPE "Integer"
#define IRRATIONAL_TYPE "Irrational"
#define LOG_TYPE "Log"

// Base class
class Number
{
public:
	virtual Number* simplify() = 0;
	virtual string toString() = 0;
	virtual string getType() = 0;
	virtual double getEstimate() = 0;

	friend ostream& operator<<(ostream& out, Number* num)
	{
		return out << num->toString();
	}
};

class Integer: public Number
{
public:
	int value;

	Integer(int);

	Number* simplify();
	string toString();
	double getEstimate();
	string getType()
	{
		return INTEGER_TYPE;
	}
	;
};

class Fraction: public Number
{
public:
	int num;
	int den;

	Fraction(Integer*, Integer*);
	Fraction(int, int);
	Fraction(string, string);
	//~Fraction();

	Number* simplify();
	string toString();
	double getEstimate();
	string getType()
	{
		return FRACTION_TYPE;
	}
	;

};

class Log: public Number
{
public:
	Number* base;
	Number* power;

	Log(string, string);
	Log(Number*, Number*);
	Log(int, int);
	~Log();

	Number* simplify();
	string toString();
	double getEstimate();
	string getType()
	{
		return LOG_TYPE;
	}
	;
};

class Irrational: public Number
{
public:
	string name;
	//Number* coeff;

	Irrational(const string s, Number* coeff):name(s){};

	Number* simplify();
	string toString();
	double getEstimate();
	string getType()
	{
		return IRRATIONAL_TYPE;
	}
	;

};

#endif
