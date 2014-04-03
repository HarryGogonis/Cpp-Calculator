using namespace std;
#include<iostream>

#define Type = "Irrational"

class Irrational{
 public:
 Irrational(string s):name(s){};
  ~Irrational();
  string name;
  ostream& operator<<(ostream& o, Irrational&);
  string toString();
};
