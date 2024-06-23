#include <iostream>
#include <vector>
#include <queue>
#include "../lib/build.cpp"
using namespace std;

// BOUNDARY TRAVERSAL
// time complextiy: O(n)
// space complexity: O(n)

// traverse left side
void traverseLeft(Node* root, vector<int> &ans) {
    // if root is null or node is a leaf node
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return ;

    ans.push_back(root -> data);

    if(root -> left)
        traverseLeft(root -> left, ans);
    else
        traverseLeft(root -> right, ans);
}

// traverse all leaf nodes
void traverseLeaf(Node* root, vector<int> &ans) {
    // base case
    if(root == NULL)
        return;
    
    // if node is a leaf node
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data); 
        return;
    }

    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

// traverse right side
void traverseRight(Node* root, vector<int> &ans) {
    // base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return;
    
    if(root -> right) 
        traverseRight(root -> right, ans);
    else 
        traverseRight(root -> left, ans);

    // comming back from leaf node
    ans.push_back(root -> data); 
}

vector<int> boundary(Node* root) {
    vector<int> ans;
    
    if(root == NULL)
        return ans;

    ans.push_back(root -> data);

    // step 1: store left part's nodes
    traverseLeft(root -> left, ans);

    // step 2: store all leaf nodes
    //      1. left part
    traverseLeaf(root -> left, ans);

    //      2. right part
    traverseLeaf(root -> right, ans);

    // step 3: store right part's nodes
    traverseRight(root -> right, ans);

    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

    vector<int> ans = boundary(root);
    cout << "boundary traversal: ";
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}