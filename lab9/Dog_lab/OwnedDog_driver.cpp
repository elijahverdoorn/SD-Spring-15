/* driver program for OwnedDog.
   RAB 3/2003 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;


#include "OwnedDog.h"

/* helper function for checking state changes from methods
   prints four labelled values of type OwnedDog.
   Example call:  
     print_all("var1", var1, "var2", var2, 
               "var3", var3, "var4", var4) 
 */

void print_all
(const char *varname1, const OwnedDog &obj1,
 const char *varname2, const OwnedDog &obj2,
 const char *varname3, const OwnedDog &obj3,
 const char *varname4, const OwnedDog &obj4)
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
  cout << "*** Driver program for OwnedDog class ***" << endl;


  cout << endl 
       << "*** Testing constructors, assignment operator, display() method ***"
       << endl << endl;


  cout << endl << "Test of typical constructor:" << endl;
  cout << "  Dog dog1(\"Fido\", 4);" << endl;
  Dog dog1("Fido", 4);
  cout << "  OwnedDog od1(dog1, \"Bob\");" << endl;
  OwnedDog od1(dog1, "Bob");
  cout << "  calling od1.display(cout);" << endl
       << "    output is:" << endl;
  od1.display(cout);   cout << endl;

  cout << endl << "Test of default constructor:" << endl;
  cout << "  OwnedDog od2;" << endl;
  OwnedDog od2;
  cout << "  calling od2.display(cout);" << endl
       << "    output is:" << endl;
  od2.display(cout);   cout << endl;

  cout << endl << "Test of copy constructor:" << endl;
  cout << "  OwnedDog od3(od1);" << endl;
  OwnedDog od3(od1);
  cout << "  calling od3.display(cout);" << endl
       << "    output is:" << endl;
  od3.display(cout);   cout << endl;

  cout << endl << "Test of assignment operator:" << endl;
  cout << "  Dog dog4(\"Spot\", 6);" << endl;
  Dog dog4("Spot", 6);
  cout << "  OwnedDog od4(dog4, \"Sue\");" << endl;
  OwnedDog od4(dog4, "Sue");
  print_all("od1", od1, "od2", od2, "od3", od3, "od4", od4);
  cout << "  calling (od1 = od4).display(cout);" << endl
       << "    output is:" << endl;
  (od1 = od4).display(cout);   cout << endl;
  cout << "  state change:" << endl;
  print_all("od1", od1, "od2", od2, "od3", od3, "od4", od4);
  cout << "  further test of return value from assignment:" << endl;
  cout << "  (od4 = od3).birthday();" << endl;
  (od4 = od3).birthday();
  cout << "  (od2 = od3).set_owner(\"Mary\");" << endl;
  (od2 = od3).set_owner("Mary");
  cout << "  state change:" << endl;
  print_all("od1", od1, "od2", od2, "od3", od3, "od4", od4);

  cout << endl 
       << "*** Testing remaining methods ***"
       << endl << endl;


  cout << endl << "Test of get_ methods:" << endl;
  cout << "  calling od1.display(cout);" << endl
       << "    output is:" << endl;
  od1.display(cout);   cout << endl;
  cout << "  od1.get_name() returns "
       << od1.get_name() << "." << endl;
  cout << "  od1.get_age() returns "
       << od1.get_age() << "." << endl;
  cout << "  od1.get_owner() returns "
       << od1.get_owner() << "." << endl;

  cout << endl << "Test of set_ and birthday methods:" << endl;
  cout << "  initial values of all variables:" << endl;
  print_all("od1", od1, "od2", od2, "od3", od3, "od4", od4);
  cout << "  od3.set_name(\"Mutt\");" << endl;
  od3.set_name("Mutt");
  cout << "  calling od3.display(cout);" << endl
       << "    output is:" << endl;
  od3.display(cout);   cout << endl;
  cout << "  od1.set_owner(\"Jeff\");" << endl;
  od1.set_owner("Jeff");
  cout << "  od1.birthday();" << endl;
  od1.birthday();
  cout << "  calling od1.display(cout);" << endl
       << "    output is:" << endl;
  od1.display(cout);   cout << endl;
  cout << "final values of all variables:" << endl;
print_all("od1", od1, "od2", od2, "od3", od3, "od4", od4);

  cout << endl << "Test of output operator:" << endl;
  cout << "cout << od1 << endl;" << endl;
  cout << od1 << endl;
  cout << endl;

  return 0;
}
