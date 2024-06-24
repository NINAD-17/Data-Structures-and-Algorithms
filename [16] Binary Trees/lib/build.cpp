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


Node* buildTree(Node* &root) {
    // initially the root is NULL
    int data;

    if(root == NULL)
        cout << "enter data for root node: ";
    else 
        cout << "enter data: ";
    cin >> data;
    cout << endl;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "-> enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "-> enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
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
