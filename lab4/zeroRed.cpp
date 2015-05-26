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
	int dataPoints = height * width * 3;
//	cout << dataPoints << endl;
	unsigned char *data = new unsigned char[dataPoints];
	for (int i = 0; i < dataPoints; ++i)
	{
		cin >> data[i];

	}
	//end of normal same.cpp
	//start of zeroRed.cpp
	for (int i = 0; i < dataPoints; ++i)
	{
		if (i % 3 == 0)
		{
			data[i] = 0;
		}
		cout << data[i] << " ";
	}
	return 0;
}