#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	int age, ssn;
	static int personNumber;
	Person(int a, int s) {age = a; ssn = s; personNumber++;};
	Person() {personNumber++;};
	Person operator+ (const Person& par1)
	{
		Person temp;
		temp.age = this->age + par1.age;
		temp.ssn = this->ssn + par1.ssn;
		return temp;
	}
	Person operator- (const Person& par1)
	{
		Person temp;
		temp.age = this->age - par1.age;
		temp.ssn = this->ssn - par1.ssn;
		return temp;
	}
	Person operator++ (int)
	{
		Person temp;
		temp.age = this->age++;
		temp.ssn = this->ssn++;
		return temp;
	}
};

int Person::personNumber = 0;

main()
{
	Person x (1,2);
	cout << "Person number " << Person::personNumber << " created." << endl;
	Person y (1,2);
	cout << "Person number " << Person::personNumber << " created." << endl;
	Person z = x + y;
	cout << "Person number " << Person::personNumber << " created." << endl;
	cout << z.age << " " << z.ssn << endl;
	z = x - y;
	cout << z.age << " " << z.ssn << endl;
	z++;
	cout << z.age << " " << z.ssn << endl;

}