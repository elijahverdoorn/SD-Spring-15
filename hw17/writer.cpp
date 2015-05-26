#include<fstream>
using namespace std;

int main()
{
  ofstream f("output.txt");

  f << "Hello world!" << endl;
  f.close();
}