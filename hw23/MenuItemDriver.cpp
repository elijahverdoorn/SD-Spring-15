#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#include "MenuItem.h"

int main()
{
  MenuItem m (2, "Hello,World!");
  MenuItem x (m);
  MenuItem y = m;
  m.display();
  x.display();
  y.display();
  return 0;
}