#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "../lib/build.cpp"
using namespace std;

// VERTICAL TRAVERSAL OF BINARY TREE

vector<int> verticalOrder(Node* root) {
    map<int, map<int, vector<int>>> nodes; // map <horizontal distance map<level, vector<nodes>>>
    queue<pair<Node*, pair<int, int>>> q; // queue <pair <node, pair<horizontal distance, level>>>
    vector<int> ans;

    if(root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_dist = temp.second.first;
        int level = temp.second.second;

        nodes[horizontal_dist][level].push_back(frontNode -> data);

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, make_pair(horizontal_dist - 1, level + 1)));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode->right, make_pair(horizontal_dist + 1, level + 1)));
    }

    for(auto i: nodes) {
        for(auto j: i.second) {
            for(auto k: j.second)
                ans.push_back(k);
        }
    }
    
    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    levelOrderIteratively(root);
    cout << endl;

    vector<int> ans = verticalOrder(root);
    cout << "vertical order: ";
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}