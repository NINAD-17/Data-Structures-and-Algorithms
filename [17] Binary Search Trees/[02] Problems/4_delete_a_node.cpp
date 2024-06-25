#include <iostream>
#include "../lib/build.cpp"
using namespace std;

// DELETE A NODE (imp)
// conditions: 
//      1. 0 childs
//      2. 1 child in left
//      3. 1 child in right
//      4. 2 childs

Node* findMinimumValue(Node* &root) {
    Node* temp = root;

    while(temp -> left != NULL)
        temp = temp -> left;
    
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    // base case
    if(root == NULL)
        return root;

    if(root -> data == val) {
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // --> only left child present
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // --> only right child present
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 childs
        if(root -> left != NULL && root -> right != NULL) {
            // find minimum value from right sub-tree or maximum value from left sub-tree (any one)
            // here, we've calculated minimum value from right sub-tree (you can relate this with prev problem i.e inorder predecessor and successor)
            int mini = findMinimumValue(root -> right) -> data;

            // replace the data of root with min value
            root -> data = mini;

            // now we've to delete that node mini
            root -> right = deleteFromBST(root -> right, mini);

            return root;
        }
    }

    // recursive calls
    else if(root -> data > val) {
        root -> left = deleteFromBST(root -> left, val);
        return root;
    } else {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main() {

    Node* root = NULL;

    cout << "note: to stop entering the data give input -1" << endl;
    cout << "enter data to create BST: ";
    takeInput(root); // 21 10 50 5 15 40 60 30 45 55 70 -1

    levelOrderIteratively(root);
    cout << endl << endl;

    deleteFromBST(root, 50);
    levelOrderIteratively(root);
    

    return 0;
}