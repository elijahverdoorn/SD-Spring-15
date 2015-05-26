#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;
#include "Circle.h"
#include "Shape.h"

Circle::Circle() : Shape()
{
	radius = 15;
}

Circle::Circle(Point2 p, int r) : Shape(p)
{
	radius = r;
}

Circle::Circle(istream &is) : Shape(is)
{
	is >> radius;
}

void Circle::display()
{
	cout << "Circle ";
	Shape::display();
	cout << radius << endl;
}

void Circle::draw()
{
	sendGLColor();
	Point2 point = getPosition();
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(point.x, point.y);
    for ( int i = 0; i < NUM_DIVS; ++i )
      glVertex2d(point.x + radius*cos(i*2*M_PI/(NUM_DIVS-1)),
                 point.y + radius*sin(i*2*M_PI/(NUM_DIVS-1)));
  glEnd();
}

void Circle::update(int x, int y)
{
	Point2 p = getPosition();
	radius = (int) this->distance(x,y,p);
}
bool Circle::containsPoint(int x, int y)
{
	double dist = distance(x,y,getPosition());
	if (dist < radius)
	{
		return true;
	}else{
		return false;
	}
}
bool Circle::isRectangle()
{
	return false;
}