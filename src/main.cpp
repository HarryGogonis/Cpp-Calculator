#include <pcrecpp.h>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "Number.h"
#include "Operations.h"
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

deque<string> parseInput(vector<string> x)
{

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
	/*
	cout << "Parsed Input: ";
	for (int i=0; i<output.size(); i++)
		cout << output[i] << " ";
	cout << endl;
	*/
	return output;	
}

void evaluate(string input)
{
	vector<string> inputTokens = split(input,' ');
	deque<string> queue = parseInput(inputTokens);
	
	vector<Number*> numStack;

	for (int i=0; i<queue.size(); i++)
	{
		string token = queue[i];
		
		// Regex 
		pcrecpp::RE rInt("-?\\d+"); // Integer
		pcrecpp::RE rFrac("(-?\\d+)\\/(-?\\d+)"); // Fractiona
		pcrecpp::RE rDec("(\\d+\\.\\d+)"); // Decimals
		pcrecpp::RE rOps("([\\+\\-\\/\\*\\^\\(\\)])"); // Operations
		pcrecpp::RE rLog("log_(\\d+)\\((\\d+)\\)"); // Logs		
		// Used to capture numbers from regex
		int val1 = 0;
		int val2 = 0;
		double val3 = 0;
			
		if (rInt.FullMatch(token))
		{
			numStack.push_back(new Integer(token));
		}
		else if (rFrac.FullMatch(token, &val1, &val2))
		{
			
			numStack.push_back((new Fraction(val1,val2))->simplify());
		}
		/*else if (rDec.FullMatch(token), &val3)
		{
			numStack.push_back(new Fraction(val3));
		}*/
		else if (rLog.FullMatch(token, &val1, &val2))
		{
			numStack.push_back(Log(val1,val2).simplify());
		}
		else if (token == "e" || token == "pi")
		{
			numStack.push_back(new Irrational(token));
		}
		else if (rOps.FullMatch(token))
		{
			Number* val2 = numStack.back();
			numStack.pop_back();
			Number* val1 = numStack.back();
			numStack.pop_back();
		
			//cout << "d\t" << val1 << " " << val2;		
		
			if (token == "+")
				numStack.push_back(Operations::add(val1,val2));
			else if (token == "*")
				numStack.push_back(Operations::multiply(val1,val2));
			else if (token == "-")
				numStack.push_back(Operations::subtract(val1,val2));	
			else if (token == "/")
				numStack.push_back(Operations::divide(val1,val2));
			else if (token == "^")
				numStack.push_back(Power(val1,val2).simplify());
		}
		else {
			stringstream ss;
			ss << "Invalid token \"" << token << "\"";
			throw invalid_argument(ss.str());
		}
	}
	if (numStack.size() > 0)
		cout << " = " <<  numStack[0] << endl;

}

int main()
{
	cout << endl << "Calculator" << endl;
	cout << "Currently working: Integers, Fractions" << endl;
	cout << "Not tested: Log, Powers" << endl;
	cout << "Not implemented: nthRoot, e, pi" << endl;
/*	cout << "===========================" << endl;
	
	cout << "===Debugging Area===" << endl;
	
	Number* Int = new Integer(1);
	cout << "d\t new int made" << endl;
	Number* Frac = new Fraction(1,2);
	cout << "d\t new frac made" << endl;
	Number* Frac2 = new Fraction(1,2);
	cout << "d\t new frac made" << endl;
	
	cout << "d\t";	
	cout << Frac << " + " << Frac2 << " = " ;
	
	cout << Operations::add(Frac,Frac2) << endl;
	
	cout << "d\t" ;
	cout << Int << " + " << Int << " = ";
	cout << Operations::add(Int, Int) << endl;
	cout << Operations::add(Frac,Int) << endl;
	cout << Operations::add(Int,Frac) << endl;
	cout << endl;

	cout << "====================" << endl;
*/
	string input;

	while (true) {
	cout << "Enter expression: ";
	getline(cin,input);

	if (input == "quit" || input == "q")
		return 0;	
	try {
		evaluate(input); 
	} catch (domain_error e) {
		cout << e.what() << endl;
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	} catch (runtime_error e) {
		cout << e.what() << endl;
	} catch (exception e) {
		cout << "Error" << endl;
	}
	}
	return 0;	
}


