#include "Number.h"
#include <string>
#define TYPE "Log"

using namespace std;

class Log{
	public:
		Log(Number*, Number*);
		Log(string, string);
		~Log();
		
		string toString();
		string getType() {return TYPE};

		Number* base;
		Number* power;
};
