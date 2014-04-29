#include <pcrecpp.h>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "Number.h"
#include "Operations.h"
#include <stdexcept>

using namespace std;

Number* ans;

struct operation
{
	string symbol;
	int prec;
	char assoc;
	
	operation(string s, int p, char a):symbol(s),prec(p),assoc(a) {};
	operation() { operation("null",-1,'0'); };
};

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

/* 
 * Preforms the Shunting-Yard Algorithm
 * See: https://en.wikipedia.org/wiki/Shunting_yard_algorithm
 */
deque<string> parseInput(vector<string> x)
{
	
	// Output Queue
	deque<string> output;
	
	// Operator Stack
	vector<operation> oper;
	
	// Put operations on the stack, numbers to queue
	for (int i=0; i<x.size(); i++) 
	{
		// Match basic operators
		pcrecpp::RE rOps("([\\+\\-\\/\\*\\^\\(\\)])");
		
		// Handle parenthesis
		if (x[i] == ")")
		{
			//for (int i=0; i<oper.size();i++)
			while (!oper.empty())
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
	}

	// Pop all leftover operations to the queue	
	while (!oper.empty())
	{
		operation op = oper.back();
		if (op.symbol == "(" || op.symbol == ")")
			throw invalid_argument("Mismatched parenthesis");
		output.push_back(string(oper.back().symbol));
		oper.pop_back();
	}
	/* For Debugging:
	cout << "Parsed Input: ";
	for (int i=0; i<output.size(); i++)
		cout << output[i] << " ";
	cout << endl;
	*/
	return output;	
}

/*
 * This method drives all of the calculations
 * Takes in a mathematical expression as a string
 * Each token must have a space inbetween
 * EX: "5 * ( 1 + 10 ) ^ 2"
*/
void evaluate(string input)
{
	vector<string> inputTokens = split(input,' ');
	deque<string> queue = parseInput(inputTokens);
	
	vector<Number*> numStack;

	for (int i=0; i<queue.size(); i++)
	{
		string token = queue[i];
		
		// Regex 
		pcrecpp::RE rInt("(-?\\d+)"); // Integer
		pcrecpp::RE rFrac("(-?\\d+)\\/(-?\\d+)"); // Fraction
		pcrecpp::RE rDec("(-?\\d+\\.\\d+)"); // Decimals
		pcrecpp::RE rOps("([\\+\\-\\/\\*\\^\\(\\)])"); // Operations
		pcrecpp::RE rLog("log_(\\w+):(-?\\w+)"); // Logs		
		pcrecpp::RE rRoot("(-?\\d+)rt:(-?\\d+)"); // Roots
		// Used to capture numbers from regex
		int val1 = 0;
		int val2 = 0;
		double val3 = 0;
		string str1= " ";
		string str2= " ";
			
		if (rInt.FullMatch(token, &val1))
		{
			numStack.push_back(new Integer(val1));
		}
		else if (rFrac.FullMatch(token, &val1, &val2))
		{
			
			numStack.push_back((new Fraction(val1,val2))->simplify());
		}
		/*else if (rDec.FullMatch(token), &val3)
		{
			numStack.push_back(new Fraction(val3));
		}*/
		else if (rLog.FullMatch(token, &str1,&str2))
		{
			numStack.push_back(Log(str1,str2).simplify());
		//	numStack.push_back((new Log(str1,str2))->simplify());
		}
		else if (token == "e" || token == "pi")
		{
			numStack.push_back(new Irrational(token));
		}
		else if (rRoot.FullMatch(token, &val1, &val2))
		{
			numStack.push_back((new Root(val2,val1))->simplify());
		}
		else if (token == "ans" || token == "Ans")
		{
			numStack.push_back(ans);
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
				numStack.push_back((new Power(val1,val2))->simplify());
		}
		else {
			stringstream ss;
			ss << "Invalid token \"" << token << "\"";
			throw invalid_argument(ss.str());
		}
	}
	if (numStack.size() > 0) {
		cout << " = " <<  numStack[0] << endl;
		ans = numStack[0];
	}
}

int main()
{
	cout << endl << "C++ Calculator" << endl;
	cout << 	"=============="<< endl;
	/*cout << "===Debugging Area===" << endl;
	Number* int1 = new Integer(2);
	Number* int2 = new Integer(2);
	Number* int3 = new Integer(3);
	cout << int1->equals(int2) << endl;
	cout << int1->equals(int3) << endl;
	Number*  ir1 = new Irrational("pi");
	Number*  ir2 = new Irrational("pi");
	Number* poly1 = Operations::add(ir1,ir2);
	Number* poly2 = Operations::add(int1,poly1);	
	cout << "2pi + 2 = " << poly2 << endl;
	cout << "====================" << endl;*/	

	string input;

	while (true) {
	cout << ">> ";
	getline(cin,input);

	if (input == "quit" || input == "q")
		return 0;	
	if (input == "help")
	{
		cout << "All expressions must be seperated by a space." << endl;
		cout << "Examples of valid expressions:" << endl;
		cout << "\t( 1/2 + 3/2 ) *  5 ^ 2" << endl;
		cout << "\tlog_10:10" << endl;
		cout << "\t2rt:16" << endl;
		continue;
	}
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


