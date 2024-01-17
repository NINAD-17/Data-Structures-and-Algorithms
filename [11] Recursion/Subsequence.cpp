#include <iostream>
#include <vector>
using namespace std;

void generate(string str, vector<string> output, int index, vector<vector<string>> &ans) {
    // Base Case
    if(index >= str.size()) {
        ans.push_back(output);
        return ;
    }

    // Exclude
    generate(str, output, index + 1, ans);

    // Include
    string temp = "";
    temp += str[index];
    output.push_back(temp);

    generate(str, output, index + 1, ans);
} 

vector<vector<string>> generateSubsequence(string str) {
    vector<vector<string>> ans;
    vector<string> output;
    int index = 0;

    generate(str, output, index, ans);
    return ans;
}

int main() {
    string str = "abc";

    vector<vector<string>> ans = generateSubsequence(str);

    // Output
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i].size() == 0)
            cout << "{}";
        for(int j = 0; j < ans[i].size(); j++)
            cout << "{" << ans[i][j] << "}";
        cout << endl;
    }
    
    return 0;
}