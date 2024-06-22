#include <iostream>
#include <queue>
#include "../lib/build.cpp"
using namespace std;

// COUNT LEAF NODES
// time complexity: O(n)
// space complexity: O(n)

// 1. using level order traversal
int cntLeafNodes(Node* &root) {
    // root is NULL
    if(root == NULL)
        return 0;

    // create a queue to store all the nodes level wise
    queue<Node*> q;
    q.push(root); // push root node in queue

    // count to store leaf node counts
    int count = 0;

    while(!q.empty()) {
        int tempCnt = 0;
        Node* temp = q.front();
        q.pop();

        if(temp -> left) {
            q.push(temp -> left);
            tempCnt++;
        }

        if(temp -> right) {
            q.push(temp -> right);
            tempCnt++;
        }

        if(tempCnt == 0) // it means both left and right are NULL means it's leaf node
            count++;
    }

    return count;
}

// 2. using inorder traversal
void cntLeafNodesInorder(Node* &root, int &count) {
    // root is null
    if(root == NULL)
        return;

    cntLeafNodesInorder(root -> left, count);

    // check for leaf node
    if(root -> left == NULL && root -> right == NULL)
        count++;

    cntLeafNodesInorder(root -> right, count);
}

// 3. other method using preorder traversal
int allLeafNodes(Node* &root) {
    if(root == NULL)
        return 0;

    if(root -> left == NULL && root -> right == NULL)
        return 1;

    int leftCnt = allLeafNodes(root -> left);
    int rightCnt = allLeafNodes(root -> right);
    
    return leftCnt + rightCnt;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // i/p: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    cout << "total leaf nodes present in binary tree: " << cntLeafNodes(root) << endl;

    int count = 0;
    cntLeafNodesInorder(root, count);
    cout << "total leaf nodes using inorder: " << count << endl;
    cout << "total leaf nodes using preorder: " << allLeafNodes(root) << endl;

    return 0;
}