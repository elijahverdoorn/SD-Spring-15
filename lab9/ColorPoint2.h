#ifndef _POINT2_
#define _POINT2_
#include <iostream>
using namespace std;

struct Point2
{
	int x, y;
public:
	void display()
	{
		cout << x << " " << y;
	}
};

#endif // _POINT2_

#ifndef _COLOR_
#define _COLOR_
#include <iostream>
using namespace std;

struct Color
{
	int red, green, blue;
public:
	Color(){}
	Color(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
	}
	void display()
	{
		cout << red << " " << green << " " << blue;
	}
};
#endif // _COLOR_