#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	ifstream g("in.txt");

	int i, j;
	g >> i >> j;
	g.close();

	cout << "i is " << i << " and j is " << j << endl;
}