#include<iostream>
using namespace std;

int main()
{
  signed short val1;
  int x = 100000;
  while ( cin >> val1 && x <= 100000) 
  {
  		x++;
  }
  while (cin >> val1)
  {
  		cout << val1 << " ";
  }
  cout << endl;
  return 0;
}