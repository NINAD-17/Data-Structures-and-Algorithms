#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// LOWEST COMMON ANCESTOR IN BINARY TREE
// time complexity: O(n)
// space complexity: O(h)

Node* lowestCommonAncestor(Node* root, int n1, int n2) {
    // base case
    if(root == NULL)
        return NULL;

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node* leftAns = lowestCommonAncestor(root -> left, n1, n2);
    Node* rightAns = lowestCommonAncestor(root -> right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
        return root;
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

int main() {
    Node* root = NULL;
    root = buildTree(root); // input: 4 -1 10 5 4 7 -1 -1 8 12 -1 -1 9 -1 -1 3 22 -1 -1 27 29 -1 -1 -1 -1 
    levelOrderIteratively(root);

    int n1 = 8;
    int n2 = 27;

    cout << "\nlowest common ancestor of " << n1 << " & " << n2 << " is " << lowestCommonAncestor(root, n1, n2) -> data << endl;
    return 0;
}