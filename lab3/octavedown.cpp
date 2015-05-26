#include <iostream>
using namespace std;

const int size = 4;
const int doubleSize = size * 2;
signed short doubleVal[doubleSize];

void ocatvedown(signed short val[])
{
  int counter = 0;
  for( int i = 0; i < size; ++i )
  {
  	doubleVal[counter] = val[i];
  	counter++;
  	doubleVal[counter] = val[i];
  	counter++;
  }
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  for (int i = 0; i < doubleSize; ++i)
  {
  	doubleVal[i] = 0;
  }

  ocatvedown(val);  // modify the array elements

  cout.write( (char *)doubleVal, doubleSize ); // write the data back out
  return 0;
}