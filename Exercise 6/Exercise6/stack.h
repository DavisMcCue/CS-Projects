//0020267671
//DavisMcCue



// FILE: stack.h
// TEMPLATE CLASS PROVIDED: Stack<Item> (a stack of items)
//   The template parameter, Item, is the data type of the items in the Stack.
//   It may be any of the C++ built-in types (int, char, etc.), or a class
//   with a default constructor, a copy constructor, and an assignment
//   operator.
//
// TYPEDEF and MEMBER CONSTANTS for the Stack<Item> template class:
//   static const size_t CAPACITY = ____
//     Stack<Item>::CAPACITY is the maximum number of items that a stack can 
//     hold.
//
// CONSTRUCTOR for the Stack<Item> template class:
//   Stack( )
//     Postcondition: The stack has been initialized as an empty Stack.
//
// MODIFICATION MEMBER FUNCTIONS for the Stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the Stack.
//
//   Item pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been popped and returned.
//
// CONSTANT MEMBER FUNCTIONS for the Stack<Item> class:
//   size_t size( ) const
//     Postcondition: Return value is the total number of items in the Stack.
//
//   bool is_empty( ) const
//     Postcondition: Return value is true if the Stack is empty.
//
//   Item peek( ) const
//     Precondition: size( ) > 0.
//     Postcondition: Return value is the top item on the Stack (but the Stack
//     is unchanged).
//
//   void print( ) const
//     Preconsition: Item should have the output operator defined for it.
//     Postcondition: Print all stored values in the Stack from top to bottom,
//     one per line (but the Stack is unchanged).
//
//  VALUE SEMANTICS for the Stack<Item> class:
//     Assignments and the copy constructor may be used with Stack<Item> 
//     objects.

#ifndef STACK_H
#define STACK_H
#include <stdlib.h> // Provides size_t

    template <class Item>
    class Stack
    {
    public:
        // MEMBER CONSTANTS -- See page 87 for a better alternative
        enum { CAPACITY = 64 };
        // CONSTRUCTOR
        Stack( ) { used = 0; }
        // MODIFICATION functions
        void push(const Item& entry);
        Item pop( );
        // CONSTANT functions
        size_t size( ) const { return used; }
        bool is_empty( ) const { return used == 0; }
        Item peek( ) const;
        void print( ) const;
    private:
        Item data[CAPACITY];  // Partially-filled array 
        size_t used;          // How much of array is being used
    };

#include "stacktemplate.h"
     
#endif
