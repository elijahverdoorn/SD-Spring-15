#include <cstring>
#include <iostream>
using namespace std;

#include "Dog.h"

char * Dog::helper(const char *str)
{
	char *copy = new char[strlen(str) + 1];
	strcpy(copy, str);
	return copy;
}

Dog::~Dog()
{
	if (name != 0)
		delete [] name;
	name = 0;
}

Dog &Dog::operator=(const Dog &dog)
{
	delete [] name;
	name = helper(dog.name);
	age = dog.age;
	return *this;
}

void Dog::display(ostream &ostr) const
{
	ostr << name << "(" << age << ")";
}

void Dog::set_name(const char *new_name)
{
	delete [] name;
	name = helper(new_name);
}