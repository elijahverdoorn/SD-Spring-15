#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void append(char *par1, const char *par2)
{
	int i; // count
	for (i = 0; par1[i] != NULL; i++) {}
	int x;
	for (i = 0; par2[x] != NULL; x++) {}
	char *returner = new char[i + x];
	for (i = 0; par1[i] != NULL; ++i)
	{
		returner[i] = par1[i];
	}
	int count = 0;
	for (int x = i; par2[x] != NULL; x++)
	{
		returner[x] = par2 [count];
		count++;
	}
	par1 = returner;
}

int main()
{
	char a[20] = "Hello";
	char b[10] = "world!";
	cout << "Initially, a is " << a << " and b is " << b << endl;
	append(a, b);
	cout << "After calling append(a,b), a is " << a << "and b is" << b << endl;
	// a should be Hello world! and b should be unchanged
	return 0;
}