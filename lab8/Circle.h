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

	void draw();
};
#endif // _CIRCLE_