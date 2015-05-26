#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ofstream x("writeread.txt");
	string y = "Hello";

	x << y << endl;
	x.close();

	ifstream u("writeread.txt");
	string k;
	u >> k;
	cout << k << endl;
	u.close();

	return 0;
	
}