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

// time complexity of insertion is O(log n)
// it's similar to binary search. we're ignoring 1 part to get correct position.
Node* insertIntoBST(Node* root, int data) {
    // base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }


    if(data > root -> data) {
        // insert in right part
        root -> right = insertIntoBST(root -> right, data);
    } else {
        // insert in left part
        root -> left = insertIntoBST(root -> left, data);
    }

    cout << root -> data << " ";
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        // Node* root = insertIntoBST(root, data); // wrong code: segmentation fault:
        //              Explaination: The segmentation fault occurs because of incorrect memory access. When you create a new node using new Node(data), it allocates memory for the new node. However, if you reassign the root pointer inside the loop, you lose track of the original memory location, leading to undefined behavior.
        
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// level order traversals
void levelOrderIteratively(Node* &root) {
    cout << "\n--> level order traversal \n";

    queue<Node*> q;

    if(root != NULL) {
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // cout << temp -> data << " ";

        if(temp == NULL) {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        } else {
            cout << temp -> data << " ";

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

int main() {

    Node* root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root);

    // print binary search tree with level order traversal
    levelOrderIteratively(root);

    return 0;
}