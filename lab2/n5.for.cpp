#include <iostream>
using namespace std;

main()
{
	int y = 1;
	for(int x = 1; x <= 10; x++)
	{
		y *= x;
		cout << y << endl; 
	}

	return 0;
}