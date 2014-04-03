#include <iostream>
#include <regex>

using namespace std;


void parseInput(string input)
{
	typedef match_results<const char*> cmatch;
	
	// Regex to match
	regex rx(".+");
	
	// Resolved text
	cmatch res;

	regex_match(input.c_str(),res,rx);

	for (int i=0; i<res.size(); i++)	
		cout << res[i];
	cout << endl;
}


int main()
{
	parseInput("test");
	return 0;
}
