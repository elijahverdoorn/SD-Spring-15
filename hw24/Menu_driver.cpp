/* driver program for Menu.
   RAB 3/2003 */

#include <iostream>
using namespace std;

#include "Menu.h"

/* helper function for checking state changes from methods
   prints four labelled values of type Menu.
   Example call:  
     print_all("var1", var1, "var2", var2, 
               "var3", var3, "var4", var4) 
 */

void print_all
(const char *varname1, Menu obj1,
 const char *varname2, Menu obj2,
 const char *varname3, Menu obj3,
 const char *varname4, Menu obj4)
{
  cout << "\t" << varname1 << ":\t";
  obj1.display();  cout << endl;
  cout << "\t" << varname2 << ":\t";
  obj2.display();  cout << endl;
  cout << "\t" << varname3 << ":\t";
  obj3.display();  cout << endl;
  cout << "\t" << varname4 << ":\t";
  obj4.display();  cout << endl << endl;
}


/* main() for driver */

int main()
{
  cout << "*** Driver program for Menu class ***" << endl;

  cout << endl 
       << "*** Testing typical constructor, display, get_ and set_ methods ***"
       << endl << endl;


  cout << endl << "Test of typical constructor:" << endl;
  cout << "  Menu menu1(4);" << endl;
  Menu menu1(4);
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;
  cout << "Defining some MenuItem objects for further testing...:" << endl;
  cout << "  MenuItem mi1(10, \"first item\");" << endl;
  MenuItem mi1(10, "first item");
  cout << "  MenuItem mi2(20, \"second item\");" << endl;
  MenuItem mi2(20, "second item");
  cout << "  MenuItem mi3(30, \"third item\");" << endl;
  MenuItem mi3(30, "third item");
  cout << "  MenuItem mi4(40, \"fourth item\");" << endl;
  MenuItem mi4(40, "fourth item");
  cout << "  MenuItem mi5(50, \"fifth item\");" << endl;
  MenuItem mi5(50, "fifth item");

  cout << endl << "Test of get_ methods:" << endl;
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;
  cout << "  menu1.get_size() returns "
       << menu1.get_size() << "." << endl;
  cout << "  menu1.get_count() returns "
       << menu1.get_count() << "." << endl;
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;

  cout << endl 
       << "*** Testing add_item, index operator, get_value ***"
       << endl << endl;


  cout << endl << "Test of add_item():" << endl;
  cout << "  menu1.add_item(mi1) returns "
       << menu1.add_item(mi1) << "." << endl;
  cout << "  menu1.add_item(17, \"another item\") returns "
       << menu1.add_item(17, "another item") << "." << endl;
  cout << "  menu1.get_count() returns "
       << menu1.get_count() << "." << endl;
  cout << "  menu1.get_not_found() returns "
       << menu1.get_not_found() << "." << endl;
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;

  cout << endl << "Test of index operator:" << endl;
  cout << "  menu1[1].display();" << endl;
  menu1[1].display();
  cout << "  menu1[0].set_val(11);" << endl;
  menu1[0].set_val(11);
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;

  cout << endl << "Test of get_value:" << endl;
  cout << "  int val = -10;" << endl;
  int val = -10;
  cout << "  val = menu1.get_value();" << endl;
  val = menu1.get_value();
  cout << "  val returns "
       << val << "." << endl;
  cout << "  val = menu1.get_value();" << endl;
  val = menu1.get_value();
  cout << "  val returns "
       << val << "." << endl;
  cout << "  val = menu1.get_value();" << endl;
  val = menu1.get_value();
  cout << "  val returns "
       << val << "." << endl;
  cout << "  calling menu1.display();" << endl
       << "    output is:" << endl;
  menu1.display();   cout << endl;

  cout << endl 
       << "*** Testing other constructors, assignment operator ***"
       << endl << endl;


  cout << endl << "Test of default constructor:" << endl;
  cout << "  Menu menu2;" << endl;
  Menu menu2;
  cout << "  calling menu2.display();" << endl
       << "    output is:" << endl;
  menu2.display();   cout << endl;

  cout << endl << "Test of copy constructor:" << endl;
  cout << "  Menu menu3(menu1);" << endl;
  Menu menu3(menu1);
  cout << "  calling menu3.display();" << endl
       << "    output is:" << endl;
  menu3.display();   cout << endl;

  cout << endl << "Test of assignment operator:" << endl;
  cout << "  Menu menu4(6);" << endl;
  Menu menu4(6);
  cout << "  menu4.add_item(5, \"An item\") returns "
       << menu4.add_item(5, "An item") << "." << endl;
  cout << "  menu4.add_item(mi2) returns "
       << menu4.add_item(mi2) << "." << endl;
  print_all("menu1", menu1, "menu2", menu2, "menu3", menu3, "menu4", menu4);
  cout << "  calling (menu1 = menu4).display();" << endl
       << "    output is:" << endl;
  (menu1 = menu4).display();   cout << endl;
  cout << "  state change:" << endl;
  print_all("menu1", menu1, "menu2", menu2, "menu3", menu3, "menu4", menu4);
  cout << "  further test of return value from assignment:" << endl;
  cout << "  (menu4 = menu3).add_item(mi3);" << endl;
  (menu4 = menu3).add_item(mi3);
  cout << "  state change:" << endl;
  print_all("menu1", menu1, "menu2", menu2, "menu3", menu3, "menu4", menu4);

  cout << endl << "Test of add_item, continued:" << endl;
  cout << "  menu4.add_item(mi4) returns "
       << menu4.add_item(mi4) << "." << endl;
  cout << "  menu4.add_item(mi5) returns "
       << menu4.add_item(mi5) << "." << endl;
  cout << "final values of all variables:" << endl;
  print_all("menu1", menu1, "menu2", menu2, "menu3", menu3, "menu4", menu4);
  cout << endl;
 
  return 0;
}