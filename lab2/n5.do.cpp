#include <iostream>
using namespace std;

main()
{
	int x = 1, y;
	y = 1;
	do
	{
		y *= x;
		cout << y << endl;
		x++; 
	}
	while(x <= 10);

	return 0;
}