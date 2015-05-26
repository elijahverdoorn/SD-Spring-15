#include <iostream>
#include <string>
using namespace std;

#define NEWLINE '\n'
#define RETURN '\r'
#define TAB '\t'
#define VERTTAB '\v'
#define BACK '\b'
#define FEED '\f'
#define	ALERT '\a'
#define SGLQUT '\''
#define DBLQUT '\"'
#define QUESTION '\?'
#define BCKSLASH '\\'

main()
{
	char x = 'x';
	string a = "this is a string";
	cout << NEWLINE << RETURN << TAB << VERTTAB << BACK << FEED << ALERT << SGLQUT << DBLQUT << QUESTION << BCKSLASH << endl;
	cout << x << " " << a << endl;
}