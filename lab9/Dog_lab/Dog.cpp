/* Example implementation module for CS 272
   R. Brown, 2/98 */

#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include "Dog.h"


/* "Dog" class */

/* Data invariant:  
     name is a (nonzero) null-terminated string 
        allocated via new
     age is a non-negative integer */


/* init -- helper function
     Arguments:
       name_val, string (null-terminated array of char)
       age_val, non-negative integer
     State change:  The state variables  name  and  age
       are assigned the indicated values.
     Return:  None. */

void Dog::init(const char *name_val, int age_val)
{
  name = new char[strlen(name_val) + 1];
  strcpy(name, name_val);
  age = age_val;
}


/* destructor */

Dog::~Dog()
{ 
  //cout << "~Dog() called" << endl;
  if (name != 0) 
    delete [] name; 
  name = 0; 
}


/* assignment operator */

Dog &Dog::operator=(const Dog &dog) 
{ 
  delete [] name;  
  init(dog.name, dog.age); 
  return *this;
}


/* display -- print this instance of Dog, formatted as
       name (age)      */

void Dog::display(ostream &ostr) const
{
  ostr << name << "(" << age << ")";
}


/* set_name -- method (see handout for specs) */

void Dog::set_name(const char *new_name)
{
  delete [] name;
  name = new char[strlen(new_name) + 1];
  strcpy(name, new_name);
}

