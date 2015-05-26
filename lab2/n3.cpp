#include <iostream>
using namespace std;

main()
{
	int x = 100;
	while(x > 0)
	{
		if(x%2 == 0)
		{
			cout << x << endl;
		}
		x--;
	}

	return 0;
}