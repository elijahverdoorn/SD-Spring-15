#include <iostream>
using namespace std;

struct Color
{
	int red, green, blue;
public:
	void display()
	{
		cout << red << " " << green << " " << blue << endl;
	}
};

main()
{
	Color x;
	x.red = 1;
	x.green = 2;
	x.blue = 3;
	x.display();
}