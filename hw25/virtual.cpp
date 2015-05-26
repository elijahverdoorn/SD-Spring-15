#include <iostream>
using namespace std;

class Animal
{
	int size;
public:
	int getSize() {return size;}
	virtual int getTail() {return 0;}
	virtual void setTail(int par) {}
};

class Lion : public Animal
{
	int tail = 3;
public:
	int getTail() {return tail;}
	void setTail(int par) {tail = par;}
};

int main()
{
	Lion x;
	Animal *y;
	y = &x;
	y->setTail(4);
	cout << y->getTail() << endl;
	return 0;
}