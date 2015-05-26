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
	printarray(a, 20);
}