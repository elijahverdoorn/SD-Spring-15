#include <iostream>
using namespace std;

class Measurement {
public:
  int shoesize;
  double height;
  Measurement () {}
  Measurement (int s, double h) {shoesize = s; height = h;}
};

class Hobbit {
public:
  Measurement m;
  Hobbit *buddy;
  Hobbit() {}
  Hobbit (int s, double h)
  {
    m = Measurement(s,h);
  }
};

int main()
{
  Hobbit pippin (7, 42);
  Hobbit merry (8, 41.5);

  pippin.buddy= &merry;
  merry.buddy = &pippin;

  cout << "Pippin's buddy has height " << (*(pippin.buddy)).m.height << endl;
}