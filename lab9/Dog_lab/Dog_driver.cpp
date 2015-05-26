/* driver program for Dog.
   Example for CS 272;  RAB 3/99 rev 3/00 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include "Dog.h"

/* helper function for checking state changes from methods
   prints four labelled values of type Dog.
   Example call:  
     print_all("var1", var1, "var2", var2, 
               "var3", var3, "var4", var4) 
 */

void print_all
(const char *varname1, const Dog &obj1,
 const char *varname2, const Dog &obj2,
 const char *varname3, const Dog &obj3,
 const char *varname4, const Dog &obj4)
{
  cout << "\t" << varname1 << ":\t";  
  obj1.display(cout);  cout << endl;
  cout << "\t" << varname2 << ":\t";
  obj2.display(cout);  cout << endl;
  cout << "\t" << varname3 << ":\t";
  obj3.display(cout);  cout << endl;
  cout << "\t" << varname4 << ":\t";
  obj4.display(cout);  cout << endl << endl;
}


/* main() for driver */

int main()
{
  cout << "*** Driver program for Dog class ***" << endl;


  cout << endl 
       << "*** Testing constructors, assignment operator, display() method ***"
       << endl << endl;


  cout << endl << "Test of typical constructor:" << endl;
  cout << "  Dog dog1(\"Fido\", 4);" << endl;
  Dog dog1("Fido", 4);
  cout << "  calling dog1.display(cout);" << endl
       << "    output is:" << endl;
  dog1.display(cout);   cout << endl;

  cout << endl << "Test of default constructor:" << endl;
  cout << "  Dog dog2;" << endl;
  Dog dog2;
  cout << "  calling dog2.display(cout);" << endl
       << "    output is:" << endl;
  dog2.display(cout);   cout << endl;

  cout << endl << "Test of copy constructor:" << endl;
  cout << "  Dog dog3(dog1);" << endl;
  Dog dog3(dog1);
  cout << "  calling dog3.display(cout);" << endl
       << "    output is:" << endl;
  dog3.display(cout);   cout << endl;

  cout << endl << "Test of assignment operator:" << endl;
  cout << "  Dog dog4(\"Spot\", 6);" << endl;
  Dog dog4("Spot", 6);
  print_all("dog1", dog1, "dog2", dog2, "dog3", dog3, "dog4", dog4);
  cout << "  calling (dog1 = dog4).display(cout);" << endl
       << "    output is:" << endl;
  (dog1 = dog4).display(cout);   cout << endl;
  cout << "  state change:" << endl;
  print_all("dog1", dog1, "dog2", dog2, "dog3", dog3, "dog4", dog4);
  cout << "  further test of return value from assignment:" << endl;
  cout << "  (dog4 = dog3).birthday();" << endl;
  (dog4 = dog3).birthday();
  cout << "  state change:" << endl;
  print_all("dog1", dog1, "dog2", dog2, "dog3", dog3, "dog4", dog4);

  cout << endl 
       << "*** Testing remaining methods ***"
       << endl << endl;


  cout << endl << "Test of get_ methods:" << endl;
  cout << "  calling dog1.display(cout);" << endl
       << "    output is:" << endl;
  dog1.display(cout);   cout << endl;
  cout << "  dog1.get_name() returns "
       << dog1.get_name() << "." << endl;
  cout << "  dog1.get_age() returns "
       << dog1.get_age() << "." << endl;

  cout << endl << "Test of set_name and birthday methods:" << endl;
  cout << "  initial values of all variables:" << endl;
  print_all("dog1", dog1, "dog2", dog2, "dog3", dog3, "dog4", dog4);
  cout << "  dog3.set_name(\"Mutt\");" << endl;
  dog3.set_name("Mutt");
  cout << "  calling dog3.display(cout);" << endl
       << "    output is:" << endl;
  dog3.display(cout);   cout << endl;
  cout << "  dog1.birthday();" << endl;
  dog1.birthday();
  cout << "  calling dog1.display(cout);" << endl
       << "    output is:" << endl;
  dog1.display(cout);   cout << endl;
  cout << "  final values of all variables:" << endl;
  print_all("dog1", dog1, "dog2", dog2, "dog3", dog3, "dog4", dog4);
  cout << endl;

  return 0;
}
