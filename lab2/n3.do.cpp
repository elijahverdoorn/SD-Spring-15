#include <iostream>
using namespace std;

main()
{
	int x = 100;
	do
	{
		if(x%2 == 0)
		{
			cout << x << endl;
		}
		x--;
	}
	while(x > 0);

	return 0;
}