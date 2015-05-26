#include <iostream>
using namespace std;

#include "Dog.h"

int main()
{
	Dog mydog("Fido", 3);

	cout << "Hello, World!" << endl;
	cout << "My dog is named " << mydog.get_name() << "and it is " << mydog.get_age() << " years old." << endl;

	return 0;
}