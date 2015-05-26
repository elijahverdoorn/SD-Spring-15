/* implementation module for RegDog */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <cassert>
#include "RegDog.h"

RegDog::RegDog(const char *nval, int aval, int ival)
: Dog(nval, aval)
{
  assert(ival >= 0);
  id = ival;
}

RegDog::RegDog()
: Dog()
{ 
  id = 0;
}

void RegDog::set_id(int newid)
{
  assert(newid >= 0);
  id = newid;
}

void RegDog::display(ostream &ostr) const
{
  Dog::display(ostr);
  ostr << " #" << id << " ";
}
