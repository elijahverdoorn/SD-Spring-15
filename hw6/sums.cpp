#include <iostream>
using namespace std;

main()
{
	int sum, x, largest = 0;
	int a, b, c, d, e;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	while (cin >> x)
	{
		e = d;
		d = c;
		c = b;
		b = a;
		a = x;
		sum = a + b + c + d + e;
		if(sum > largest)
		{
			largest = sum;
		}
		cout << sum << endl;
	}
	cout << "the largest sum is " << largest << endl;
	return 0;
}