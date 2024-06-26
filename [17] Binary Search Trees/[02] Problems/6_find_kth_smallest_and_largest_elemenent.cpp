#include <iostream>
#include <vector>
#include "../lib/build.cpp"
using namespace std;

// FIND K-TH SMALLEST AND LARGEST ELEMENT IN BST

// use moris traversal and solve this question for optimized approach. by this approach time complexity will be O(n) and space complexity will be O(1)

// using inorder traversal approach
int getAns(Node* root, int k, int &i) {
    // base case
    if(root == NULL)
        return -1;

    int left = getAns(root -> left, k, i);

    if(left != -1)
        return left;
    
    i++;
    if(i == k)
        return root -> data;
    
    return getAns(root -> right, k, i);
}

int k_th_smallest_element(Node* root, int k) {
    if(root == NULL) return -1;
    int i = 0;
    return getAns(root, k, i);
} 

int k_th_largest_element(Node* root, int k, int size) {
    if(root == NULL) return -1;
    k = size - k + 1;
    int i = 0;
    return getAns(root, k, i);
}

int main() {

    Node *root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root);

    levelOrderIteratively(root);

    cout << endl;

    int k = 3, size = 11;
    cout << k << "th smallest element is " << k_th_smallest_element(root, k) << endl;
    cout << k << "th largest element (from last) is " << k_th_largest_element(root, k, size) << endl;

    return 0;
}