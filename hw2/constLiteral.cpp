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

#define PI 3.14

main()
{
	char x = 'x';
	string a = "this is a string";
	cout << NEWLINE << RETURN << TAB << VERTTAB << BACK << FEED << ALERT << SGLQUT << DBLQUT << QUESTION << BCKSLASH << endl;
	cout << x << " " << a << endl;

	const double pi = 3.14;
	cout << PI << " using define, or " << pi << " as a const variable." << endl;
	// pi = 4.16;
}