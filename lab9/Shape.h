#include <GL/glut.h>
#include "ColorPoint2.h"
#ifndef _SHAPE_
#define _SHAPE_

class Shape
{
	Color color;
	Point2 position;
public:
	Shape();
	Shape(Point2 p);
	Shape(istream &is);

	// no deconstructor required

	Color getColor();
	Point2 getPosition();
	void setColor(Color c);
	void setPosition(int x, int y);
	void display();
	double distance(int x, int y, Point2 p);
	void sendGLColor();

	virtual void draw() = 0;
	virtual void update(int x, int y) = 0;
	virtual bool containsPoint(int x, int y) = 0;
	virtual bool isRectangle() = 0;
};

#endif // _SHAPE_