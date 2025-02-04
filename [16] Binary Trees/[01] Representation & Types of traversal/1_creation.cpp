#include <iostream>
#include <queue>
#include <stack>
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

// --- creation: recursive way ---
// time complexity: O(n) because we're visiting each node once.
// space complexity: O(h) where h = height
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

// --- creation: iterative way ---
// in this code we add nodes level wise
// time complexity: O(n) we’re visiting each node once.
// space complexity: O(w), where w is the maximum width of the tree
Node* buildTreeIteratively(Node* &root) {
    // create a queue to store the nodes
    queue<Node*> q;

    int data;
    cout << "enter data for root node: ";
    cin >> data;

    if(data != -1) {
        root = new Node(data);
        q.push(root);
    }

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        cout << "enter left child of " << front -> data << ": ";
        cin >> data;
        
        if(data != -1) {
            front -> left = new Node(data);
            q.push(front -> left);
        }

        cout << "enter right child of " << front -> data << ": ";
        cin >> data;

        if(data != -1) {
            front -> right = new Node(data);
            q.push(front -> right);
        }
    }

    return root;
}

// --- level order traversal (breadth first search) ---
// 1. using queue
// time Complexity: O(n), where n is the number of nodes.
// space Complexity: O(n), in the worst case, if the tree is a complete binary tree, there will be n/2 nodes at the last level, which will be added to the queue.
void levelOrderTraversal(Node* &root) {
    if(root == NULL) {
        cout << "tree doesn't exist :(" << endl;
        return;
    }

    cout << "\n--- printing binary tree with level order traversal ---\n";

    // create a queue to store level wise nodes
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty())
                q.push(NULL); // when any 
        } else {
            cout << front -> data << " ";

            if(front -> left) 
                q.push(front -> left);
            
            if(front -> right)
                q.push(front -> right);
        }
    }
}

// 2. using height (recursive)
// time Complexity: O(n^2) in the worst case (when the tree is skewed). This is because for each level (and there are n levels for a skewed tree), we might end up traversing all nodes of the tree.
// space Complexity: O(h), where h is the height of the tree. This is due to the recursive call stack.
int height(Node* node) {
    if(node == NULL) 
        return 0;
    
    int leftHeight = height(node -> left);
    int rightHeight = height(node -> right);

    return max(leftHeight, rightHeight) + 1;
}

void printCurrentLevel(Node* root, int level) {
    if(root == NULL)
        return ;
    else if(level == 0)
        cout << root -> data << " ";
    else if(level > 0) {
        printCurrentLevel(root -> left, level - 1);
        printCurrentLevel(root -> right, level - 1);
    } 
}

void levelOrderTraversal_ByHeight(Node* &root) {
    int h = height(root);
    for(int level = 0; level < h; level++) {
        printCurrentLevel(root, level);
        cout << endl;
    }
}

// --- reverse level order traversal ---
// 1. using height
void reverseOrderTraversal_ByHeight(Node* &root) {
    int h = height(root);
    for(int level = h - 1; level >= 0; level--) {
        printCurrentLevel(root, level);
        cout << endl;
    }
}

// 2. using queue and stack
// time complexity: O(n)
// space complexity: O(n)
void reverseOrderTraversal(Node* root) {
    if(root == NULL) {
        cout << "root is NULL" << endl;
        return ;
    }

    cout << "\nprinting reverse order traversal";

    stack<Node*> st;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        st.push(front);

        if(front == NULL) {
            if(!q.empty()) // avoiding memory leak: otherwise it will push null to last position and it will stuck in an infinite loop
                q.push(NULL);
            continue;
        } 
        
        if(front -> right)
            q.push(front -> right);

        if(front -> left) 
            q.push(front -> left);
        
    }

    while(!st.empty()) {
        if(st.top() == NULL) {
            cout << endl;
        } else {
            cout << st.top() -> data << " ";
        }
        st.pop();
    }
}

int main() {
    Node* root = NULL;

    root = buildTree(root); // input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // root = buildTreeIteratively(root); // input: 1 2 5 3 4 -1 6 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);
    // levelOrderTraversal_ByHeight(root);

    reverseOrderTraversal(root);

    return 0;
}