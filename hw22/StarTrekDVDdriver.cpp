#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DVD.h"
#include "DVD.cpp"
#include "StarTrekDVD.h"
#include "StarTrekDVD.cpp"

int main()
{
	StarTrekDVD d1(1, "test title", "test director", 2, "Elijah Verdoorn");
	StarTrekDVD d2;
	StarTrekDVD d3(d1);

	d1.display();
	d2.display();
	d3.display();

	cout << endl;

	d1.setTitle("title2");
	d2.setDirector("director2");
	d1.setCaptain("captain2");
	d3++;

	d1.display();
	d2.display();
	d3.display();

	cout << "Test of assignment operator:" << endl;
	StarTrekDVD d4(d1);
	d4 = d3;
	d4.display(); cout << endl; // [3.  Gandhi/Richard Attenborough]
	(d4 = d2).setTitle("Persona"); 
	d4.display(); cout << endl; // [2.  Persona/Ingmar Bergman]

	return 0;
}