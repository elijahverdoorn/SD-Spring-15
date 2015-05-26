#include <iostream>
using namespace std;

main()
{
	int x = 1;
	do
	{
		if(x%2 == 0)
		{
			cout << x << endl;
		}
		x++;
	}
	while(x <= 100);
	return 0;
}