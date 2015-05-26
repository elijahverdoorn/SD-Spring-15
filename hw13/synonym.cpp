#include <iostream>
using namespace std;

main()
{
	typedef int number;
	number w = 1;
	enum color {black, white};
	color theColor = white;
	cout << theColor << " " << w << endl;
}