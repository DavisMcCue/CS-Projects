//0020267671
//DavisMcCue

#include <iostream>
#include "stack.h"

using namespace std;

// You may or may not need this.  Use it if you need it.
void eat_white (istream & in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
  while ((in.peek()!=EOF) && isspace(in.peek())) in.ignore();
};

int main ()
{
    char c;
    int n;
// DO 1: Declare/instantiate a character stack (0.25).
    Stack<char> chars;
// DO 1: Declare/instantiate an integer stack (0.25).
    Stack<int> in;

    cout << "Input a short sentence and hit enter: ";

    while ((cin.peek() != '\n'))
    {
        c = cin.get();
// DO 2: push the character onto the character stack (0.5).
        chars.push(c);
    }

    cout << "Thank you.  Now input some integers:" << endl;

// DO 3: In a loop, read integers from the input until the end of file and
//     push each integer onto the integer stack, similar to the above (1).

    while (cin >> n)
    {
        in.push(n);
    }

// DO 7: After implementing the print method (look for DO 6.a and 6.b
//       in stacktemplate.h), call print on each of the two stacks (1).
    chars.print();
    in.print();


// DO 4: In a loop, pop the characters from the character stack until it is empty
//     and print each (1).

    while (chars.size() > 0 || !chars.is_empty())
    {
        std::cout << chars.pop();
    }

// DO 5: In a loop, pop the numbers from the integer stack until it is empty
//     and print each (1).

    cout << endl;
    while (in.size() > 0 || !in.is_empty())
    {
        std::cout << in.pop() << endl;
    }

    cout << endl << "Bye!" << endl;
}