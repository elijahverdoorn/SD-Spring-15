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
	Person foo (10.0);
	Person bar = 20.0;
	Person *pointer = &foo;
	foo.weight = (*pointer).height;	
}