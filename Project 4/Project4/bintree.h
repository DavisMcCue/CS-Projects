//0020267671
//Davis McCue

// FILE: bintree.h
// PROVIDES: An expanded toolkit of nine template functions for manipulating 
// binary trees. Each node of the tree contains a piece of data and pointers
// to its left and right children as shown here:
//
//     template <class Item>       Item may be any of the C++ built-in types
//     struct BinaryTreeNode       (int, char, etc.), or a class with a default
//     {                           constructor, and an assignment operator.
//         Item data;
//         BinaryTreeNode *left;    
//         BinaryTreeNode *right;
//     }
//
// The left and right pointers may be NULL to indicate no child. Each tree
// is accessed through a pointer to its root. A NULL root pointer indicates an
// empty tree.
//
// FUNCTIONS in the binary tree toolkit:
//   template <class Item>
//   BinaryTreeNode<Item>* create_node(
//       const Item& entry,
//       BinaryTreeNode<Item>* l_ptr = NULL,
//       BinaryTreeNode<Item>* r_ptr = NULL
//   )
//     Postcondition: The value returned is a pointer to a newly allocated node
//     with its data equal to entry, and its child pointers equal to l_ptr and
//     r_ptr. Note: If there is insufficient dynamic memory, then the
//     new_handler is called.
//
//   template <class Item>
//   bool is_leaf(const BinaryTreeNode<Item>& node)
//     Postcondition: The return value is true if node is a leaf;
//     otherwise the return value is false.
//
//   template <class Item>
//   void tree_clear(BinaryTreeNode<Item>*& root_ptr)
//     Precondition: root_ptr is the root pointer of a binary tree (which may
//     be NULL for the empty tree).
//     Postcondition: All nodes at the root or below have been returned to the
//     heap, and root_ptr has been set to NULL.
//
//   template <class Item>
//   BinaryTreeNode<Item>* tree_copy(BinaryTreeNode<Item>* root_ptr)
//     Precondition: root_ptr is the root pointer of a binary tree (which may
//     be NULL for the empty tree).
//     Postcondition: A copy of the binary tree has been made, and the return
//     value is a pointer to the root of this copy.
//
//   template <class Process, class Item>
//   void preorder(Process f, BinaryTreeNode<Item>*)
//     Precondition: node_ptr is a pointer to a node in a binary
//     tree (or node_ptr may be NULL to indicate the empty tree).
//     Postcondition: If node_ptr is non-NULL, then the function f
//     has been applied to the contents of *node_ptr and all of
//     its descendants, using a pre-order traversal.
//     Note: Process is the type of a function f which may be
//     called with a single Item argument. Item may be any type.
//
//   template <class Process, class Item>
//   void postorder(Process f, BinaryTreeNode<Item>*)
//     Same as the preorder function, except with a post-order traversal.
//
//   template <class Process, class Item>
//   void inorder(Process f, BinaryTreeNode<Item>*)
//     Same as the preorder function, except with an in-order traversal.
//
//   template <class Item, class SizeType>
//   void print(BinaryTreeNode<Item>* node_ptr, SizeType depth)
//     Precondition: node_ptr is a pointer to a node in a binary
//     tree (or node_ptr may be NULL to indicate the empty tree).
//     If the pointer is not NULL, then depth is the depth of
//     the node pointed to by node_ptr.
//     Postcondition: If node_ptr is non-NULL, then the contents
//     of *node_ptr and all its descendants have been written
//     to cout with the << operator, using a backward in-order
//     traversal. Each node is indented 4 times its depth.
//
//   template <class Item>
//   size_t tree_size(const BinaryTreeNode<Item>* root_ptr)
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Postcondition: The return value is the number of nodes in
//     the tree.
//
//   template <class Item>
//   void printTree (BinaryTreeNode<Item>* node_ptr);
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Postcondition: The complete tree is printed sideways to
//     provide an intuitive visual view.
//
//   template <class Item>
//   void insert (BinaryTreeNode<Item>* & root_ptr, Item Target);
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Target is expected NOT to be a value already in the tree.
//     Postcondition: The tree rooted at root_ptr is updated to
//     insert a node containing the Target value.  If Target
//     is already present, an error message is issued.
//
//   template <class Item>
//   void remove (BinaryTreeNode<Item>* & root_ptr, Item Target);
//     Note: delete is predefined, so we use the name "remove"
//     rather than "delete".
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Target is expected to be a value present in the tree.
//     Postcondition: The tree rooted at root_ptr is updated to
//     remove the node containing the Target value.  If Target
//     is not present, an error message is issued.
//
//   template <class Item>
//   BinaryTreeNode<Item>* reflect (const BinaryTreeNode<Item>* root_ptr);
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Postcondition: A mirror image of the tree rooted at root_ptr
//     is created with all new nodes (a la a deep copy) and returned.
//
//   template <class Item>
//   int height(const BinaryTreeNode<Item>* root_ptr);
//     Precondition: root_ptr is a pointer to a node in a binary
//     tree (or root_ptr may be NULL to indicate the empty tree).
//     Postcondition: The height of the tree is returned.


#ifndef BINTREE_H
#define BINTREE_H
#include <cstdlib>  // Provides NULL

    template <class Item>
    struct BinaryTreeNode
    {
        Item data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    template <class Item>
    BinaryTreeNode<Item>* create_node(
        const Item& entry,
        BinaryTreeNode<Item>* l_ptr = NULL,
        BinaryTreeNode<Item>* r_ptr = NULL
    );

    template <class Item>
    BinaryTreeNode<Item>* tree_copy(const BinaryTreeNode<Item>* root_ptr);

    template <class Item>
    void tree_clear(BinaryTreeNode<Item>*& root_ptr);

    template <class Item>
    bool is_leaf(const BinaryTreeNode<Item>& ptr);

    template <class Process, class Item>
    void preorder(Process f, BinaryTreeNode<Item>*);

    template <class Process, class Item>
    void inorder(Process f, BinaryTreeNode<Item>*);

    template <class Process, class Item>
    void postorder(Process f, BinaryTreeNode<Item>*);

    template <class Item>
    size_t tree_size(const BinaryTreeNode<Item>* root_ptr);

    template <class Item>
    void printTree (BinaryTreeNode<Item>* node_ptr);

    template <class Item>
    void insert (BinaryTreeNode<Item>* & root_ptr, Item Target);

    template <class Item>
    void remove (BinaryTreeNode<Item>* & root_ptr, Item Target);
    // delete is predefined, so we use the name "remove" rather than "delete".

    template <class Item>
    BinaryTreeNode<Item>* reflect (const BinaryTreeNode<Item>* root_ptr);

    template <class Item>
    int height(const BinaryTreeNode<Item>* root_ptr);

#include "bintreetemplate.h"
#endif