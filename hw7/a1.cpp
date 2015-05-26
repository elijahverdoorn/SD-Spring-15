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
	int a[20];
	for (int k = 0; k <= 19; k++)
	{
		a[k] = k;
	}
	printarray(a, 20);
}