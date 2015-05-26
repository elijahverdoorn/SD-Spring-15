#include <iostream>
using namespace std;

main()
{
	int x  = 1;
	int y = 2;
	y += x;
	cout << "x is 1, y is 3. 3 - 1 = 2, so 2 should be printed " << endl;
	cout << y - x << endl;
	x++;
	cout << "incremnted x, now it equals 2, so 2 should be printed again. " << endl;
	cout << x << endl;
}