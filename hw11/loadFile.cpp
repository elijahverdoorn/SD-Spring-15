#include <iostream>
#include <new>
using namespace std;

main()
{
	int arraySize, *array;
	cin >> arraySize;
	array = new int[arraySize];
	if (array == '\0')
	{
		cout << "Error: no data" << endl;
//		return 0;
	}else{
		for (int i = 0; i <= arraySize; i++)
		{
			cin >> array[i];
		}
	}
	return 0;
}