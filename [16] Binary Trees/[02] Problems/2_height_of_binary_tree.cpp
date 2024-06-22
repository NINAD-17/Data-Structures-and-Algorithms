#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// HEIGHT OF BINARY TREE
// height is the longest path between root node and leaf node

// time complexity: O(n)
// space complexity: O(h) // for skew tree it's O(n)
int heightOfBinTree(Node* &root) {
    if(root == NULL)
        return 0;

    int leftNode = heightOfBinTree(root -> left);
    int rightNode = heightOfBinTree(root -> right);

    return max(leftNode, rightNode) + 1;
}

int main() {
    Node* root = NULL;
    root = buildTree(root); 
    // input 3 levels: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    // intput 4 levels: 1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 -1

    cout << "height of binary tree is " << heightOfBinTree(root) << " levels" << endl;

    return 0;
}