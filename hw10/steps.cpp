#include <iostream>
using namespace std;

int func(int arg)
{
	arg = arg + 2;
	return arg;
}

int funcp(int *argp)
{
	*argp = (*argp) + 2;
	return *argp;
}

int main ()
{
	int i = 17;
	double f = -4.2; // step 1

	int * ip = &i;
	double * fp = &f; // step 2

	cout << "Initial values: " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << endl; //step 3

	i *= 3;
	*fp *= 1.5;
	cout << "After multiplication: " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << endl; // step 4

	double f2 = 2.5;
	fp = &f2;
	i *= *ip;
	cout << "After 2nd multiplication: " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << " f2=" << f2 << endl; // step 5

	cout << "func(i) " << func(i) << endl;
	cout << "After func(i): " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << " f2=" << f2 << endl; //step 6

	cout << "func(*ip) " << func(*ip) << endl;
	cout << "After func(*ip): " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << " f2=" << f2 << endl; //step 7

	cout << "funcp(ip) " << funcp(ip) << endl;
	cout << "After funcp(ip): " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << " f2=" << f2 << endl; //step 8

	cout << "funcp(&i): " << funcp(&i) << endl;
	cout << "After funcp(&i): " << "i=" << i << " *ip=" << *ip << " f=" << f << " *fp=" << *fp << " f2=" << f2 << endl; // step 9

}