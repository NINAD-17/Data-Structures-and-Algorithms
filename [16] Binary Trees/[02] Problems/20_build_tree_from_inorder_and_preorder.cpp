#include <iostream>
#include <map>
#include "../lib/node.cpp"
using namespace std;

// CONSTRUCT TREE FROM INORDER AND PREORDER TRAVERSAL
// (*hard question)

// algorithm: 
//      1. take index element as a root (from preorder)
//      2. find root element's position in an inorder
//      3. call left recursion from inorderStart to pos - 1 
//      4. call right recursion from pos + 1 to inorderEnd


// unoptimized for loop: each time this function will call so time complexity is O(n) for this function and that's why overall time complexity is O(n^2)
// int findPosition(int *inorder, int element, int n) {
//     for(int i = 0; i < n; i++) {
//         if(inorder[i] == element)
//             return i;
//     }
//     return -1;
// }

// instead use map // in this optimized version overall time complexity is O(n)
void createMapping(int *inorder, map<int, int> &nodeToIndex, int n) {
    for(int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i;
    }
}

Node* solve(int *inorder, int *preorder, int &preorderIndex, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
    // base case: preorderIndex traversed all over preorder array elements
    if(preorderIndex >= n || inorderStart > inorderEnd) // n is the preorder array's size: means all elements are traversed
        return NULL;

    int element = preorder[preorderIndex]; // it's a preorder's element. it's a root element
    Node* root = new Node(element); // root Node

    // find position of element
    // int pos = findPosition(inorder, element, n); (*unoptimized version) // n is the size of preorder and inorder array: i.e total nodes
    int pos = nodeToIndex[element]; // it finds the element index from inorder array

    // recursive calls
    preorderIndex++; // update preorder's index

    // call for left sub-tree
    root -> left = solve(inorder, preorder, preorderIndex, inorderStart, pos - 1, n, nodeToIndex);

    // call for right sub-tree 
    root -> right = solve(inorder, preorder, preorderIndex, pos + 1, inorderEnd, n, nodeToIndex);

    return root;
}

Node* buildTree(int *inorder, int *preorder, int n) {
    int preorderIndex = 0; // first index of preorder

    // create nodes to index map
    map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);

    Node* ans = solve(inorder, preorder, preorderIndex, 0, n - 1, n, nodeToIndex); // 0 is the starting index of inorder and (n - 1) is the inorder's last element's index. last 'n' parameter is the size of preorder array
    return ans;
}

// post order function to print ans in postorder (LRN)
void postorder(Node* ans) {
    // base case
    if(ans == NULL)
        return ;

    postorder(ans -> left);
    postorder(ans -> right);

    cout << ans -> data << " ";
}

int main() {

    int inorder[6] = {3, 1, 4, 0, 5, 2};
    int preorder[6] = {0, 1, 3, 4, 2, 5};

    Node* ans = buildTree(inorder, preorder, 6);

    cout << "postorder: ";
    postorder(ans);

    return 0;
}