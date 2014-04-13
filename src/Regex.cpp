#include <pcrecpp.h>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "Number.h"

struct operation
{
	string symbol;
	int prec;
	char assoc;
	
	operation(string s, int p, char a):symbol(s),prec(p),assoc(a) {};
	operation() { operation(" ",-1,'0'); };
};

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

	// Shunting-Yard Algoirthm
	
	// Output Queue
	deque<string> output;
	
	// Operator Stack
	vector<operation> oper;
	
	for (int i=0; i<x.size(); i++) 
	{
		// Match basic operators
		pcrecpp::RE rOps("([\\+\\-\\/\\*\\^\\(\\)])");
		
		// TODO testing
		for (int j=0; j<output.size();j++) {
			cout << " ";
			cout << output[j];
		}
		cout.flush();	
		cout << endl;
		
		// Handle parenthesis
		if (x[i] == ")")
		{
			for (int i=0; i<oper.size();i++)
			{
				if (oper.back().symbol == "(" ) {
					oper.pop_back();
					break;
				}
				else {
                			output.push_back(oper.back().symbol);
              				oper.pop_back();
				}
       			 }
		}
	
		else if (rOps.FullMatch(x[i])) {
			operation op1;
			operation op2;
			
			if (!oper.empty())
				op2  = oper.back();

			if (x[i] == "+") op1 = operation("+",2,'L');
			else if (x[i] == "-") op1 = operation("-",2,'L');
			else if (x[i] == "/") op1 = operation("/",3,'L');
			else if (x[i] == "*") op1 = operation("*",3,'L');
			else if (x[i] == "^") op1 = operation("^",4,'R');
			else if (x[i] == "(") op1 = operation("(",9,'L');
			
			if ((op1.assoc == 'L' && op1.prec == op2.prec) 
				|| op1.prec < op2.prec) 
			{
				output.push_back(op2.symbol);
				oper.pop_back();
			} 
			oper.push_back(op1);
		}	

		else {
			output.push_back(x[i]);	
		}
		
		/*	
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
		}*/
	}
	
	while (!oper.empty())
	{
		output.push_back(string(oper.back().symbol));
		oper.pop_back();
	}

	cout << "Parsed Input: ";
	for (int i=0; i<output.size(); i++)
		cout << output[i] << " ";
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


