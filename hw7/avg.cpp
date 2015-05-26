#include <iostream>
using namespace std;

main()
{
	int total = 0;
	int count = 0;
	int current = 0;
	while (cin >> current)
	{
		count++;
		total += current;
		cout << total << endl;
	}
	cout << "end" << endl;
	double out = (double) total/count;
	cout << out << endl;
	return 0;
}