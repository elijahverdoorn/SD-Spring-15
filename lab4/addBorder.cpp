#include <iostream>
#include <new>
using namespace std;

int stringLength(const char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return i;
}

bool getFormat()
{
	bool correctFormat = false;
	char p;
	cin >> p;
//	cout << p << endl;
	if (p =! 'P')
	{
		cout << "not the right format" << endl;
		correctFormat = false;
		return correctFormat;
	}
	int x;
	cin >> x;
//	cout << x << endl;
	switch (x)
	{
		case 3:
			cout << "already in the ascii format" << endl;
			correctFormat = false;
			break;
		case 6:
			correctFormat = true;
			break;
		default:
			correctFormat = false;
			break;
	}
	return correctFormat;
}

bool getColors()
{
	bool correctColor = false;
	int x;
	cin >> x;
	if (x == 255)
	{
		correctColor = true;
	}
	return correctColor;
}

main()
{
	if (!getFormat())
	{
		cout << "error" << endl;
		return 1;
	}
	int height, width;
	cin >> width;
//	cout << "width" << width << endl;
	cin >> height;
//	cout << "height" << height << endl; 
	if (!getColors())
	{
		cout << "error" << endl;
		return 1;
	}
	int dataPoints = ((height + 6) * (width + 6) * 3) + 36;
//	cout << dataPoints << endl;
	unsigned char *data = new unsigned char[dataPoints];
	for (int i = 0; i < dataPoints; ++i)
	{
		cin >> data[i];

	}
	//end of normal same.cpp
	//start of addBorder.cpp
	unsigned char *newData = new unsigned char[dataPoints / 2];
	int count = 0;

	// draw top border
	int i = 0;
	while (i < ((width + 6) * 3))
	{
		newData[i] = 0;
		i++;
	}
	//fill in the image
	for (int i = 0; i < dataPoints; ++i)
	{
		if (i % width == 0) // draw the border on the left
		{
			newData[i] = 0;
			i++;
			newData[i] = 0;
			i++;
			newData[i] = 0;
			i++;
		}
		if (i % (width + 3) == 0) // draw the right border
		{
			newData[i] = 0;
			i++;
			newData[i] = 0;
			i++;
			newData[i] = 0;
			i++;
		}
		newData[count] = data[i];
		count++;
	}
	while (i < dataPoints)
	{
		newData[i] = 0;
		i++;
	}
	for (int i = 0; i < dataPoints; ++i)
	{
		cout << newData[i] << " ";
	}
	return 0; 
}
// TODO: use the width and height variables to define the start and end of each line