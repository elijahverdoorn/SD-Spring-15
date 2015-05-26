// example about structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct musics_t {
  string title;
  int year;
} mine, yours;

void printmusic (musics_t music);

int main ()
{
  string mystr;

  mine.title = "Anna Sun";
  mine.year = 2012;

  cout << "Enter title: ";
  getline (cin,yours.title);
  cout << "Enter year: ";
  getline (cin,mystr);
  stringstream(mystr) >> yours.year;

  cout << "My favorite music is:\n ";
  printmusic (mine);
  cout << "And yours is:\n ";
  printmusic (yours);
  return 0;
}

void printmusic (musics_t music)
{
  cout << music.title;
  cout << " (" << music.year << ")\n";
}