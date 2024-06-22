#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// SUM TREE
// time complexity: O(n)
// space complexity: O(n)

pair<int, bool> isSumTree(Node* root) {
    // base case
    if(root == NULL)
        return make_pair(0, true);

    if(root -> left == NULL && root -> right == NULL)
        return make_pair(root -> data, true);

    pair<int, bool> leftAns = isSumTree(root -> left);
    pair<int, bool> rightAns = isSumTree(root -> right);

    bool left = leftAns.second;
    bool right = rightAns.second;
    bool condn = root -> data == leftAns.first + rightAns.first;

    pair<int, bool> ans;
    if(left && right && condn) {
        ans.second = true;
        ans.first = 2 * (root -> data); // root -> data + left.first + right.first
    } else {
        ans.second = false;
    }

    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 20 6 3 -1 -1 3 -1 -1 4 3 -1 -1 1 -1 -1

    pair<int, bool> ans = isSumTree(root);
    cout << ans.first << endl;
    if(ans.second)
        cout << "given tree is a sum tree" << endl;
    else 
        cout << "given tree isn't a sum tree" << endl;

    return 0;
}