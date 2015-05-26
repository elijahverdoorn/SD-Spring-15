#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DVD.h"

int main()
{
	DVD d1(1, "test title", "test director");
	DVD d2;
	DVD d3(d1);

	d1.display();
	d2.display();
	d3.display();

	cout << endl;

	d1.setTitle("title2");
	d2.setDirector("director2");
	d3++;

	d1.display();
	d2.display();
	d3.display();

	return 0;
}