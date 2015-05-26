#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Image.h"

Image::Image(int w, int h, int d)
{
	if ((w <= 0) || (h <= 0) || (d <= 0))
	{
		cout << "Image width or height is below expected value. Quitting." << endl;
		return;
	}else{
		width = w;
		height = h;
		depth = d;
	}
	data = new Pixel*[height];
	for (int i = 0; i < height; ++i)
	{
		data [i] = new Pixel [width];
	}
}

Image::Image(char* filename)
{
	ifstream file(filename); // remember that this string must be an array of chars, not a string object
	string header;
	file >> header;
	if (header != "P6")
	{
		cout << "image format not correct for file based input. Quitting." << endl;
		return;
	}
	file >> width;
	file >> height;
	file >> depth; // should have dealt with the entire header at this point

	// set up memory
	data = new Pixel*[height];
	for (int i = 0; i < height; ++i)
	{
		data [i] = new Pixel [width];
	}
	// read in all the values
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			file >> data[i][j].red;
			file >> data[i][j].green;
			file >> data[i][j].blue;
		}
	}
	file.close();
	}

Image::Image(Image &other)
{

	if ((other.getWidth() <= 0) || (other.getHeight <= 0) || (other.getDepth() <= 0))
	{
		cout << "Image width or height is below expected value. Quitting." << endl;
		return;
	}else{
		width = other.getWidth();
		height = other.getHeight();
		depth = other.getDepth();
	}
	data = new Pixel*[height];
	for (int i = 0; i < height; ++i)
	{
		data [i] = new Pixel [width];
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			data[i][j].red = other[i][j].red;
			data[i][j].green = other[i][j].green;
			data[i][j].blue = other[i][j].blue;
		}
	}
}

Image::~Image()
{
	delete data; //TODO: update this deconstructor
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

int Image::getDepth()
{
	return depth;
}

void Image::print() // construct a .ppm file
{
	cout << "P6" << endl;
	cout << width << " " << height << endl;
	cout << depth << endl;
	for (int i = 0; i < width; ++i)
	{
		cout.write((char *) data[i], width*sizeof(Pixel));	
	}
}

void Image::zeroRed()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			image[i][j].red = 0;
		}
	}
}

void Image::greyScale()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			double average = image[i][j].red + image[i][j].green + image[i][j].blue;
			average /= 3;
			image[i][j].red = image[i][j].green = image[i][j].blue = average;
		}
	}
}

void Image::horizSqueeze()
{
	Pixel **data2; 
	bool alternator = false;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if(alternator)
			{
				image[i][j].red
				image[i][j].green
				image[i][j].blue
				alternator = false;
			}else{
				x
				x
				x
				alternator = true;
			}
		}
	}
}

void Image::addBorder()
{

}