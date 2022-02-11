//0020267671
//DavisMcCue


// FILE: stacktemplate.h
// TEMPLATE CLASS IMPLEMENTED: Stack<Item> (see stack.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the Stack ADT:
//   1. The number of items in the Stack is in the member variable used.
//   2. The actual items of the Stack are stored in a partially-filled
//      array data[0]..data[used-1]. The stack elements appear from the
//      bottom (at data[0]) to the top (at data[used-1]).

#include <assert.h>  // Provides assert
#include <stdlib.h>  // Provides size_t
//DO 6.a: Uncomment the following two lines.
#include <iostream>
#include "stack.h"
using namespace std;

template <class Item>
void Stack<Item>::push(const Item& entry)
// Library facilities used: assert.h
{
    assert(size( ) < CAPACITY);
    data[used] = entry;
    used++;
}

template <class Item>
Item Stack<Item>::pop( )
// Library facilities used: assert.h
{
    assert(!is_empty( ));
    used--;
    return data[used];
}

template <class Item>
Item Stack<Item>::peek( ) const
// Library facilities used: assert.h
{
    assert(!is_empty( ));
    return data[used-1];
}

// DO 6.b: Complete the print method below as described in the
//         exercise description.  Print one data item per line (1.5).
template<class Item>
inline void Stack<Item>::print() const
{
    if (used != 0)
    {
        for (int i = used - 1; i > -1; i--)
        {
            cout << data[i];
            cout << endl;
        }
    }
}