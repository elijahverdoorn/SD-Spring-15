#include <iostream>
#include <string>
#include "MenuItem.h"
#include "Menu.h"
using namespace std;

Menu::Menu(int sz)
{
	size = sz;
	count = 0;
	not_found = -1;
	vec = new MenuItem[sz];
}
Menu::Menu()
{
	vec = new MenuItem[DEFAULT_SIZE];
	size = DEFAULT_SIZE;
	count = 0;
	not_found = -1;
}
Menu::Menu(const Menu &m)
{
	cout << "testing" << endl;
	size = m.get_size();
	count = m.get_count();
	not_found = m.get_not_found();
	copyVec(m);
}

Menu::~Menu()
{
	deleteVec();
}

int Menu::get_size()
{
	return size;
}
int Menu::get_count()
{
	return count;
}
int Menu::get_not_found()
{
	return not_found;
}
int Menu::add_item(int v1, char* lbl)
{
	if (count < size)
	{
		MenuItem x (v1, lbl);
		vec[count] = x;
		count++;
		if (v1 < not_found)
		{
			not_found = v1-1;			
		}
	}else{
		return 0;
	}
}
int Menu::add_item(MenuItem item)
{
	if (count < size)
	{
		MenuItem x (item);
		vec[count] = x;
		count++;
		if (item.get_val() < not_found)
		{
			not_found = item.get_val() - 1;
		}
	}else{
		return 0;
	}
}
void Menu::display()
{
	cout << "size=" << size << " count=" << count << " not_found=" << not_found << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << i << ". ";
		vec[i].display();
	}
}
int Menu::get_value()
{
	for (int i = 0; i < count; ++i)
	{
		cout << i << ". ";
		vec[i].display();
	}
	cout << "Your choice (1-" << count + 1 << "):" << endl;
	int user_val;
	cin >> user_val;
	int returner;
	if (user_val > count + 1)
	{
		returner = not_found;
	}else{
		returner = vec[user_val].get_val();
	}
	return returner;
}

Menu Menu::operator=(const Menu &m)
{
	Menu returner;
	returner.size = m.size;
	returner.count = m.count;
	returner.not_found = m.not_found;
	returner.copyVec(m);
	return returner;
}

MenuItem Menu::operator[](int par)
{
	return vec[par];
}

//helper methods
void Menu::copyVec(Menu &m)
{
	vec = new MenuItem[m.size];
	count = m.get_count();
	for (int i = 0; i < count; ++i)
	{
		MenuItem x (m[i]);
		vec[i] = x;
	}
}

void Menu::deleteVec()
{
	delete vec;
}