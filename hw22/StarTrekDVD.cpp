#include <iostream>
using namespace std;
#include "DVD.h"
#include "StarTrekDVD.h"

StarTrekDVD::StarTrekDVD(unsigned int i, char *t, char *dir, unsigned int n, char *cap)
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
	episode = n;
	captain = new char[sizeof(cap)];
	for (int i = 0; i < sizeof(cap); ++i)
	{
		captain [i] = cap[i];
	}

}
StarTrekDVD::StarTrekDVD()
{
	id = 0;
	title = new char['\0'];
	director = new char ['\0'];
	episode = -1;
	captain = new char ['\0'];
}
StarTrekDVD::StarTrekDVD(StarTrekDVD &d)
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
	episode = d.getEpisode();
	char *oldCaptain = d.getCaptain();
	captain = new char[sizeof(d.getCaptain())];
	for (int i = 0; i < sizeof(d.getCaptain()); ++i)
	{
		captain [i] = oldCaptain[i];
	}
}

StarTrekDVD::~StarTrekDVD()
{
	delete captain;
	this->DVD::~DVD();
}

int StarTrekDVD::getEpisode()
{
	return episode;
}

char* StarTrekDVD::getCaptain()
{
	return captain;
}

void StarTrekDVD::display()
{
	cout << "[" << getID() << ". ST" << getEpisode() << ":" << getTitle() << "/" << getDirector() << "/" << getCaptain() <<"]" << endl;
}

void StarTrekDVD::setEpisode(unsigned int e)
{
	episode = e;
}

void StarTrekDVD::setCaptain(const char *c)
{
	delete captain;
	captain = new char[sizeof(c)];
	for (int i = 0; i < sizeof(c); ++i)
	{
		captain[i] = c[i];
	}
}

StarTrekDVD& StarTrekDVD::operator= (StarTrekDVD par)
{
	StarTrekDVD returner;
	returner.setID(par.getID());
	returner.setEpisode(par.getEpisode());
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
	delete captain;
	char *captain2 = new char [sizeof(par.getCaptain())];
	for (int i = 0; i < sizeof(par.getCaptain()); ++i)
	{
		captain2[i] = par.getCaptain()[i];
	}
	returner.setCaptain(captain2);
	return returner;
}