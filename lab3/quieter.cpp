#include <iostream>
using namespace std;

const int size = 1152000;

void quieter(signed short val[])
{
  for( int i = 0; i < size; ++i )
    val[i] /= 5;
}

int main()
{
  signed short val[size];  // make an array to hold the data
  cin.read( (char *)val, 2*size ); // read the data into the array

  quieter(val);  // modify the array elements

  cout.write( (char *)val, 2*size ); // write the data back out
  return 0;
}