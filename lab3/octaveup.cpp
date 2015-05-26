#include <iostream>
using namespace std;

const int size = 4;
const int halfSize = size / 2;
signed short halfVal[halfSize];

void octaveup(signed short val[])
{
  int counter = 0;
  for( int i = 0; i < size; ++i )
  {
  	halfVal[i] = val[counter];
  	counter++;
  	counter++;
  }
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  for (int i = 0; i < halfSize; ++i)
  {
  	halfVal[i] = 0;
  }

  octaveup(val);  // modify the array elements

  cout.write( (char *)halfVal, size ); // write the data back out
  return 0;
}