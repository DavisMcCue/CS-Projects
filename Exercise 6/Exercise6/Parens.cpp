// FILE: parens.cxx
// A small demonstration program for a stack.
#include <cassert>    // Provides assert
#include <iostream>  // Provides cin, cout
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <string>  // If available, this could be changed to the standard
                       // String class
#include "stack.h"

using namespace std;

void eat_white(istream& in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
    while ((in.peek() != EOF) && isspace(in.peek())) in.ignore();
};

// PROTOTYPE for a function used by this demonstration program
bool balanced_parentheses(const string& expression
						  );
// Postcondition: A true return value indicates that the parentheses in the
// given expression are balanced. Otherwise, the return value is false.

int main( )
{
    string user_input;

    cout << "Type a String with some parentheses and no white space (or control-Z to end):\n";
    do
    {
        cin >> user_input;

        if (balanced_parentheses(user_input))
            cout << "Those parentheses are balanced.\n";
        else
            cout << "Those parentheses are not balanced.\n";
        cout << "Type a String with some parentheses and no white space (or control-Z to end):\n";
    } while (!cin.eof());

    cout << "That ends this balancing act.\n";
    return EXIT_SUCCESS;
}

bool balanced_parentheses(const string& expression)
// Library facilities used: assert.h, stack1.h, stdlib.h, myString.h.
{
    // Meaningful names for constants
    const char LEFT_PARENTHESIS = '(';
    const char RIGHT_PARENTHESIS = ')';

    Stack<char> store;    // Stack to store the left parentheses as they occur
    size_t i;             // A index into the String
    char next;            // The next character from the String
    char discard;         // A char popped off the stack and thrown away
    bool failed = false;  // Becomes true if a needed parenthesis is not found

    for (i = 0; !failed  &&  (i < expression.length( )); i++)
    {
        next = expression[i];
        if (next == LEFT_PARENTHESIS)
        {
            assert(store.size( ) < store.CAPACITY);
            store.push(next);
        }
        else if ((next == RIGHT_PARENTHESIS) && (!store.is_empty( )))
            discard = store.pop( );
        else if ((next == RIGHT_PARENTHESIS) && (store.is_empty( )))
            failed = true;
    }

    return (store.is_empty( ) && !failed);
}
