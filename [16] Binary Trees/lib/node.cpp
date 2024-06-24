#include <iostream>
#include <queue>
using namespace std;

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};
