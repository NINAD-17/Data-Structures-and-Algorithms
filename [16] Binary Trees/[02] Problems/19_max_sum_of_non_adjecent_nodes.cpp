#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// MAXIMUM SUM OF NON-ADJECENT NODES

pair<int, int> solve(Node* root) {
    // base case
    if(root == NULL)
        return (make_pair(0, 0));

    pair<int, int> leftAns = solve(root -> left);
    pair<int, int> rightAns = solve(root -> right);

    pair<int, int> result;

    // include current node
    result.first = root -> data + leftAns.second + rightAns.second;

    // exclude current node
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return result;
}

int getMaxSum(Node* root) {
    pair<int, int> ans = solve(root); // 1st int means include and 2nd int means exclude

    return max(ans.first, ans.second); // max sum between including current node and by excluding current node
}

int main() {
    

    return 0;
}