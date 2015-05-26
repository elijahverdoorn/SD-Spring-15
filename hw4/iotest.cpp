#include <iostream>
using namespace std;

main()
{
	int size, num;
	double average;
	cout << "enter your shoesize" << endl;
	cin >> size;
	cout << "enter your favorite number" << endl;
	cin >> num;
	average = size + num;
	average /= 2;
	cout << "the average is " << average << endl;
	return 0;
}