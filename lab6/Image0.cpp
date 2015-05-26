#include <iostream>
#include <string>
using namespace std;

class Image0
{
public:
	int width, height;
	Image0(int w, int h) // constructor
	{
		if ((w <= 0) || (h <= 0))
		{
			cout << "Image width or height is below expected value. Quitting." << endl;
			return;
		}else{
			width = w;
			height = h;
		}
	};

	int getWidth()
	{
		return width;
	};

	int getHeight()
	{
		return height;
	};
};

int main()
{
	Image0 img1 (10, 10);
	Image0 img2 (50, 50);

	cout << img1.getWidth() << " " << img1.getHeight() << endl;
	cout << img2.getWidth() << " " << img2.getHeight() << endl;
	return 0;
}