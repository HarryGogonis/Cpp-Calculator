#include "Number.h"
#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "Numbers test" << endl;

	Number* f1 = new Fraction(4, 10);
	Number* f2 = new Fraction(2, 2);
	Number* int1 = new Integer(5);
	Number* logTester = new Log(3, 8);

	cout << "f1: " << f1 << " " << f1->simplify() << endl;
	cout << "f2: " << f2 << " " << f2->simplify() << endl;
	cout << "int1: " << int1 << endl << endl;

	cout << "Regex test" << endl;
	using namespace boost::xpressive;

	std::string hello("5+log:5+5/2");
	//(\d) ([\+\-\*\/]) (log:\d+)
	sregex rex = sregex::compile(
			"((\\d)||([\\+\\-\\*/])||(\\w+:\\d+)||(?:\\s))+");
	smatch what;

	regex_match(hello, what, rex);
	for (int i = 0; i < what.size(); i++)
		std::cout << what[i] << '\n';

	cout << "Log Test Area" << endl;
	//logTester->simplify();
	cout << logTester->simplify() << endl;

}

