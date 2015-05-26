#include <iostream>
using namespace std;
#include "IntArray.h"

IntArray::IntArray(unsigned int sz)
{
	size = sz;
	elt = new int [size];
	for (unsigned int i = 0; i < size; ++i)
	{
		elt[i] = 0;
	}
}

IntArray::IntArray()
{
	size = DEFAULT_SIZE;
	elt = new int [size];
	for (unsigned int i = 0; i < size; ++i)
	{
		elt[i] = 0;
	}
}

IntArray::IntArray(const IntArray& par)
{
	size = par.size;
	elt = new int [size];
	for (unsigned int i = 0; i < size; ++i)
	{
		elt[i] = 0;
	}
}

IntArray::~IntArray()
{
	delete elt;
}

unsigned int IntArray::getSize()
{
	return size;
}

void IntArray::display()
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << i << ": " << this->elt[i] << endl;
	}
}

int& IntArray::operator[](int i)
{
	if ((i >= 0) && (i < (getSize() - 1)))
	{
		return elt[i];
	}
	else
	{
		cout << "Outside of array size" << endl;
		if (i < 0)
		{
			return elt[0];
		}
		if (i > (getSize() - 1))
		{

			return elt[getSize() - 1];
		}
	}
	cout << "something broke" << endl;
	return elt[0];
}