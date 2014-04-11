#include "Number.h"


Number* Irrational::simplify()
{
return this;
}

string Irrational::toString()
{
return this->name;
}

double Irrational::getEstimate()
{
 if(name=="e")
   return 2.718;
 if(name=="pi")
   return 3.142;
}
