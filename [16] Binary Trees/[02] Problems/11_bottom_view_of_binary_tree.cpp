#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "../lib/build.cpp"
using namespace std;

// BOTTOM VIEW OF BINARY TREE
vector<int> bottomView(Node* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;

    map<int, int> bottomNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_dist = temp.second;

        bottomNode[horizontal_dist] = frontNode -> data;

        if(frontNode -> left) 
            q.push(make_pair(frontNode -> left, horizontal_dist - 1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, horizontal_dist + 1));
    }

    for(auto i: bottomNode)
        ans.push_back(i.second);

    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans = bottomView(root); // 1 2 4 -1 8 9 10 -1 -1 -1 -1 5 -1 -1 3 -1 7 -1 -1
    cout << "bottom view of binary tree: ";
    for(auto i: ans)
        cout << i << " "; // 10 9 8 5 3 7
    cout << endl;

    return 0;
}