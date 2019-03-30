/* BST.cpp */

#include "BST.h"
#include <iostream>
#include <cassert>

using namespace std;

// Desc: Default constructor (empty tree)
BST::BST() {
    root = NULL;
} // constructor

// Desc: Import tree
BST::BST(BTnode *root) {
    this->root = root;
} // constructor

// Desc: Insert key into the BST
// Note: This is the wrapper method which is called
//       by the client code (main.ccp) and which
//       calls the private helper (recursive) method insertH().
void BST::insert(int key) {
    root = insertH(root, key);
} // insert

// Desc: Helper function for insert(key)
BTnode * BST::insertH(BTnode *tree, int key) {
    // base
    if (tree == NULL) {
        BTnode * newnode = new BTnode(key, NULL, NULL, NULL);
        return newnode;
    }

    if (key <= tree->key) {
        // left
        tree->left = insertH(tree->left, key);
        assert(tree->left);
        tree->left->parent = tree;
    } else {
        // right
        tree->right = insertH(tree->right, key);
        tree->right->parent = tree;
    }

    return tree;

} // insertH

// Desc: Input a tree
//  Pre: The input stream contains a sequence of integers ending
//       in eof, or the result is indeterminate
istream & operator>>(istream & is, BST& rhs) {
    while (is) {
        int key;

        is >> key;

        if (is) {
            rhs.insert(key);
        }
    }

    return is;
} // operator >>

// Desc: Output a tree
ostream & operator<<(ostream & os, const BST& rhs) {
    if (!rhs.root) return os;

    os << "[" << rhs.root->key;

    if (rhs.root->left) {
        os << " L" << BST(rhs.root->left);
    }
    if (rhs.root->right) {
        os << " R" << BST(rhs.root->right);
    }
    os << "]";
    return os;
} // operator <<

// Desc: Prints the highest 5 keys of the BST in decreasing order.
//       Keys are presented in descending order in a space-separated
//       list, ending with a newline.
void BST::top5() const 
{
    int counter = 0;
    // Base case
    if (root == NULL)
    {
        return;
    }
    else
    {
        highestValue(root->right, counter);
        if (counter < 5)
        {

            cout << root->key << " ";
            counter++;
        }
        highestValue(root->left, counter);
    }

    cout << endl;
    
} // top5

void BST::highestValue(BTnode *root, int& c) const
{
    BTnode *nodePtr = root;
    
    // Base case
    if (c >= 5)
    {
        return;
    }
    // If BST is a leaf
    else if (nodePtr->left == NULL && nodePtr->right == NULL)
    {
        cout << nodePtr->key << " ";
        c++;
    }
    // If BST only has a left subtree
    else if (nodePtr->right == NULL)
    {
        cout << nodePtr->key << " ";
        c++;

        nodePtr = nodePtr->left;
        highestValue(nodePtr, c);
        nodePtr = nodePtr->parent;
        if (c < 5)
        {
            cout << nodePtr->key << " ";
            c++;
        }
        
    }
    // If BST has a right subtree
    else
    {
        nodePtr = nodePtr->right;
        highestValue(nodePtr, c);
        nodePtr = nodePtr->parent;
        if (c < 5)
        {
            cout << nodePtr->key << " ";
            c++;
        }
       
    }

}
