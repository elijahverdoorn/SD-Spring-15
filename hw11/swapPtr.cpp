#include <iostream>
#include <new>
using namespace std;

int main()
{
  int *p0 = new int;
  *p0 = 5;
  cout << "*p0==" << *p0 << endl;
 
  int *p1 = new int[3];
  p1[0] = 11;
  p1[1] = 12;
  p1[2] = 13;
  cout << "p1[1]==" << p1[1] << endl;
 
  delete p0;
  delete [] p1;
}