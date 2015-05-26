#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Pixel {
	unsigned char red, green, blue;
};

class Image
{
	int width, height, depth;
	Pixel **data;
public:
	Image(int w, int h, int d); // explicit constructor
	Image(char* filename); // file-based constructor

	~Image(); // destructor

	int getWidth();
	int getHeight();
	int getDepth();
	void print(); // defined elsewhere
};

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
};

int main()
{
	Image img1("testPic.ppm");

	img1.print();
	return 0;
}