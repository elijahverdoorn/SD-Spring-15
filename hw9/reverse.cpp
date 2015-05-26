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

void reverse(char arr[], int length)
{
	for (int  i = 0; i < (length / 2); i++)
	{
		char temp = arr[i];
//		cout << "temp: " << temp << endl;
		arr[i] = arr[length - i - 1];
//		cout << "new arr[i] " << arr[i] << endl;
		arr[length - i - 1] = temp;
	}
	return;
}

main()
{
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	int len = stringLength(arr);
	reverse(arr, len);

	for(int i = 0; arr[i] != '\0'; i++)
	{
		cout << arr[i] << endl;
	}
}