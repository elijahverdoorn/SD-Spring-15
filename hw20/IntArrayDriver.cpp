#include <iostream>
using namespace std;
#include"IntArray.h"
 
int main()
{
	IntArray arr1, arr2(3);
	cout << "arr1 has size " << arr1.getSize() << endl;
	arr1.display(); cout << endl;

	arr2[1] = 24;
	arr2.display(); cout << endl;
	arr2[389]; // should display an error, but not crash

	IntArray arr3(arr2);
	arr3.display();
}