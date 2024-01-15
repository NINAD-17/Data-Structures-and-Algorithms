#include <iostream>
#include <vector>
using namespace std;

#define KEYPAD {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

void generateCombinations(string inputNo, string output, int index, vector<string> &ans) {
    // Base Case
    if(index >= inputNo.size()) {
        ans.push_back(output);
        return ;
    }

    // Keypad
    string keypad[] = KEYPAD;
    
    int number = inputNo[index] - '0';
    string keypadStr = keypad[number];

    for(int i = 0; i < keypadStr.length(); i++) {
        output.push_back(keypadStr[i]);
        generateCombinations(inputNo, output, index + 1, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string inputNo) {
    vector<string> ans;
    string output;
    int index = 0;

    generateCombinations(inputNo, output, index, ans);
    return ans;
}

int main() {
    string inputNo = "23";

    vector<string> ans = letterCombinations(inputNo);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}