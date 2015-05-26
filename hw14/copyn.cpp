#include <iostream>
using namespace std;

void copyn(char *&chrpar, char arrpar[], int intpar)
{
	if (intpar < 0)
	{
		return;
	}
	if (intpar == 0)
	{
		chrpar = 0;
		return;
	}

	char *returner;
	returner = new char [intpar];
	for (int i = 0; i < intpar; ++i)
	{
		returner[i] = arrpar[i];
	}
	chrpar = returner;

}

int main() 
{                                                                                                                        
	char *buff;                                                                                                                             
	copyn(buff, "St. Olaf", 5);   

	cout << buff << endl;                                                                                                                   
}
