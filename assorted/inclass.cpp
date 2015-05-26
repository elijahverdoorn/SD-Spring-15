#include <iostream>
using namespace std;

int stringLength(char s[])
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
	int counter = 0;
	for (int x = 0; longstring [x] != '\0'; x++)
	{
		if (longstring[x] == innerstring [x])
		{
			bool tf = true;
			for(int i = x; i != length && tf != false; i++)
			{
				if (longstring[i] != innerstring[i])
				{
					tf = false;
				}else{
					cout << counter << endl;
					counter++;	
				}

			} 
		}
	}
	return counter;	
}

main()
{
	char longstring [] = "abclkasdfjsadlkjfsdlkafabc", innerstring [] = "abc";
	cin >> longstring;
	cin >> innerstring;
	int length = stringLength(innerstring);
	int number = compare(longstring, innerstring, length);

	cout << "the number of times is " << number << endl;
}