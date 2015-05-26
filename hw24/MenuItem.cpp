#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#include "MenuItem.h"

MenuItem::MenuItem(int init_val, char *init_label)
{
	val = init_val;
	label = new char[strlen(init_label)];
	for (int i = 0; i < strlen(init_label); i++)
	{
		label[i] = init_label[i];
	}
}

MenuItem::MenuItem()
{
	val = 0;
	label = new char[0];
}

MenuItem::MenuItem(const MenuItem &mi)
{
	val = mi.val;
	label = new char[strlen(mi.label)];
	for (int i = 0; i < strlen(mi.label); ++i)
	{
		label[i] = mi.label[i];
	}
}

MenuItem::~MenuItem()
{
	delete label;
}

int MenuItem::get_val()
{
	return val;
}

void MenuItem::set_val(int new_val)
{
	val = new_val;
}

char* MenuItem::get_label()
{
	return label;;
}

void MenuItem::set_label(char *new_label)
{
	delete label;
	label = new char[sizeof(new_label)];
	for (int i = 0; i < sizeof(new_label); ++i)
	{
		label[i] = new_label[i];
	}
}

void MenuItem::display()
{
	cout << "[" << val << "] " << label << endl;
}

char* MenuItem::makeString(char* str) // not used
{
	char *returner = new char[sizeof(str)];
	for (int i = 0; i < sizeof(str); ++i)
	{
		returner[i] = str[i];
	}
	return returner;
}

MenuItem MenuItem::operator=(const MenuItem &mi)
{
	MenuItem returner;
	returner.set_label(mi.label);
	returner.set_val(mi.val);
	return returner;
}
