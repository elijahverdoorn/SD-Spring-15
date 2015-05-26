#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	int age, ssn;
	Person(int a, int s) {age = a; ssn = s;};
	Person() {};
	Person operator+ (const Person& par1)
	{
		Person temp;
		temp.age = age + par1.age;
		temp.ssn = ssn + par1.ssn;
		return temp;
	}
	Person operator- (const Person& par1)
	{
		Person temp;
		temp.age = age - par1.age;
		temp.ssn = ssn - par1.ssn;
		return temp;
	}
	Person operator++ (int)
	{
		Person temp;
		temp.age = age++;
		temp.ssn = ssn++;
		return temp;
	}
};

main()
{
	Person x (1,2);
	Person y (1,2);
	Person z = x + y;
	cout << z.age << " " << z.ssn << endl;
	z = x - y;
	cout << z.age << " " << z.ssn << endl;
	z++;
	cout << z.age << " " << z.ssn << endl;

}