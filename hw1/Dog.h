#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>
using std::ostream;

class Dog
{
protected:
	char *name;
	int age;

public:
	Dog(const char *n, int a)
	{
		age = a; 
		name = helper(n);
	}
	Dog()
	{
		age = 0;
		name = helper("");
	}
	Dog(const Dog &dog)
	{
		age = dog.age;
		name = helper(dog.name);
	}

	~Dog();

	Dog &operator = (const Dog &dog);
	void display(ostream &ostr) const;

	const char *get_name(void) const {return name;}
	int get_age(void) const {return age;}

	void set_name(const char *new_name);
	void birthday(void) {age++;}

protected:
	char *helper(const char *s);
};

#endif