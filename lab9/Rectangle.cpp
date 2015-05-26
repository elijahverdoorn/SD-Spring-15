#include <iostream>
#include <GL/glut.h>
using namespace std;
#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle() : Shape()
{
	width = 50;
	height = 60;
}

Rectangle::Rectangle(Point2 p, int w, int h) : Shape(p)
{
	width = w;
	height = h;
}

Rectangle::Rectangle(istream &is) : Shape(is)
{
	is >> width;
	is >> height;
}

void Rectangle::display()
{
	cout << "Rectangle ";
	Shape::display();
	cout << width << height << endl;
}

void Rectangle::draw()
{
	sendGLColor();
	Point2 point = getPosition();
	double x0 = min(point.x, point.x + width);
	double x1 = max(point.x, point.x + width);
	double y0 = min(point.y, point.y + height);
	double y1 = max(point.y, point.y + height);
	glBegin(GL_QUADS);
		glVertex2d(x0, y0);
		glVertex2d(x1, y0);
		glVertex2d(x1, y1);
		glVertex2d(x0, y1);
	glEnd();
}

void Rectangle::update(int x, int y)
{
	width = x - getPosition().x;
	height = x - getPosition().y;
}

bool Rectangle::containsPoint(int x, int y)
{
	Point2 point = getPosition();
	double x0 = min(point.x, point.x + width);
	double x1 = max(point.x, point.x + width);
	double y0 = min(point.y, point.y + height);
	double y1 = max(point.y, point.y + height);
	if ((x0 < x) && (x < x1) && (y0 < y) && (y < y1))
	{
		return true;
	}else{
		return false;
	}
}
bool Rectangle::isRectangle()
{
	return true;
}