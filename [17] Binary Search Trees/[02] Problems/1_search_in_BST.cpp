#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// ------------- Iterative way -----------------
// Time Complexity: O(log n) on average (balanced tree), O(n) in the worst case (skewed tree).
// Space Complexity: O(1) (constant space)
bool searchInBST_iterative(Node* &root, int data) {
    Node* tempNode = root;

    while(tempNode != NULL) {
        if(tempNode -> data == data)
            return true; // data found in BST
        
        if(tempNode -> data > data) 
            tempNode = tempNode -> left;
        else 
            tempNode = tempNode -> right;
    }

    return false; // data not found in BST
}

// ------------- Recursive way -----------------
// TLE
// time complexity for balanced tree (average case): O(log n) 
// time complexity for un-balanced / skew tree (worst case):  O(h) and if it's a skew tree then O(n)
// space complexity: same as time complexity
bool searchInBST(Node* &root, int data) {
    // base case
    if(root == NULL)
        return false;

    if(data == root -> data)
        return true;
    else if(data < root -> data) 
        return searchInBST(root -> left, data);
    else
        return searchInBST(root -> right, data);
}

int main() {
    Node *root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root); // 21 10 50 5 15 40 60 55 70 -1

    // print binary search tree with level order traversal
    levelOrderIteratively(root);

    // search in BST
    int data = 15;

    if(searchInBST_iterative(root, data))
        cout << "element found in BST" << endl;
    else
        cout << "element not found in BST" << endl;

    return 0;
}