#include <iostream>
using namespace std;

main()
{
	int x = 1, y;
	y = 1;
	while(x <= 10)
	{
		y *= x;
		cout << y << endl;
		x++; 
	}

	return 0;
}