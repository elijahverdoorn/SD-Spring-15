#include<iostream>
using namespace std;

int main()
{
  signed short val;
  while ( cin >> val ) {
    val *= 5;
    cout << val << " ";
  }
  cout << endl;
  return 0;
}