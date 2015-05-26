#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DVD.h"
#include "DVDArray.h"
#include "DVDArrayP.h"

DVD::DVD(unsigned int i, char *t, char *dir)
{
	id = i;
	title = new char[sizeof(t)];
	for (int i = 0; i < sizeof(t); ++i)
	{
		title [i] = t[i];
	}
	director = new char[sizeof(t)];
	for (int i = 0; i < sizeof(t); ++i)
	{
		director [i] = dir[i];
	}
}
DVD::DVD()
{
	id = 0;
	title = new char['\0'];
	director = new char ['\0'];
}
DVD::DVD(DVD &d)
{
	id = d.getID();
	title = new char[sizeof(d.getTitle())];
	char *oldTitle = d.getTitle();
	char *oldDirector = d.getDirector();
	for (int i = 0; i < sizeof(d.getTitle()); ++i)
	{
		title [i] = oldTitle[i];
	}
	director = new char[sizeof(d.getDirector())];
	for (int i = 0; i < sizeof(d.getDirector()); ++i)
	{
		director [i] = oldDirector[i];
	}
}

DVD::~DVD()
{
	delete title;
	delete director;
}

unsigned int DVD::getID()
{
	return id;
}

char* DVD::getDirector()
{
	return director;
}

char* DVD::getTitle()
{
	return title;
}

void DVD::setID(unsigned int i)
{
	id = i;
}

void DVD::setTitle(char *t)
{
	delete title;
	char *title = new char [sizeof(t)];
	for (int i = 0; i < sizeof(t); ++i)
	{
		title[i] = t[i];
	}
}

void DVD::setDirector(char *t)
{
	delete director;
	char *director = new char [sizeof(t)];
	for (int i = 0; i < sizeof(t); ++i)
	{
		director[i] = t[i];
	}
}

void DVD::display()
{
	cout << "[" << getID() << ". " << getTitle() << "/" << getDirector() << "]" << endl;
}

DVD& DVD::operator++(int)
{
	id++;
	return *this;
}

DVD& DVD::operator=(DVD par)
{
	DVD returner;
	returner.setID(par.getID());
	delete director;
	char *director2 = new char [sizeof(par.getDirector())];
	for (int i = 0; i < sizeof(par.getDirector()); ++i)
	{
		director2[i] = par.getDirector()[i];
	}
	returner.setDirector(director2);
	delete title;
	char *title2 = new char [sizeof(par.getTitle())];
	for (int i = 0; i < sizeof(par.getTitle()); ++i)
	{
		title2[i] = par.getTitle()[i];
	}
	returner.setTitle(title2);
	return returner;
}

//start of DVDArray functions

DVDArray::DVDArray(unsigned int sz)
{
	size = sz;
	elt = new DVD [size];
}

DVDArray::DVDArray()
{
	size = DEFAULT_SIZE;
	elt = new DVD [size];
}

DVDArray::DVDArray(const DVDArray& par)
{
	size = par.size;
	elt = new DVD [size];
}

DVDArray::~DVDArray()
{
	delete elt;
}

unsigned int DVDArray::getSize()
{
	return size;
}

void DVDArray::display()
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << i << ": ";
		this->elt[i].display();
	}
}
DVD& DVDArray::operator[](int i)
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

// start of DVDArrayP functions

DVDArrayP::DVDArrayP(unsigned int sz)
{
	size = sz;
	elt = new DVDArray [size];
}

DVDArrayP::DVDArrayP()
{
	size = DEFAULT_SIZE;
	elt = new DVDArray [size];
}

DVDArrayP::DVDArrayP(const DVDArrayP& par)
{
	size = par.size;
	elt = new DVDArray [size];
}

DVDArrayP::~DVDArrayP()
{
	for (int i = 0; i < size; ++i)
	{
		elt[i].~DVDArray(); // depends on the [] operator
	}
	delete elt;
}

unsigned int DVDArrayP::getSize()
{
	return size;
}

void DVDArrayP::display()
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << i << ": ";
		this->elt[i].display();
	}
}

DVDArray& DVDArrayP::operator[](int i)
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

DVDArrayP* DVDArrayP::operator=(DVDArrayP arr)
{
	for (int i = 0; i < size; ++i)
	{
		elt[i].~DVDArray(); // depends on the [] operator
	}
	delete elt;
	size = arr.getSize();
	elt = new DVDArray[size];
	for (int i = 0; i < size; ++i)
	{
		elt[i] = arr.elt[i];
	}
	return this;
}