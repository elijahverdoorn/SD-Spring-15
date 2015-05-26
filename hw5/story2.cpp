#include <iostream>
using namespace std;

void case1 (int par)
{
	switch (par)
	{
		case 1: 
			cout << "he goes to the cage, he eats food and is happy, the end" << endl;
			return;
		case 2:
			cout << "he goes to the pause, eats food, but spends money. he is full, but poor. the end" << endl;
			return;
		default:
			return;
	}
}
void case2 (int par)
{
	switch (par)
	{
		case 1: 
			cout << "he goes to the library, he eats does homework and is happy, the end" << endl;
			return;
		case 2:
			cout << "he goes to the pause, eats food, but does not do homework.. he is full, but failing. the end" << endl;
			return;
		default:
			return;
	}
}
main()
{
	int answer;
	cout << "welcome to the story" << endl;
	cout << "there once was a student who had homework" << endl;
	cout << "should he \n 1. do his homework \n or \n 2. not do homework?" << endl;
	cin >> answer;
	switch (answer)
	{
		case 1:
			cout << "he does his homework, and is now hungry. He can \n 1. go to the cage \n or \n 2. go to the pause" << endl;
			cin >> answer;
			case1 (answer);
			break;
		case 2:
			cout << "he does not his homework, and is now behind. He can \n 1. go to the library \n or \n 2. go to the pause" << endl;
			cin >> answer;
			case2 (answer);
			break;
		default:
			break;
	}
	return 0;
}