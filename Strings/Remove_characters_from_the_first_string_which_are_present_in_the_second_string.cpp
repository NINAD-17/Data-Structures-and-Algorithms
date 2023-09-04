#include <iostream>
using namespace std;

// time complexity: O(n)
string removeChars(string str1, string str2) {
    int alphabates[26] = {0};
    string ans = "";

    for(int i = 0; i < str2.length(); i++)
        alphabates[str2[i] - 'a']++;
    
    for(int i = 0; i < str1.length(); i++) {
        if(alphabates[str1[i] - 'a'] > 0)
            continue;
        ans += str1[i];
    }

    return ans;
}

int main() {

    string str1 = "computer", str2 = "cat";

    string ans = removeChars(str1, str2);
    cout << ans << endl;

    return 0;
}