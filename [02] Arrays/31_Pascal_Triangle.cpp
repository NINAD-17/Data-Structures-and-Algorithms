#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2) // Optimal
// Space Complexity: O(n^2)

vector<vector<int>> generatePascalTriangle(int numOfRows) {
    vector<vector<int>> ans;

    for(int i = 0; i < numOfRows; i++) {
        vector<int> temp(i + 1);

        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                temp[j] = 1;
            }
            else {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j]; // Here we're adding value to temp[j] by taking sum of previous row's `j` th element and `j - 1` element. We're accessing previous row by ans[i - 1] and inside element by [j];
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    
    int size;
    cout << "Enter size of pascal triangle(total rows) -> ";
    cin >> size;

    vector<vector<int>> ans = generatePascalTriangle(size);

    for(int i = 0; i < ans.size(); i++) {
        cout << "Row " << i + 1 << " --> [ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
}