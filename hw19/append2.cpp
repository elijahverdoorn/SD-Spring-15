#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char* append2(char *par1, const char *par2)
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
	char * str;
	cout << "*" << append2("Hello ", "world") << "*" << endl;
	// cout:   *Hello world*
	return 0;
}