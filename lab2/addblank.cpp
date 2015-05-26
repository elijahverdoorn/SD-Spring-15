#include<iostream>
using namespace std;

int main()
{
  signed short val1;
  int x = 0;
  while (x <= 100000) 
  {
  		cout << 1 << " ";
      x++;
  }
  while (cin >> val1)
  {
  		cout << val1 << " ";
  }
  cout << endl;
  return 0;
}