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

Node* insertInBST(Node* root, int data) {
    // base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    // left call and right call
    if(data < root -> data)
        root -> left = insertInBST(root -> left, data);
    else
        root -> right = insertInBST(root -> right, data);
    
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertInBST(root, data);
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