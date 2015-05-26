#include <iostream>
using namespace std;

class Animal
{
public:
	int height, weight;
	Animal()
	{
		height = 0;
		weight = 0;
	}
	Animal(int h, int w)
	{
		height = h;
		weight = w;
	}
	void display()
	{
		cout << height << " " << weight << endl;
	}
};

class Bird: public Animal
{
	int wingspan;
public:
	Bird(int h, int w, int x) : public Animal()
	{
		height = h;
		weight = w;
		wingspan = x;
	}
	void display()
	{
		cout << height << " " << weight << " " << wingspan << endl;
	}
};

class Reptile: public Animal
{
	int bloodTemp;
public:
	Reptile(int h, int w, int b) : public Animal()
	{
		height = h;
		weight = w;
		bloodTemp = b;
	}
	void display()
	{
		cout << height << " " << weight << " " << bloodTemp << endl;
	}
};

main()
{
	Reptile r = Reptile(1,2,3);
	Bird b = Bird(4,5,6);
	b.display();
	r.display();

}