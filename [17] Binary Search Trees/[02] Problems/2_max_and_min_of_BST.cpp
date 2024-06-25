#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// maximum node of BST is always at the last right element
int findMaxOfBST(Node* &root) {
    Node* temp = root;

    while(temp -> right != NULL)
        temp = temp -> right;

    return temp -> data;
}

// minimum node of BST is always at the last left element
int findMinOfBST(Node* &root) {
    Node* temp = root;

    while(temp -> left != NULL)
        temp = temp -> left;
    
    return temp -> data;
}

int main() {

    Node* root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root);

    levelOrderIteratively(root);

    cout << endl;
    cout << "max node of BST is " << findMaxOfBST(root) << endl;
    cout << "min node of BST is " << findMinOfBST(root) << endl;

    return 0;
}