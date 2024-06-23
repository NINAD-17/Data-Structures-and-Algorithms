#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "../lib/build.cpp"
using namespace std;

// LEFT VIEW OF BINARY TREE

// -- recursive approach
void leftViewRecursion(Node* root, vector<int> &ans, int level) {
    // base case
    if(root == NULL)
        return ;
    
    // entered in new level
    if(level == ans.size())
        ans.push_back(root -> data);

    leftViewRecursion(root -> left, ans, level + 1);
    leftViewRecursion(root -> right, ans, level + 1);
}

// 1. level order with iterative approach and level count
vector<int> leftViewUsingLevelCount(Node* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;

    queue<pair<Node*, int>> q; // queue contains a node and it's level
    q.push(make_pair(root, 1)); // you can use {root, 1} as well instead of make_pair

    int maxLevel = 0;

    while(!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();

        Node* frontNode = front.first;
        int level = front.second;

        if(level > maxLevel) {
            ans.push_back(frontNode -> data);
            maxLevel = level;
        }

        if(frontNode -> left)
            q.push({frontNode -> left, level + 1});
        
        if(frontNode -> right)
            q.push({frontNode -> right, level + 1});
    }

    return ans;
}

// 2. first code
vector<int> leftViewUsingLevelOrderTraversal(Node* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root -> data);

    bool isFirstNode = false;

    while(!q.empty()) {
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL) {
            isFirstNode = true;
            if(!q.empty())
                q.push(NULL);
            continue;
        }

        if(isFirstNode) {
            ans.push_back(frontNode -> data);
            isFirstNode = !isFirstNode;
        }

        if(frontNode -> left)
            q.push(frontNode -> left);
        
        if(frontNode -> right)
            q.push(frontNode -> right);
    }

    return ans;
}


int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 3 -1 -1 4 -1 7 -1 -1 5 -1 6 -1 8 -1 9 -1 -1

    vector<int> ans = leftViewUsingLevelCount(root); 
    cout << "left view of binary tree: ";
    for(auto i: ans)
        cout << i << " "; // 1 2 3 7 9
    cout << endl;

    vector<int> ansRec;
    leftViewRecursion(root, ansRec, 0);
    for(auto i: ansRec)
        cout << i << " "; // 1 2 3 7 9
    cout << endl;

    return 0;
}