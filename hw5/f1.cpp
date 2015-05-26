#include<iostream>
using namespace std;

void f1(int x)
{
  if ( 0 != x ) {
    cout << x << endl;
    f1(x - 1);
  }
}

int main()
{
  f1(10);
  return 0;
}