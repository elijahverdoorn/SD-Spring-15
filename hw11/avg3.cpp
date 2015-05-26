#include <iostream>
#include <new>
using namespace std;

double averageOf(float dat[], int nelts, float &minVal)
{
  double result = 0;
  minVal = dat[0];
  for(int i = 0; i < nelts; ++i) {
    if ( dat[i] < minVal ) minVal = dat[i];
    result += dat[i];
  }
  result /= nelts;
  return result;
}

main()
{
	int arraySize;
	float *array;
	cin >> arraySize;
	array = new (nothrow) float[arraySize];
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
	float x;
	cout << averageOf(array, arraySize, x) << endl;
	return 0;
}