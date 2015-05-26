#include "Shape.h"
#ifndef _RECTANGLE_
#define _RECTANGLE_
#include <iostream>
#include <GL/glut.h>
using namespace std;

class Rectangle: public Shape
{
	int width;
	int height;
public:
	Rectangle();
	Rectangle(Point2 p, int w, int h);
	Rectangle(istream &is);

	//no deconstructor

	void display();
	void update(int x, int y);
	void draw();
	bool containsPoint(int x, int y);
	bool isRectangle();
};
#endif // _RECTANGLE_