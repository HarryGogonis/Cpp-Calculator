#include <pcrecpp.h>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "Number.h"
#include <stdexcept>
struct operation
{
	string symbol;
	int prec;
	char assoc;
	
	operation(string s, int p, char a):symbol(s),prec(p),assoc(a) {};
	operation() { operation("null",-1,'0'); };
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
			
			if (x[i] == "+") op1 = operation("+",2,'L');
			else if (x[i] == "-") op1 = operation("-",2,'L');
			else if (x[i] == "/") op1 = operation("/",3,'L');
			else if (x[i] == "*") op1 = operation("*",3,'L');
			else if (x[i] == "^") op1 = operation("^",4,'R');
			else if (x[i] == "(") op1 = operation("(",9,'L');
			
			//cout << "op 1 " << op1.symbol;
			//cout << "op 2 " << op2.symbol;
			if (!oper.empty())
			{
				operation op2 = oper.back();
				if (op2.symbol != "(" && ((op1.assoc == 'L' &&
				    op1.prec == op2.prec && op1.prec > 0) 
				    || op1.prec < op2.prec))
					{
						output.push_back(op2.symbol);
						oper.pop_back();
					} 
			}
			oper.push_back(op1);
		}	

		else {
			output.push_back(x[i]);	
		}
		//pcrecpp::RE rInt("-?\\d+");
		//pcrecpp::RE rFrac("(-?\\d+)\\/(-?\\d+)");
	}
	
	while (!oper.empty())
	{
		operation op = oper.back();
		if (op.symbol == "(" || op.symbol == ")")
			throw invalid_argument("Mismatched parenthesis");
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


