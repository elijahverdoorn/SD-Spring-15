#ifndef _IMAGE_
#define _IMAGE_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pixel {
	unsigned char red, green, blue;
};

class Image
{
	int width, height, depth;
	Pixel **data;
public: // defined in Image.cpp
	Image(int w, int h, int d); // explicit constructor
	Image(char* filename); // file-based constructor

	~Image(); // destructor

	int getWidth();
	int getHeight();
	int getDepth();
	void print(); 
	void zeroRed();
	void greyScale();
	void horizSqueeze();
	void addBorder(int par);
};

#endif // _IMAGE_