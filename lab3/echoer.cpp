#include <iostream>
using namespace std;

const int size = 4;
const int newSize = size + 2;
signed short newVal[newSize];

void addecho(signed short val[])
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

  addecho(val);  // modify the new array elements

  for (int i = 0; i < size; ++i) // add the arrays together
  {
    newVal[i] += val[i];
  }

  cout.write( (char *)newVal, 2*size ); // write the data back out
  return 0;
}