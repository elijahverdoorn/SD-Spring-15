#include "Shape.h"
#ifndef _CIRCLE_
#define _CIRCLE_
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

class Circle: public Shape
{
	int radius;
public:
	Circle();
	Circle(Point2 p, int r);
	Circle(istream &is);

	// no deconstructor

	void display();
	void update(int x, int y);
	void draw();
	bool containsPoint(int x, int y);
	bool isRectangle();
};
#endif // _CIRCLE_