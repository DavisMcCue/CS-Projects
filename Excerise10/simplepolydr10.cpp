// simplepolydr.cpp
// Copyright by Venu Dasigi

#include "simplepoly10.h"
#include <iostream>

using namespace std;

const unsigned int MAX = 50;
int main ()
{
	// Pre: None.
	// Post: Give the user a menu of choices.
	//       Based on what command the user inputs, take
	//       the appropriate action as guaranteed by the menu.
	//       Input is accepted in a case-insensitive manner!
	SimplePoly p[MAX];
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
				cout << "Reading polynomial " << i << endl;
				cin >> p[i];
				break;
			case 'P':
			case 'p':
				cin >> i;
				cout << "Printing polynomial " << i << ": " << p[i] << endl;
				break;
			case '+':
				cin >> i >> j >> k;
				cout << "Printing the sum of the number " << i <<
					" and polynomial " << j << ": " << p[i] + p[j] << endl;
				cout << "Now, printing the sum of polynomial " << i <<
					" and the number " << j << ": " << p[i] + j << endl;
				cout << "The sum of polynomials " << i <<
					" and " << j << " is being saved in polynomial "
					<< k << endl;
				p[k] = p[i] + p[j];
				break;
			case '-':
				cin >> i >> j >> k;
				cout << "Printing the difference of the number " << i <<
					" and polynomial " << j << ": " << p[i] - p[j] << endl;
				cout << "Now, printing the difference of polynomial " << i <<
					" and the number " << j << ": " << p[i] - j << endl;
				cout << "The difference of polynomials " << i <<
					" and " << j << " is being saved in polynomial "
					<< k << endl;
				p[k] = p[i] - p[j];
				break;
			case 'E':
			case 'e':
				cin >> i >> value;
				cout << "The polynomial " << i << " evaluated at "
					<< value << " equals ";
				cout << p[i].evaluate(value) << endl;
				break;
			case 'Q':
			case 'q':
				cout << "Thank you.  Bye!" << endl;
				break;
			default:
				cout << "Enter a valid command.  Type H or ? for help."
					<< endl;
		};
	}
	while ((command != 'Q') && (command != 'q'));
	return (0);
};

void printmenu ()
{
	// Pre: None.
	// Post: Print a menu of choices.
	cout
		<< "Available commands:\n"
		<< "?: to print this menu\n"
		<< "H: to print this menu\n"
		<< "R n: to read a value for polynomial n\n"
		<< "P n: to print the value of polynomial n\n"
		<< "+ i j k: to add polynomials i and j and store result in k\n"
		<< "- i j k: to subtract polynomials j from i and store result in k\n"
		<< "E n v: to evaluate polynomial n with its variable set to value v\n"
		<< "Q: to quit\n";
};
