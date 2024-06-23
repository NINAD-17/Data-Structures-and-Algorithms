#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "../lib/build.cpp"
using namespace std;

// TOP VIEW OF BINARY TREE
vector<int> topView(Node* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;
    
    map<int, int> topNode; // contains mapping of horizontal dist. and top node
    queue<pair<Node*, int>> q; // contains pair of node and horizontal dist

    q.push(make_pair(root, 0)); // 0 is the root's horizontal dist.

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_dist = temp.second;

        // if one value present for a horizontal_dist then do nothing.
        if(topNode.find(horizontal_dist) == topNode.end()) // find tries to find corresponding entry for horizontal_dist if it can't find then it's equal to topNode.end()
            topNode[horizontal_dist] = frontNode -> data;
        

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, horizontal_dist - 1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, horizontal_dist + 1));
    }

    for(auto i: topNode) {
        ans.push_back(i.second);
    }

    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans = topView(root); // 1 2 4 -1 8 9 10 -1 -1 -1 -1 5 -1 -1 3 -1 7 -1 -1
    cout << "top view of binary tree: ";
    for(auto i: ans)
        cout << i << " "; // 10 4 2 1 3 7
    cout << endl;

    return 0;
}