#include<iostream>
using namespace std;


void printHalf(int par1, int par2)
{
	cout << par1 << " ";
}
int main()
{
  signed short val1;
  signed short val2;
  while ( cin >> val1, cin >> val2 ) {
    printHalf(val1,val2);
  }
  cout << endl;
  return 0;
}