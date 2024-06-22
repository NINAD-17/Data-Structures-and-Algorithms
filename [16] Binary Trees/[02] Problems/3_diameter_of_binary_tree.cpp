#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// DIAMETER (WIDTH) OF BINARY TREE
// Diameter is a longest path between two end nodes. End node can be a leaf node or a root node.
// To find solution we've 3 options:
//      1. find diameter of left tree
//      2. find diameter of right tree
//      3. find height of both tree (left and right)

// time complexity: O(n^2) // as we're calling height() from diameter() both have O(n) complexity
// space complexity:
int height(Node* &root) {
    // base case
    if(root == NULL)
        return 0;

    int leftNode = height(root -> left);
    int rightNode = height(root -> right);

    return max(leftNode, rightNode) + 1;
}

int diameter(Node* &root) {
    // base case
    if(root == NULL)
        return 0;

    int op1 = diameter(root -> left); // find longest diameter in left side of tree
    int op2 = diameter(root->right);  // find longest diameter in right side of tree
    int op3 = height(root -> left) + height(root -> right) + 1; // find longest diameter present in combination of both left and right part of tree

    int ans = max(op1, max(op2, op3));
    return ans;
}

// --- optimized solution ---
// pair<diameter, height> therefore we remove height()
// time complexity: O(n)
// space complexity: O(h) ... h is height
pair<int, int> diameterFast(Node* &root) {
    // base case
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);

    int op1 = left.first; // accessing diameter
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    // store answer
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3)); // store diameter
    ans.second = max(left.second, right.second) + 1; // store height

    return ans;
}

int diameter_optimized(Node* &root) {
    return diameterFast(root).first;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    cout << "diameter of binary tree is " << diameter(root) << endl;
    cout << "diameter of binary tree is " << diameter_optimized(root) << endl;

    return 0;
}