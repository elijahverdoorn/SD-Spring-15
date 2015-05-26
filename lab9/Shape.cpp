#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
#include "Shape.h"
#include "ColorPoint2.h"

double Shape::distance(int x, int y, Point2 p)
{
	int a, b;
	a = x - p.x;
	b = y - p.y;
	double returner;
	returner = sqrt(pow(a,2) + pow(b,2));
	return returner;
}

Shape::Shape()
{
	color.red = color.green = color.blue = 100;
	setPosition(100,100);
}

Shape::Shape(Point2 p)
{
	color.red = color.green = color.blue = 100;
	position.x = p.x;
	position.y = p.y;
}

Shape::Shape(istream &is)
{
	is >> color.red;
	is >> color.green;
	is >> color.blue;
	int x;
	is >> x;
	int y;
	is >> y;
	setPosition(x,y);
}

// no deconstructor required

Color Shape::getColor()
{
	return color;
}

Point2 Shape::getPosition()
{
	return position;
}

void Shape::setColor(Color c)
{
	color.red = c.red;
	color.green = c.green;
	color.blue = c.blue;
}

void Shape::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Shape::display()
{
	color.display();
	position.display();
}


void Shape::sendGLColor()
{
	glColor3f(color.red/255., color.green/255., color.blue/255.);
}