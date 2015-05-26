#include <iostream>
using namespace std;

const int size = 4;
const int newSize = size + 2;
signed short newval1[newSize];
signed short newval2[newSize + 2];

void addecho2(signed short val[])
{
  for( int i = (size / 2); i < newSize; ++i )
  {
    newval2[i] = val[i];
  }
}

void addecho1(signed short val[])
{
  for( int i = (size / 2); i < newSize; ++i )
  {
    newval1[i] = val[i];
  }
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  for (int i = 0; i < newSize; ++i) // set values in the array to 0
  {
    newval1[i] = 0;
  }

  addecho1(val);  // modify the new array elements

  for (int i = 0; i < size; ++i) // add the arrays together
  {
    newval1[i] += val[i];
  }

  addecho2(val);  // modify the new array elements

  for (int i = 0; i < size; ++i) // add the arrays together
  {
    newval2[i] += val[i];
  }

  cout.write( (char *)newval2, 2*size ); // write the data back out
  return 0;
}