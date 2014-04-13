#include <pcrecpp.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "Number.h"

using namespace std;

vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	
	stringstream ss(s);
	string item;
	while (getline(ss,item,delim)) {
		elems.push_back(item);
	}
	return elems;
}

void parseInput(string input)
{
	vector<string> x = split(input,' ');

	vector<Number*> nums;
	vector<string> oper;
	
	for (int i=0; i<x.size(); i++) 
	{
		// Match basic operators
		pcrecpp::RE rOps("([\\+\\-\\/\\*])");
		if (rOps.FullMatch(x[i])) {
			oper.push_back(x[i]);
			continue;
		}	
			
		// Match Integers	
		pcrecpp::RE rInt("-?\\d+");
		if (rInt.FullMatch(x[i])) {
			nums.push_back(new Integer(x[i]));
			continue;
		}
		// Match Fractions	
		pcrecpp::RE rFrac("(-?\\d+)\\/(-?\\d+)");
		int num=0;
		int den=0;
		if (rFrac.FullMatch(x[i],&num,&den)) {
			nums.push_back(Fraction(num,den).simplify());
			continue;
		}
	}
	
	cout << "Parsed: ";
	for (int i=0; i<nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;	
}

int main()
{
	cout << "Calculator" << endl;
	cout << "Currently supports: integers, fractions" << endl;
	string input;

	cout << "Enter expression (spaces seperate values/operations):" << endl;
	getline(cin,input);
	
	parseInput(input);
	return 0;	
}


