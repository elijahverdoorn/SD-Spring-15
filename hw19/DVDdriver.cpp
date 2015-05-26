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

	cout << "Test of assignment operator:" << endl;
	DVD d4(d1);
	d4 = d3;
	d4.display(); cout << endl; // [3.  Gandhi/Richard Attenborough]
	(d4 = d2).setTitle("Persona"); 
	d4.display(); cout << endl; // [2.  Persona/Ingmar Bergman]

	return 0;
}