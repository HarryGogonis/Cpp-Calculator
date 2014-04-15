#ifndef _NUMBER_H_
#define _NUMBER_H_

#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

#define FRACTION_TYPE "Fraction"
#define INTEGER_TYPE "Integer"
#define IRRATIONAL_TYPE "Irrational"
#define LOG_TYPE "Log"
#define POLYNOMIAL_TYPE "Polynomial"
#define POWER_TYPE "Power"

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
	Integer(string);

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
	Fraction(double);
	//~Fraction();

	static Number* convertDoubleToFraction(double);
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
	//virtual ~Log();

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

	Irrational(const string s):name(s){};

	Number* simplify();
	string toString();
	double getEstimate();
	//virtual ~Irrational();
	string getType()
	{
		return IRRATIONAL_TYPE;
	}
	;

};

class Power: public Number
{
public:
	Number* base;
	Number* power;

	Power(string, string);
	Power(Number*, Number*);
	Power(int, int);
	virtual ~Power();

	Number* simplify();
	string toString();
	double getEstimate();
	string getType()
	{
		return POWER_TYPE;
	}
	;
};

class Polynomial: public Number
{
	public:
		vector<Number*> numbers;
		vector<char> operations;
		
		Polynomial();
		Polynomial(string);
		Polynomial(vector<Number*>, vector<char>);	
		Polynomial(Number*, char, Number*);
		~Polynomial();

		Number* join(Number*);
		Number* simplify();
		string toString();
		double getEstimate();
		string getType() { return POLYNOMIAL_TYPE; };	

		Number* operator+(Number*);
};


#endif
