#include <regex.h>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() 
{
	regex_t regex;
	
	string pattern = "((\\d+)+).+";	
	string input = "5 + 5";

	// Compile regular expression
	int compile = regcomp(&regex,pattern.c_str(),0);
	if (compile) { cout << "could not compile" ;}
	
	// Execute regular expression
	regmatch_t rmatch[1];
	int execute = regexec(&regex,input.c_str(),0,rmatch,0);
	if (!execute)
		cout << "Matched" << endl;
	
	else if (execute == REG_NOMATCH )
		cout << "No match" << endl;
	else 
		throw runtime_error("Regex match failed");
	
	regfree(&regex);
	return 0;
}
