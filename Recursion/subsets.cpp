#include <iostream>
#include <vector>
using namespace std;

void solve(int *arr, int size, vector<int> output, int index, vector<vector<int>> &ans) {
    // Base Case
    if(index >= size) {
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(arr, size, output, index + 1, ans);

    // Include
    int element = arr[index];
    output.push_back(element);
    solve(arr, size, output, index + 1, ans);
}

vector<vector<int>> subsets(int *arr, int size) {
    vector<vector<int>> ans; // To store all subsets in an array
    vector<int> output; // To store output
    int index = 0;

    solve(arr, size, output, index, ans);
    return ans;
}

int main() {

    int arr[3] = { 1, 2, 3 };
    int size = 3;

    vector<vector<int>> ans = subsets(arr, size);

    // Output
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i].size() == 0)
            cout << "{}";
        for(int j = 0; j < ans[i].size(); j++)
            cout << "{" << ans[i][j] << "}";
        cout << endl;
    }
    cout << endl;

    return 0;
}