#include <iostream>
using namespace std;

main()
{
	int x = 100;
	do
	{
		if(x%25 == 0)
		{
			cout << x << endl;
		}
		x++;
	}
	while(x <=600);

	return 0;
}