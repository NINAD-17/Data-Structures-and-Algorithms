#include <iostream>
#include <vector>
#include "../lib/build.cpp"
using namespace std;

// LOWEST COMMON ANCESTOR OF BST

// iterative
Node* lowestCommonAncestorInBST_iteratively(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    while(root != NULL) {
        if(root -> data < n1 && root -> data < n2)
            root = root -> right;
        else if(root -> data > n1 && root -> data > n2)
            root = root -> left;
        else
            return root;
    }
}

// recursive
Node* lowestCommonAncestorInBST(Node* root, int n1, int n2) {
    // base case
    if(root == NULL)
        return NULL;

    // both nodes are lies in right part of sub-tree
    if(root -> data < n1 && root -> data < n2)
        return lowestCommonAncestorInBST(root -> right, n1, n2);

    // both nodes are lies in left part of sub-tree
    if(root -> data > n1 && root -> data > n2)
        return lowestCommonAncestorInBST(root -> left, n1, n2);

    return root; // if(root -> data < n1 && root -> data > n2) || (root -> data > n1 && root -> data < n2));
}

int main() {

    Node* root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root);

    levelOrderIteratively(root);

    cout << endl;
    
    
    return 0;
}