#include <iostream>
#include <string>
#include "MenuItem.h"
using namespace std;
#ifndef _MENU_
#define _MENU_

class Menu
{
	MenuItem* vec; // to be array
	unsigned int size;
	unsigned int count; // count <= size
	int not_found; // int that is smaller than all the vals of all the MenuItems in the menu
	const static int DEFAULT_SIZE = 20; // the default size of variable size;
public:
	Menu(int sz);
	Menu();
	Menu(const Menu &m);

	~Menu();

	int get_size();
	int get_count();
	int get_not_found();
	int add_item(int v1, char* lbl);
	int add_item(MenuItem item);
	void display();
	int get_value();

	void copyVec(Menu m);
	void deleteVec();

	Menu operator=(const Menu &m);
	MenuItem operator[](int par);
};


#endif // _MENU_