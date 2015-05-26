#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node {
	string info;
	node *link;

};

node* deleteOther(node *head)
{
	node *start = new node; 
	start = head;
	node *cur = new node;
	cur = head;
	while (cur != NULL)
	{
		node *next = new node;
		next = cur;
		next = next->link;
		next = next->link;
		cur->link = next;
		cur = cur->link;
	}
	return start;
}

node* insertG(node *head)
{
	node *cur;
	node *start;
	start = head;
	cur = head;
	while (cur != NULL)
	{
		if (cur->info[0] == 'g')
		{		
			node *middle = new node;
			middle->info = "xxx";
			node *next = cur->link;
			cur->link = middle;
			middle->link = next;
			cur = middle;
		}else{
			cur = cur->link;
		}
	}
	return start;
}

int main()
{
	string input;
	node *next, *cur, *head;

	// begin linked list
	cur = new node;
	head = cur;
	cin >> input;
	cur->info = input;

	while ((cin >> input ) && (input != "q"))
	{
		next = new node;
		next->info = input;
		cur->link = next;
		cur = next;
	}
	cur->link = NULL;
	// end of linked list

	cout << "calling the insertG function" << endl;

	// call one of the quiz functions
	head = insertG(head);

	// begin output
	cur = head;
	while (cur != NULL)
	{
		cout << cur->info << endl;
		cur = cur->link;
	}
	// end output

	cout << "calling the deleteOther function" << endl;

	// call the second of the quiz functions
	head = deleteOther(head);

	// begin output
	cur = head;
	while (cur != NULL)
	{
		cout << cur->info << endl;
		cur = cur->link;
	}
	// end output

	delete next, cur, head;
	return 0;
}
