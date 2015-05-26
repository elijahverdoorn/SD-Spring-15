/* my second program in C++
with more comments */
#include <iostream>
using namespace std;

int x = 0;
int main ()
{
	x++;
	cout << "Hello World! " << endl;
	// prints Hello World!
	cout << "I'm a C++ program" << endl;
	// prints I'm a C++ program
	if (x == 5)
	{
		return 0;
	}
	else
	{
		main();
	}
}