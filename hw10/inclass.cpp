#include <iostream>
using namespace std;

int maincounter = 0;
int smallcounter = 0;
int x = 0;

int stringLength(char s[]) // from hw9
{
  int i = 0;
  while (s[i] != '\0')
  {
	i++;	
  }
  return i;
}

int compare( char longstring[], char innerstring[], int length)
{
	if (longstring[x] != '\0') //if there are characters left
	{
		if (longstring[x] == innerstring[smallcounter]) // if a match is found
		{
			smallcounter++; // increment a global variable
			if (smallcounter == length) // if we have the same number of sequential matches as the length of the string to be found
			{
				maincounter++; // then we have a complete match
				smallcounter = 0; // reset so that we can count again
			}
		}else{
			smallcounter = 0; // reset the small counter, prevents partial matches from counting
		}
		x++; // move to the next array element
		compare(longstring, innerstring, length); //loop
	}else{
		return maincounter; // return up the chain
	}
}

main()
{
	char longstring [10]; 
	char innerstring [3]; // data input
	for (int i = 0; i < 10; i++)
	{
		cin >> longstring[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> innerstring[i];
	}
	int length = stringLength(innerstring); // get the length of the string to be found
	int number = compare(longstring, innerstring, length); // call compare

	cout << "the number of times is " << number << endl; // output result
}