#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// INORDER PREDECESSOR AND SUCCESSOR FOR A GIVEN KEY IN BST
// maximum value in left sub-tree is predecessor // root node is the key
// minimum value in right sub-tree is successor // root node is the key

void findPreSucc_iteratively(Node* root, Node* &predecessor, Node* &successor, int key) {
    // set predecessor and successor NULL initially
    predecessor = NULL;
    successor = NULL;

    Node* temp1 = root;
    while(temp1) {
        if(temp1 -> data > key) {
            successor = temp1;
            temp1 = temp1 -> left;
        } else 
            temp1 = temp1 -> right;
    }

    Node* temp2 = root;
    cout << "temp2: ";
    while(temp2) {
        cout << temp2 -> data << " ";
        if(temp2 -> data < key) {
            cout << " true ";
            predecessor = temp2;
            temp2 = temp2 -> right;
        } else 
            temp2 = temp2 -> left;
    }
    cout << endl << endl;

    return;
}

void findPreSucc(Node* root, Node* &predecessor, Node* &successor, int key) {
    // base case: NULL root don't have any predecessor and successor
    if(root == NULL)
        return ;

    // case 1: key found
    if(root -> data == key) {
        // maximum value in left sub-tree is predecessor
        if(root -> left != NULL) {
            Node* temp = root -> left;
            while(temp -> right != NULL) 
                temp = temp -> right;
            predecessor = temp;
        }

        // minimum value in right sub-tree is the successor
        if(root -> right != NULL) {
            Node* temp = root -> right;
            while(temp -> left != NULL) 
                temp = temp -> left;
            successor = temp;
        }

        return; // you got successor and predecessor for given key so return
    }

    // case 2: key is smaller than root && case 3: key is greater than root
    if(root -> data > key) {
        // successor = root;
        findPreSucc(root -> left, predecessor, successor, key);
    } else {
        // predecessor = root;
        findPreSucc(root -> right, predecessor, successor, key);
    }
}

int main() {

    Node* root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root); // 21 10 50 5 15 40 60 30 45 55 70 -1

    levelOrderIteratively(root);
    cout << endl;

    int key = 50;
    Node* predecessor = NULL;
    Node* successor = NULL;

    findPreSucc_iteratively(root, predecessor, successor, key);
    if(predecessor != NULL) 
        cout << "predecessor of " << key << " is " << predecessor -> data << endl;
    else
        cout << "no predecessor" << endl;
    
    if(successor)
        cout << "successor of " << key << " is " << successor -> data << endl;
    else
        cout << "no successor" << endl;

    return 0;
}