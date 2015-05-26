#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DVD.h"

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