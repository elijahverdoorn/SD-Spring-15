#include <iostream>
using namespace std;

class Person{
	int age, weight, height;
	public:
		Person (int, int, int);
		int get_age() {return age;}
		int get_weight() {return weight;}
		int get_height() {return height;}
};

Person::Person (int a, int w, int h)
	{
		age = a;
		weight = w;
		height = h;
	}

main()
{
	Person pep1 (1, 2, 3);
	cout << pep1.get_age() <<  pep1.get_height() << pep1.get_weight() << endl;
}