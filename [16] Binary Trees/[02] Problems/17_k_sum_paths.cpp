#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// K SUM PATHS
// read this: https://www.geeksforgeeks.org/count-all-k-sum-paths-in-a-binary-tree/

// Note: for this problem we've created separate build function
//       because in our example one node contain -1 as a value. see image from readme file. So we modified -2 for return
Node* buildTree22(Node* &root) {
    // initially the root is NULL
    int data;

    if(root == NULL)
        cout << "enter data for root node: ";
    else 
        cout << "enter data: ";
    cin >> data;
    cout << endl;

    if(data == -2)
        return NULL;

    root = new Node(data);

    cout << "-> enter data for inserting in left of " << data << endl;
    root -> left = buildTree22(root -> left);

    cout << "-> enter data for inserting in right of " << data << endl;
    root -> right = buildTree22(root -> right);

    return root;
}

void solve(Node* &root, int k, int &count, vector<int> path) {
    if(root == NULL)
        return ;
    
    path.push_back(root -> data);

    solve(root -> left, k, count, path);
    solve(root -> right, k, count, path);

    int sum = 0;
    for(int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        cout << "\n";
        for(int j = 0; j < path.size(); j++) {
            cout << path[j] << " ";
        }
        cout << "\nsum: " << sum << endl << endl;
        if(sum == k) {
            count++;
            // break; //
        }
    }

    // backtrack
    path.pop_back();
}

int kSumPaths(Node* root, int k) {
    if(root == NULL)
        return -1;

    vector<int> path;
    int count = 0;

    solve(root, k, count, path);

    return count;
}

int main() {
    Node* root = NULL;
    root = buildTree22(root); // 1 3 2 -2 -2 1 1 -2 -2 -2 -1 4 1 -2 -2 2 -2 -2 5 -2 6 -2 -2

    // levelOrderIteratively(root);

    cout << "Sum: " << kSumPaths(root, 5) << endl;

    return 0;
}