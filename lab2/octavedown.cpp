#include<iostream>
using namespace std;


void printTwice(int par1, int par2)
{
	cout << par1 << " " << par2 << " " << par1 << " " << par2<< " ";
}
int main()
{
  signed short val1;
  signed short val2;
  while ( cin >> val1, cin >> val2 ) {
    printTwice(val1,val2);
  }
  cout << endl;
  return 0;
}