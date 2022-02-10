// polydr.cpp
// Copyright by Venu Dasigi

#include "poly.h"
#include <iostream>

using namespace std;

const unsigned int MAX = 50;
void main ()
{
	// Pre: None.
	// Post: Give the user a menu of choices.
	//       Based on what command the user inputs, take
	//       the appropriate action as guaranteed by the menu.
	//       Input is accepted in a case-insensitive manner!
	poly p[MAX];
	char command;
	unsigned int i, j, k;
	float value;
	void printmenu ();

	printmenu();
	do
	{
		cin >> command;
		switch (command)
		{
		case '?':
		case 'H':
		case 'h':
			printmenu();
			break;
		case 'R':
		case 'r':
			cin >> i;
			//cout << "Reading The Polynomial " << i << endl;
			p[i].read();
			break;
		case 'P':
		case 'p':
			cin >> i;
			//cout << "Printing The Polynomial " << i << endl;
			p[i].write();
		case '+':
			cin >> i;
			cin >> j;
			cin >> k;
			p[k] = p[i].plus(p[j]);
			break;
		case '-':
			cin >> i;
			cin >> j;
			cin >> k;
			p[k] = p[i].minus(p[j]);
			break;
		case 'E':
		case 'e':
			cin >> i;
			cin >> value;
			cout << "The Value Of Polynomial " << i << " With " << value << " Substuted for x is " << p[i].evaluate(value) << endl;
			break;
		};
	}
	while ((command != 'Q') && (command != 'q'));
};

void printmenu ()
{
	// Pre: None.
	// Post: Print a menu of choices.

	cout << "Available Commands" << endl;
	cout << "?: to print this menu" << endl;
	cout << "H: to print this menu" << endl;
	cout << "R n: to read a value for polynomial n" << endl;
	cout << "P n: to print the value of polynomial n" << endl;
	cout << "+ i j k: to add polynomials i an j and store results in k" << endl;
	cout << "- i j k: to subtract polynomial j and i and store restuls in k" << endl;
	cout << "E n v : to evaluate polynomial n with its variable set to value v" << endl;
	cout << "Q: to quit" << endl;
};
