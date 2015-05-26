#include <iostream>
using namespace std;

struct Point2
{
	int x, y;
public:
	void display()
	{
		cout << x << " " << y << endl;
	}
};

main()
{
	Point2 p;
	p.x = 1;
	p.y = 2;
	p.display();
