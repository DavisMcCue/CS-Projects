//0020267671
//Davis McCue


// FILE: bintreetemplate.h
// IMPLEMENTS: The nine template functions of the second version of the binary
// tree toolkit (see bintree.h for documentation). Note that this file is not
// compiled on its own. Instead, this file is included by an include directive
// at the bottom of bintree.h.

#include <cassert>    // Provides assert
#include <iomanip>   // Provides setw
#include <iostream>  // Provides cout
#include <cstdlib>    // Provides NULL, size_t

using namespace std;

// Programming note: Some compilers require that the default argument is
// listed in the implementation as well as the prototype, so we have
// include the default arguments for create_node.
template <class Item>
BinaryTreeNode<Item>* create_node(
    const Item& entry,
    BinaryTreeNode<Item>* l_ptr,
    BinaryTreeNode<Item>* r_ptr
)
{
    BinaryTreeNode<Item>* result_ptr;

    result_ptr = new BinaryTreeNode<Item>;
    result_ptr->data  = entry;
    result_ptr->left  = l_ptr;
    result_ptr->right = r_ptr;

    return result_ptr;
}

template <class Item>
BinaryTreeNode<Item>* tree_copy(const BinaryTreeNode<Item>* root_ptr)
// Library facilities used: stdlib.h
{
    BinaryTreeNode<Item> *l_ptr;
    BinaryTreeNode<Item> *r_ptr;

    if (root_ptr == NULL)
        return NULL;
    else
    {
        l_ptr = tree_copy(root_ptr->left);
        r_ptr = tree_copy(root_ptr->right);
        return create_node(root_ptr->data, l_ptr, r_ptr);
    }
}

template <class Item>
void tree_clear(BinaryTreeNode<Item>*& root_ptr)
{
    if (root_ptr != NULL)
    {
        tree_clear(root_ptr->left);
        tree_clear(root_ptr->right);
        delete root_ptr;
        root_ptr = NULL;
    }
}

template <class Item>
bool is_leaf(const BinaryTreeNode<Item>& node)
{
    return (node.left == NULL) && (node.right == NULL);
}

template <class Process, class Item>
void inorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        inorder(f, node_ptr->left);
        f(node_ptr->data);
        inorder(f, node_ptr->right);
    }
}

template <class Process, class Item>
void postorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        postorder(f, node_ptr->left);
        postorder(f, node_ptr->right);
        f(node_ptr->data);
    }
}

template <class Process, class Item>
void preorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        f(node_ptr->data);
        preorder(f, node_ptr->left);
        preorder(f, node_ptr->right);
    }
}

template <class Item>
size_t tree_size(const BinaryTreeNode<Item>* node_ptr)
// Library facilities used: stdlib.h
{
    if (node_ptr == NULL)
        return 0;
    else
        return 1 + tree_size(node_ptr->left) + tree_size(node_ptr->right);
}

//
//   template <class Item, class SizeType>
//   void printTreeAtDepth (BinaryTreeNode<Item>* node_ptr, SizeType depth)
//     Precondition: node_ptr is a pointer to a node in a binary
//     tree (or node_ptr may be NULL to indicate the empty tree).
//     If the pointer is NULL, then depth is expected to be 0.
//     If the pointer is not NULL, then depth is the depth of
//     the node pointed to by node_ptr.
//     Postcondition: If node_ptr is non-NULL, then the contents
//     of *node_ptr and all its descendants have been written
//     to cout with the << operator, using a backward in-order
//     traversal. Each node is indented 4 times its depth.
template <class Item, class SizeType>
void printTreeAtDepth (BinaryTreeNode<Item>* node_ptr, SizeType depth)
// Library facilities used: iomanip.h, iostream.h, stdlib.h
{
    if (node_ptr != NULL)
    {
        printTreeAtDepth (node_ptr->right, depth+1);
        cout << setw(4*depth) << ""; // Indent 4*depth spaces
        cout << node_ptr->data << endl;
        printTreeAtDepth (node_ptr->left, depth+1);
    }
}

