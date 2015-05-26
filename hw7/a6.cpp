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
	int a[10];
	a[0] = 0;
	a[1] = 1;
	for (int k = 2; k <= 9; k++)
	{
		a[k] = a[k-1] + a[k-2];
	}
	printarray(a, 10);
}