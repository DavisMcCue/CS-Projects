// P4driver.cpp
// Copyright by Venu Dasigi

#include "bintree.h"
#include <iostream>

using namespace std;

void eat_white (istream & in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
  while ((in.peek()!=EOF) && isspace(in.peek())) in.ignore();
};

void print (int x) {cout << x << " ";}

int main ()
{
	char command;
	int value;
	BinaryTreeNode<int> * tree = NULL;
	BinaryTreeNode<int> * temp;
	
	void printmenu ();

	printmenu();
	
	do
	{
	    eat_white (cin);
		cin >> command;
		switch (command)
		{
			case '?':
				printmenu();
				break;
			case 'I':
			case 'i':
				cin >> value;
				cout << "Inserting " << value << " into the BST" << endl;
				insert (tree, value);
				break;
			case 'D':
			case 'd':
				cin >> value;
				cout << "Deleting/removing " << value << " from the BST" << endl;
				remove (tree, value);
				break;
			case 'C':
			case 'c':
				cout << "Clearing the BST" << endl;
				tree_clear (tree);
				break;
			case 'R':
			case 'r':
				cout << "Reflecting, i.e., creating a mirror image of the BST" << endl;
				temp = reflect (tree);
				tree_clear (tree);
				tree = temp;
				break;
			case 'H':
			case 'h':
				cout << "Printing the tree height:" << height(tree) << endl;
				break;
			case 'S':
			case 's':
				cout << "Printing the tree size (# nodes):" << tree_size(tree) << endl;
				break;
			case 'P':
			case 'p':
				cout << "Printing the tree sideways:" << endl;
				printTree (tree);
				break;
			case 'T':
			case 't':
				cout << "Traversal of the tree in ";
				char next;
				cin >> next;
				if (next == 'R' || next == 'r')
				{
					cout << "preorder:" << endl;
					preorder (print, tree);
					cout << endl;
				}
				else if (next == 'I' || next == 'i')
				{
					cout << "inorder:" << endl;
					inorder (print, tree);
					cout << endl;
				}
				else if (next == 'O' || next == 'o')
				{
					cout << "postorder:" << endl;
					postorder (print, tree);
					cout << endl;
				}
				else cout << "Enter a valid command.  Type H or ? for help." << endl;
				break;
			case 'Q':
			case 'q':
				if (tree) tree_clear (tree);
				cout << "Clearing any non-empty tree to avoid memory leaks.  Thank you.  Bye!" << endl;
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
		<< "Available commands:" << endl
		<< "?: to print this menu"  << endl
		<< "I value: to insert the specified data value into the BST" << endl
		<< "D value: to delete the specifieditem with the data value from the BST" << endl
		<< "C: to clear the tree (to avoid any memory leak)" << endl
		<< "R: to reflect, i.e., create a mirror image in place" << endl
		<< "H: to print the tree height" << endl
		<< "S: to print the tree size (number of nodes)" << endl
		<< "P: Print three sideways using the supplied utility" << endl
		<< "TR/TI/TO: Traverse the tree in pReorder/Inorder/pOstorder and print values" << endl
		<< "Q: Quit (but only after taking care of any memory leaks" << endl;
};
