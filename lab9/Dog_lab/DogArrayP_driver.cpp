/* driver program for DogArrayP.
   RAB 3/2003 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;


#include "DogArrayP.h"

/* helper function for checking state changes from methods
   prints four labelled values of type DogArrayP.
   Example call:  
     print_all("var1", var1, "var2", var2, 
               "var3", var3, "var4", var4) 
 */

void print_all
(const char *varname1, const DogArrayP &obj1,
 const char *varname2, const DogArrayP &obj2,
 const char *varname3, const DogArrayP &obj3,
 const char *varname4, const DogArrayP &obj4)
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
  cout << "*** Driver program for DogArrayP class ***" << endl;


  cout << endl 
       << "*** Testing constructors, assignment operator, display() method ***"
       << endl << endl;


  cout << endl << "Test of typical constructor:" << endl;
  cout << "  DogArrayP dap1(4);" << endl;
  DogArrayP dap1(4);
  cout << "  calling dap1.display(cout);" << endl
       << "    output is:" << endl;
  dap1.display(cout);   cout << endl;

  cout << endl << "Test of default constructor:" << endl;
  cout << "  DogArrayP dap2;" << endl;
  DogArrayP dap2;
  cout << "  calling dap2.display(cout);" << endl
       << "    output is:" << endl;
  dap2.display(cout);   cout << endl;
  cout << "Defining some Dog objects for further testing...:" << endl;
  cout << "  Dog dog1(\"Fido\", 4);" << endl;
  Dog dog1("Fido", 4);
  cout << "  Dog dog2(\"Lady\", 2);" << endl;
  Dog dog2("Lady", 2);
  cout << "  Dog dog3(\"Spot\", 5);" << endl;
  Dog dog3("Spot", 5);
  cout << "  Dog dog4(\"Lassie\", 10);" << endl;
  Dog dog4("Lassie", 10);
  cout << "  Dog dog5(\"Snoopy\", 3);" << endl;
  Dog dog5("Snoopy", 3);

  cout << endl << "Test of index operator:" << endl;
  cout << "dap1[1] = dog1;" << endl;
  dap1[1] = dog1;
  cout << "dap1[2] = dog2;" << endl;
  dap1[2] = dog2;
  cout << "calling dap1[1].display(cout);" << endl
       << "  output is:" << endl;
  dap1[1].display(cout);   cout << endl;
  cout << "calling dap1.display(cout);" << endl
       << "  output is:" << endl;
  dap1.display(cout);   cout << endl;
  cout << "further test of return value from index operator::" << endl;
  cout << "dap1[3].birthday();" << endl;
  dap1[3].birthday();
  cout << "calling dap1.display(cout);" << endl
       << "  output is:" << endl;
  dap1.display(cout);   cout << endl;

  cout << endl << "Test of copy constructor:" << endl;
  cout << "  DogArrayP dap3(dap1);" << endl;
  DogArrayP dap3(dap1);
  cout << "  calling dap3.display(cout);" << endl
       << "    output is:" << endl;
  dap3.display(cout);   cout << endl;

  cout << endl << "Test of assignment operator:" << endl;
  cout << "  DogArrayP dap4(6);" << endl;
  DogArrayP dap4(6);
  cout << "  dap4[0] = dog3;  dap4[5] = dog4;" << endl;
  dap4[0] = dog3;  dap4[5] = dog4;
  print_all("dap1", dap1, "dap2", dap2, "dap3", dap3, "dap4", dap4);
  cout << "  calling (dap1 = dap4).display(cout);" << endl
       << "    output is:" << endl;
  (dap1 = dap4).display(cout);   cout << endl;
  cout << "  state change:" << endl;
  print_all("dap1", dap1, "dap2", dap2, "dap3", dap3, "dap4", dap4);
  cout << "  further test of return value from assignment:" << endl;
  cout << "  (dap4 = dap3)[2] = dog5;" << endl;
  (dap4 = dap3)[2] = dog5;
  cout << "  (dap2 = dap3)[3].birthday();" << endl;
  (dap2 = dap3)[3].birthday();
  cout << "  state change:" << endl;
  print_all("dap1", dap1, "dap2", dap2, "dap3", dap3, "dap4", dap4);

  cout << endl 
       << "*** Testing remaining methods ***"
       << endl << endl;


  cout << endl << "Test of get_ methods:" << endl;
  cout << "  calling dap1.display(cout);" << endl
       << "    output is:" << endl;
  dap1.display(cout);   cout << endl;
  cout << "  dap1.get_size() returns "
       << dap1.get_size() << "." << endl;
  cout << "final values of all variables:" << endl;
print_all("dap1", dap1, "dap2", dap2, "dap3", dap3, "dap4", dap4);
  cout << endl;

  return 0;
}
