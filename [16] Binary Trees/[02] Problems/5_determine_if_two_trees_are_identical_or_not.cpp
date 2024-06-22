#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// DETERMINE IF TWO TREES ARE IDENTICAL OR NOT
// time complexity: O(n)
bool isIdentical(Node* root1, Node* root2) {
    // base cases
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        return false;

    // now both root1 & root2 are non-NULL
    bool left = isIdentical(root1 -> left, root2 -> left);
    bool right = isIdentical(root1 -> right, root2 -> right);

    bool value = root1 -> data == root2 -> data;

    if(left && right && value)
        return true;
    else 
        return false;
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;
    
    root1 = buildTree(root1);
    root2 = buildTree(root2); // 1 2 -1 -1 3 -1 -1

    if(isIdentical(root1, root2))
        cout << "both trees are identical" << endl;
    else 
        cout << "trees aren't identical" << endl;

    return 0;
}