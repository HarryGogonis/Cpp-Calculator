#include <string>
#include <sstream>

using namespace std;

#define FRACTION_TYPE "Fraction"
#define INTEGER_TYPE "Integer"
#define IRRATIONAL_TYPE "Irrational"
#define LOG_TYPE "Log"


// Base class
class Number 
{
	public:
		virtual string toString() = 0;	
		virtual string getType() = 0;

		friend ostream& operator<<(ostream& out, Number* num) 
		{
			out << num->toString() << endl;
		}
};

class Integer:public Number
{
	public:
		int value;

		Integer(int);
	
		string toString();
		string getType() { return INTEGER_TYPE; };
};


class Fraction:public Number
{
	public:
		Number* num;
		Number* den;

		Fraction(Number*, Number*);
		Fraction(int, int);
		Fraction(string,string);
		~Fraction();

		string toString();
		string getType() { return FRACTION_TYPE; };
};

class Log: public Number{
	public:
		Number* base;
		Number* power;

		Log(Number*, Number*);
		Log(string, string);
		Log(int, int);
		~Log();
		
		string toString();
		string getType() {return LOG_TYPE; };
};



class Irrational:public Number
{
	public:
		string name;
		Irrational(string s):name(s){};
  		
  		string toString();
  		string getType() { return IRRATIONAL_TYPE; };

};

