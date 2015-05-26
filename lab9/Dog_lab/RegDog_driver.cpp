/* driver program for RegDog.
   RAB 3/2003 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;


#include "RegDog.h"

/* helper function for checking state changes from methods
   prints four labelled values of type RegDog.
   Example call:  
     print_all("var1", var1, "var2", var2, 
               "var3", var3, "var4", var4) 
 */

void print_all
(const char *varname1, const RegDog &obj1,
 const char *varname2, const RegDog &obj2,
 const char *varname3, const RegDog &obj3,
 const char *varname4, const RegDog &obj4)
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
  cout << "*** Driver program for RegDog class ***" << endl;


  cout << endl 
       << "*** Testing constructors, assignment operator, display() method ***"
       << endl << endl;


  cout << endl << "Test of typical constructor:" << endl;
  cout << "  RegDog rdog1(\"Fido\", 4, 1111);" << endl;
  RegDog rdog1("Fido", 4, 1111);
  cout << "  calling rdog1.display(cout);" << endl
       << "    output is:" << endl;
  rdog1.display(cout);   cout << endl;

  cout << endl << "Test of blank at end of display():" << endl;
  cout << "rdog1.display(cout); cout << \"XXX\" << endl;" << endl;
  rdog1.display(cout); cout << "XXX" << endl;

  cout << endl << "Test of default constructor:" << endl;
  cout << "  RegDog rdog2;" << endl;
  RegDog rdog2;
  cout << "  calling rdog2.display(cout);" << endl
       << "    output is:" << endl;
  rdog2.display(cout);   cout << endl;

  cout << endl << "Test of copy constructor:" << endl;
  cout << "  RegDog rdog3(rdog1);" << endl;
  RegDog rdog3(rdog1);
  cout << "  calling rdog3.display(cout);" << endl
       << "    output is:" << endl;
  rdog3.display(cout);   cout << endl;

  cout << endl << "Test of assignment operator:" << endl;
  cout << "  RegDog rdog4(\"Spot\", 6, 2222);" << endl;
  RegDog rdog4("Spot", 6, 2222);
  print_all("rdog1", rdog1, "rdog2", rdog2, "rdog3", rdog3, "rdog4", rdog4);
  cout << "  calling (rdog1 = rdog4).display(cout);" << endl
       << "    output is:" << endl;
  (rdog1 = rdog4).display(cout);   cout << endl;
  cout << "  state change:" << endl;
  print_all("rdog1", rdog1, "rdog2", rdog2, "rdog3", rdog3, "rdog4", rdog4);
  cout << "  further test of return value from assignment:" << endl;
  cout << "  (rdog4 = rdog3).birthday();" << endl;
  (rdog4 = rdog3).birthday();
  cout << "  (rdog2 = rdog3).set_id(5555);" << endl;
  (rdog2 = rdog3).set_id(5555);
  cout << "  state change:" << endl;
  print_all("rdog1", rdog1, "rdog2", rdog2, "rdog3", rdog3, "rdog4", rdog4);

  cout << endl 
       << "*** Testing remaining methods ***"
       << endl << endl;


  cout << endl << "Test of get_ methods:" << endl;
  cout << "  calling rdog1.display(cout);" << endl
       << "    output is:" << endl;
  rdog1.display(cout);   cout << endl;
  cout << "  rdog1.get_name() returns "
       << rdog1.get_name() << "." << endl;
  cout << "  rdog1.get_age() returns "
       << rdog1.get_age() << "." << endl;
  cout << "  rdog1.get_id() returns "
       << rdog1.get_id() << "." << endl;

  cout << endl << "Test of set_ and birthday methods:" << endl;
  cout << "  initial values of all variables:" << endl;
  print_all("rdog1", rdog1, "rdog2", rdog2, "rdog3", rdog3, "rdog4", rdog4);
  cout << "  rdog3.set_name(\"Mutt\");" << endl;
  rdog3.set_name("Mutt");
  cout << "  calling rdog3.display(cout);" << endl
       << "    output is:" << endl;
  rdog3.display(cout);   cout << endl;
  cout << "  rdog1.set_id(6666);" << endl;
  rdog1.set_id(6666);
  cout << "  rdog1.birthday();" << endl;
  rdog1.birthday();
  cout << "  calling rdog1.display(cout);" << endl
       << "    output is:" << endl;
  rdog1.display(cout);   cout << endl;
  cout << "final values of all variables:" << endl;
print_all("rdog1", rdog1, "rdog2", rdog2, "rdog3", rdog3, "rdog4", rdog4);
  cout << endl;

  return 0;
}
