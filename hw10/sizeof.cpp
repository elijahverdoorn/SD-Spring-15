#include <iostream>
using namespace std;

main()
{
	short s;
	int i;
	double d;
	s = sizeof(s);
	i = sizeof(i);
	d = sizeof(d);
	cout << "s: " << s << " i: " << i << " d: " << d << endl;
	short *sp;
	int *ip;
	double *dp;
	s = sizeof(sp);
	i = sizeof(ip);
	d = sizeof(dp);
	cout << "s: " << s << " i: " << i << " d: " << d << endl;
}