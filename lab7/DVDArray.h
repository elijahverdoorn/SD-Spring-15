#ifndef _DVD_
#define _DVD_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DVD
{
	unsigned int id;
	char *title;
	char *director;
public:
	DVD(unsigned int i, char *t, char *dir);
	DVD();
	DVD(DVD &d);

	~DVD();

	unsigned int getID();
	char* getTitle();
	char* getDirector();
	void display();
	void setID(unsigned int i);
	void setTitle(char *t);
	void setDirector(char *t);
	DVD& operator++ (int x);
	DVD& operator= (DVD par);

};

#endif
#ifndef _DVDArray_
#define _DVDArray_

class DVDArray
{
	DVD *elt;
	unsigned int size;
	const static int DEFAULT_SIZE = 10;
public:
	DVDArray(unsigned int sz);
	DVDArray();
	DVDArray(const DVDArray& par);

	~DVDArray();

	unsigned int getSize();
	void display();
	DVD& operator[](int i);
};

#endif // _DVD_