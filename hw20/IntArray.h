#include <iostream>
#ifndef IntArray
#define _INTARRAY_

class IntArray
{
	int *elt;
	unsigned int size;
	const int static DEFAULT_SIZE = 10;
public:
	IntArray(unsigned int sz);
	IntArray();
	IntArray(const IntArray& par);

	~IntArray();

	unsigned int getSize();
	void display();
	int& operator[](int i);
};
#endif