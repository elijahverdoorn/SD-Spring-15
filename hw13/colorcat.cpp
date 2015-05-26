#include<iostream>
using namespace std;

struct Cat 
{
  int color;
  double weight;
  void grow() {
    weight *= 1.1;
  }
};

void changeColor(Cat &theCat, int theColor)
{
  theCat.color = theColor;
}

int main()
{
  Cat misty, dusty;
  misty.color = 3;
  misty.weight = 2;
  cout << "misty weighs " << misty.weight << endl;   // misty weighs 2
  misty.grow();
  changeColor(misty, 4);
  cout << "misty weighs " << misty.weight << endl;   // misty weighs 2.2
  cout << "misty's color is " << misty.color << endl; // cout the color
}