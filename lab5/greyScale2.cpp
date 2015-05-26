#include <iostream>
using namespace std;
#include <string>

struct Pixel {
	unsigned char red, green, blue;
};

bool getFormat() // deal with the "P3" or "P6", ensure that the correct format is read
{
	bool correctFormat = false;
	char p;
	cin >> p;
	if (p =! 'P')
	{
		cout << "not the right format" << endl;
		correctFormat = false;
		return correctFormat;
	}
	int x;
	cin >> x;
	switch (x)
	{
		case 3:
			cout << "Image is in ascii format" << endl;
			correctFormat = false;
			break;
		case 6:
			cout << "Image is in encoded format" << endl;
			correctFormat = true;
			break;
		default:
			cout << "Image format not known" << endl;
			correctFormat = false;
			break;
	}
	return correctFormat;
}

main()
{
	if (!getFormat())
	{
		cout << "Error!" << endl;
		return 0;
	}
	int height, width, colorRange;
	cin >> width;
	cin >> height;
	cin >> colorRange; // file is in the correct format and we know the size, and the color range

	// set up memory
	Pixel **image = new Pixel*[height]; 
	for (int i = 0; i < height; ++i)
	{
		image [i] = new Pixel [width];
	}
	//for some reason there is a random '10' that appears at the start of my file. this is how I am getting rid of it.
	unsigned char x = cin.get();
	// read in all the values
	for (int i = 0; i < height; ++i)
	{
		cin.read((char *) image[i], width*sizeof(Pixel));
	}

	// set the pixels to greyscale
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			double average = image[i][j].red + image[i][j].green + image[i][j].blue;
			average /= 3;
			image[i][j].red = image[i][j].green = image[i][j].blue = average;
		}
	}






	// cout the values
	for (int i = 0; i < width; ++i)
	{
		cout.write((char *) image[i], width*sizeof(Pixel));
	}

	// delete the memory locations
	for (int i = 0; i < height; ++i)
	{
		delete[] image [i];
	}
	delete[] image;

	return 0;
}