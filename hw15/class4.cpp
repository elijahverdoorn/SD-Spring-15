#include <iostream>
using namespace std;

class Person {
public:
		double height;
		double weight;

		Person (double h, double w){height = h; weight = w;}
		Person (double h) {height = h;}
};
main()
{
	Person a(5.3);
}