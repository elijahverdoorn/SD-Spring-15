#include <iostream>
using namespace std;

const int size = 10;
const int smallSize = (size - 2); // 8
signed short newVal[smallSize];

void trunc(signed short val[])
{
  for(int i = (size - smallSize); i < size; i++)
  {
  	newVal[i] = val[i];
  }
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  trunc(val);  // modify the array elements

  cout.write( (char *)newVal, 2*smallSize); // write the data back out
  return 0;
}