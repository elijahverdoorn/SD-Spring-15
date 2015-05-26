// bus.cpp, bus2.cpp, bus3.cpp all in one file
#include <iostream>
using namespace std;

struct business{
	long int number;
	char *name, location [10];
	float rating;
} bus1, bus2, bus3, bus4;

void printBusiness(business par)
{
	cout << par.name << " (" << par.rating << ")" << endl;
	cout << "Phone Number: " << par.number << endl;
	cout << "Location: " << par.location << '\n' << endl;
	return;
}

void setBusiness(business &par, int num, char name[], char address[10], float rate)
{
	par.number = num;
	par.name = name;
	for (int i = 0; i < 10; ++i)
	{
		par.location[i] = address[i];
	}
	par.rating = rate;
}

main()
{
	bus1.number = 1234567;
	char tempName[] = "Business 1";
	bus1.name = tempName;
	char arr[] = "1234 Main";
	for (int x = 0; x < 10; x++)
	{
		bus1.location[x] = arr[x];
	}
	bus1.rating = 4.3;
	bus2.number = 7654321;
	char tempName2[] = "Business 2";
	bus2.name = tempName2;
	char arr2[] = "400 Orange";
	for (int x = 0; x < 10; x++)
	{
		bus2.location[x] = arr2[x];
	}
	bus2.rating = 3.1;
	printBusiness(bus1);
	printBusiness(bus2);
	setBusiness(bus3, 555555, "Business 3", "401 Orange", 2.2);
	printBusiness(bus3);
	setBusiness(bus4, 999999, "Business 4", "5673 Maple", 1.6);
	printBusiness(bus4);
}