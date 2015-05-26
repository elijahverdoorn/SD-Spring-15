#include <iostream>
using namespace std;

main()
{
	int x = 100;
	while(x <=600)
	{
		if(x%25 == 0)
		{
			cout << x << endl;
		}
		x++;
	}

	return 0;
}