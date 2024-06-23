#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "../lib/build.cpp"
using namespace std;

// RIGHT VIEW OF BINARY TREE

// --- recursive approach ---
void rightViewRecursion(Node* root, vector<int> &ans, int level) {
    // base case
    if(root == NULL)
        return ;
    
    // entered in new level
    if(level == ans.size())
        ans.push_back(root -> data);

    rightViewRecursion(root -> right, ans, level + 1);
    rightViewRecursion(root -> left, ans, level + 1);
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 3 -1 -1 4 -1 7 -1 -1 5 -1 6 -1 8 -1 9 -1 -1

    vector<int> ans;
    rightViewRecursion(root, ans, 0); 
    
    cout << "right view of binary tree: ";
    for(auto i: ans)
        cout << i << " "; // 1 2 3 7 9
    cout << endl;

    return 0;
}