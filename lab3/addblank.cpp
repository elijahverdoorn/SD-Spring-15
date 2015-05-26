#include <iostream>
using namespace std;

const int size = 4;
const int newSize = size + (size / 2);
signed short newVal[newSize];

void addsilence(signed short val[])
{
  for( int i = (size / 2); i < newSize; ++i )
  {
  	newVal[i] = val[i];
  }
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  for (int i = 0; i < newSize; ++i) // set values in the array to 0
  {
  	newVal[i] = 0;
  }
  addsilence(val);  // modify the array elements

  cout.write( (char *)newVal, 2*size ); // write the data back out
  return 0;
}