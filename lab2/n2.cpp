#include <iostream>
using namespace std;

main()
{
	int x = 1;
	while(x <= 100)
	{
		if(x%2 == 0)
		{
			cout << x << endl;
		}
		x++;
	}

	return 0;
}