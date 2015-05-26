#include <iostream>
using namespace std;

void f1(int& x)
{
	x++;
}

main()
{
	int x = 2;
	cout << x << endl;
	f1(x);
	cout << x << endl;
	return 0;
}