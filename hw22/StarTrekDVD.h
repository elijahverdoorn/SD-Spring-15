#ifndef _StarTrekDVD_
#define _StarTrekDVD_
#include <iostream>
using namespace std;
#include "DVD.h"

class StarTrekDVD: public DVD
{
	unsigned int episode;
	char *captain;
public:
	StarTrekDVD(unsigned int i, char *t, char *dir, unsigned int n, char *cap);
	StarTrekDVD();
	StarTrekDVD(StarTrekDVD &d);

	~StarTrekDVD();

	int getEpisode();
	char* getCaptain();
	void display();
	void setEpisode(unsigned int e);
	void setCaptain(const char *c);
	StarTrekDVD& operator= (StarTrekDVD par);
};
#endif // _StarTrekDVD_