template <class Item>
void printTree(BinaryTreeNode<Item>* node_ptr)
{
    printTreeAtDepth (node_ptr, 0);
}

template <class Item>
void insert(BinaryTreeNode<Item>*& root_ptr, Item Target)
{
    //if root_ptr == null then call create a node with the target
    if (root_ptr == NULL)
    {
        root_ptr = create_node(Target);
    }
    else //else
    {
        //if root_ptr data is greater then Target
        if (root_ptr->data > Target)
        {
            //enter here
            insert(root_ptr->left, Target);
        }
        else // else (less then)
        {
            //enter here
            insert(root_ptr->right, Target);
        }
    }
}

template <class Item>
void remove(BinaryTreeNode<Item>*& root_ptr, Item Target)
// delete is predefined, so we use the name "remove" rather than "delete".
{
    //if root_ptr == null
    if (root_ptr == NULL)
    {
        //print empty tree
        cout << "Error Empty Tree" << endl;
    }
    //if target is less then the root_ptr->data
    if (Target < root_ptr->data)
    {
        //enter here
        //calls remove on the root_ptr->left with the target
        remove(root_ptr->left, Target);
    }
    else if (Target > root_ptr->data)
    {
        //enter here
        //calls remove on the root_ptr->right with the target
        remove(root_ptr->right, Target);
    }
    else
    {
        // ------------- case 1 ------------------------------
        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            root_ptr = NULL;
            delete(root_ptr);
        }
        //-------------- case 2 ------------------------------
        else if (root_ptr->right == NULL)
        {
            //if the right side is null then cycle through the left deleting a node
            BinaryTreeNode<int>* ptr_holder = root_ptr;
            root_ptr = root_ptr->left;
            ptr_holder = NULL;
            delete ptr_holder;
        }

        else if (root_ptr->left == NULL)
        {
            //if the left side is null then cycle through the right deleting a node
            BinaryTreeNode<int>* ptr_holder = root_ptr;
            root_ptr = root_ptr->right;
            ptr_holder = NULL;
            delete ptr_holder;
        }
        //------------- case 3 ------------------------------
        else
        {
            //use a helper function I created to find if the tree is empty after it deletes a node one by one 
            //makes sure that the left subtree is fully empty before going to the right subtree
            BinaryTreeNode<int>* Save = RemoveHelper(root_ptr->right);
            root_ptr->data = Save->data;
            remove(root_ptr->right, Save->data);
        }
    }
}
template <class Item>
BinaryTreeNode<Item>* RemoveHelper(BinaryTreeNode<Item>*& root_ptr)
{
    if (root_ptr == NULL)
    {
        cout << "Error Empty Tree" << endl;
    }
    if (root_ptr->left != NULL)
    {
        return RemoveHelper(root_ptr->left);
    }
    return root_ptr;
}

template <class Item>
BinaryTreeNode<Item>* reflect(const BinaryTreeNode<Item>* root_ptr)
{
    //variables
    BinaryTreeNode<Item>* leftside = new BinaryTreeNode<Item>;
    BinaryTreeNode<Item>* rightside = new BinaryTreeNode<Item>;

    //if root_ptr == null return
    if (root_ptr == NULL)
    {
        return NULL;
    }
    //else
    else
    {
        //store the left node of the rootptr in leftside that points to the right side 
        leftside->right = reflect(root_ptr->left);
        //store the right node of the rootptr in rightside that points to the left side 
        rightside->left = reflect(root_ptr->right);
        //then returns the root_ptr and its data along with the leftside and rightside
        return create_node(root_ptr->data, leftside, rightside);
    }
}

template <class Item>
int height(const BinaryTreeNode<Item>* root_ptr)
{
    //if root_ptr == null return
    if (root_ptr == NULL)
    {
        return 0;
    }
    else //else
    {
        //return the max + 1 for each time height is called from either looking at the left or the right subtree's
        return max(height(root_ptr->left), height(root_ptr->right)) + 1;
    }
}
