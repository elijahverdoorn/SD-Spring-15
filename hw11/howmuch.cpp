#include <iostream>
#include <new>
using namespace std;

main()
{
	int *i;
	i = new int[9999999900];
	cout << "done" << endl;
	return 0;
}