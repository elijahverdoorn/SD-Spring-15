/* Example implementation module for subclass and enum type
   CS 272  R. Brown, 3/99 */

#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include "OwnedDog.h"


/* "OwnedDog" class */

/* Data invariant:  
     data invariant for OwnedDog holds, and 
     owner is a (nonzero) null-terminated string 
        allocated via new */


/* o_init -- helper function
     Arguments:
       owner_val, string (null-terminated array of char)
     State change:  The state variables  owner  is assigned
       a newly allocated copy of  owner_val .
     Return:  None. */

void OwnedDog::o_init(const char *owner_val)
{
  owner = new char[strlen(owner_val) + 1];
  strcpy(owner, owner_val);
}


/* destructor */

OwnedDog::~OwnedDog()
{ 
  cout << "~OwnedDog() called" << endl;
  if (owner != 0) {
    delete [] owner; 
    owner = 0; 
  }
}


/* assignment operator */

OwnedDog &OwnedDog::operator=(const OwnedDog &odog) 
{ 
  Dog::operator=(odog);
  delete [] owner;  
  o_init(odog.owner); 
  return *this;
}


/* display */

void OwnedDog::display(ostream &ostr) const
{
  Dog::display(ostr);
  ostr << "[" << owner << "]";
}


/* set_owner -- method (see handout for specs) */

void OwnedDog::set_owner(const char *new_owner)
{
  delete [] owner;
  owner = new char[strlen(new_owner) + 1];
  strcpy(owner, new_owner);
}


/* output operator for OwnedDog */

ostream &operator<<(ostream &ostr, const OwnedDog &odog)
{
  odog.display(ostr);
  return ostr;
}

