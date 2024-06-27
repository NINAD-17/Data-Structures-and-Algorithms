#include <bits/stdc++.h>
#include "../../[16] Binary Trees/lib/build.cpp"
using namespace std;

// IS BINARY TREE HEAP?
// conditions to check:
//      - is it's a complete binary tree
//      - is it satisfy properties of max heap

int countNodes(Node* root) {
    // base case
    if(root == NULL) 
        return 0;

    int ans = 1 + countNodes(root -> left) + countNodes(root -> right); // root + left + right
    return ans;
}

bool isCBT(Node* root, int index, int totalCount) {
    // base case
    if(root == NULL)
        return true;

    if(index >= totalCount) // as in CBT all levels are filled except last and also nodes should be added from left. this condition is false when some nodes aren't present in middle
        return false;
    else {
        bool left = isCBT(root -> left, 2 * index + 1, totalCount);
        bool right = isCBT(root -> right, 2 * index + 2, totalCount);
        return left && right;
    }
}

bool isMaxOrder(Node* root) {
    // 1. base case: leaf node
    if(root -> left == NULL && root -> right == NULL)
        return true;

    // 2. only left node exist (as it's a CBT, it doesn't contain only right node)
    if(root -> right == NULL)
        return (root -> data > root -> left -> data);
    else {
    // 3. both child exists
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        if(left && right && (root -> data > root -> left -> data) && (root -> data > root -> right -> data))
            return true;
        else
            return false;
    }
}

bool isHeap(Node* root) {
    int index = 0; // current index
    int totalCount = countNodes(root); // total nodes

    if(isCBT(root, index, totalCount) && isMaxOrder(root)) // if isCBT() is false then it will not execute isMaxOrder() as the answer is false anyway.
        return true;
    else
        return false;
}

int main() {

    Node* root = NULL;
    root = buildTree(root);
    // EX- non-CBT: 60 50 45 -1 -1 -1 53 -1 52 -1 -1
    // EX- no-maxHeap: 60 50 45 -1 -1 49 -1 -1 53 54 -1 -1 -1
    // correct: 60 50 45 -1 -1 -1 53 -1 -1

    levelOrderIteratively(root); cout << endl;

    if(isHeap(root))
        cout << "yes, the given binary tree is heap" << endl;
    else
        cout << "no, the given binary tree isn't a heap" << endl;

    return 0;
}