#ifndef _MENUITEM_
#define _MENUITEM_
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class MenuItem
{
	int val;
	char *label; // wil become an array
public:
	MenuItem(int init_val, char init_label[]);
	MenuItem();
	MenuItem(const MenuItem &mi);

	~MenuItem();

	int get_val();
	void set_val(int new_val);
	char* get_label();
	void set_label(char *new_label);
	void display();
	char* makeString(char *str);

	MenuItem operator=(const MenuItem &mi);

};

#endif // _MENUITEM_