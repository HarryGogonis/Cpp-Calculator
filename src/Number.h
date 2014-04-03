#include <string>
#include <sstream>

using namespace std;

class Number 
{
	public:
		virtual string toString() = 0;	
		friend ostream& operator<<(ostream& out, Number* num) 
		{
			out << num->toString() << endl;
		}
};
