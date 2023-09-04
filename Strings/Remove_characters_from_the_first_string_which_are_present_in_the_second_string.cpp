#include <iostream>
using namespace std;

// Link: https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/

// time complexity: O(n)
// resize function: The resize function is a member function of the std::string class. It changes the size of the string to the specified size k. If k is less than the current size of the string, the function removes characters from the end of the string. If k is greater than the current size of the string, the function appends additional characters to the end of the string. The time complexity of this operation is O(k) where k is the new size of the string.
string removeChars(string str1, string str2) {
    int alphabates[26] = {0};
    string ans = "";
    int k = 0;

    for(int i = 0; i < str2.length(); i++)
        alphabates[str2[i] - 'a']++;
    
    for(int i = 0; i < str1.length(); i++) {
        if(alphabates[str1[i] - 'a'] > 0)
            continue;
        ans += str1[i];
        str1[k++] = str1[i];
    }

    str1.resize(k);
    cout << str1 << endl;
    return ans;
}

int main() {

    string str1 = "computer", str2 = "cat";

    string ans = removeChars(str1, str2);
    cout << ans << endl;

    return 0;
}