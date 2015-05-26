#include <iostream>
#include <new>
using namespace std;

int stringLength(const char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return i;
}

void copyString(char * &outputChar, const char *constChar)
{
	int len = stringLength(constChar);
	outputChar = new char[len];
	for (int i = 0; i < len; ++i)
	{
		outputChar[i] = constChar[i];
	}

}

main()
{
	const char *str1 = "Hello!";
	char *str2;
	copyString(str2, str1);
	cout << "str1 is " << str1 << " and str2 is " << str2 << endl;
	delete [] str2;
	return 0;
}