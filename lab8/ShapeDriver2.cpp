#include <iostream>
#include <fstream>
using namespace std;
#include "ColorPoint2.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

main()
{
    ifstream g ("shapes.txt");
	int numShapes;
	g >> numShapes;
	Shape **shapeArray = new Shape* [numShapes];
	for (int i = 0; i < numShapes; ++i)
	{
		char *charArr = new char[64];
		g >> charArr;
		switch (charArr[0])
		{
			case 'r':
				shapeArray[i] = new Rectangle(g);
				break;
			case 'R':
				shapeArray[i] = new Rectangle(g);
				break;
			case 'c':
				shapeArray[i] = new Circle(g);
				break;
			case 'C':
				shapeArray[i] = new Circle(g);
				break;		
			default:
				cout << "lines must start with either Circle or Rectangle" << endl;
				break;
		}
		delete charArr;
	}
	for (int i = 0; i < numShapes; ++i)
	{
		shapeArray[i]->display();
		cout << endl;
	}
}