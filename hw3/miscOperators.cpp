#include <iostream>
using namespace std;
#include "/home/users/cs251/binary.h"

main()
{
	int x, z, w = 2;
	double y = 3.14;
	x = int(y);
	cout << y << " becomes " << x << endl;
	z = x | w;
	cout << "z = " << binary(z) << endl;
	cout << "the size of x is " << sizeof(x) << " bytes." << endl;
}