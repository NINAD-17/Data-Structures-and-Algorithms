#include <iostream>
#include <vector>
#include <queue>
#include "../lib/build.cpp"
using namespace std;

// ZIG ZAG TRAVERSAL (SPIRAL TRAVERSAL)
// time complexity: O(n)
// space complexity: O(n)

vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> tempAns(size); // remember to initialize tempArr with size otherwise code will not work

        // process each level
        for(int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            // reverse insert or normal insert
            int index = leftToRight ? i: size - i - 1;
            tempAns[index] = frontNode -> data;

            if(frontNode -> left)
                q.push(frontNode -> left);
            
            if(frontNode -> right)
                q.push(frontNode -> right);
        }
        // change direction
        leftToRight = !leftToRight;

        // for(int i = 0; i < tempAns.size(); i++) {
        //     ans.push_back(tempAns[i]);
        // }

        for(auto i: tempAns)
            ans.push_back(i);
    }
    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree(root); // 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1

    cout << "level order traversal: \n";
    levelOrderIteratively(root);

    cout << "\nprinting zig zag traversal: \n";
    vector<int> ans = zigZagTraversal(root);
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    // for(int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    // cout << endl;

    return 0;
}