#include <iostream>
using namespace std;

void printarray (int arg[], int length) {
	for (int n=0; n<length; n++)
	{
		cout << arg[n] << " ";
	}
	cout << "\n";
}

main()
{
	int a[21];
	for (int k = 0; k = 20; k++)
	{
		a[k] = 600 - (25 * k);
	}
	printarray(a, 21);
}