#include <iostream>
using namespace std;

// Link: https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/

// time complexity: O(n)
// resize function: The resize function is a member function of the std::string class. It changes the size of the string to the specified size k. If k is less than the current size of the string, the function removes characters from the end of the string. If k is greater than the current size of the string, the function appends additional characters to the end of the string. The time complexity of this operation is O(k) where k is the new size of the string.
// Space complexity: O(1)
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


// Time complexity: O(n * m)
// The first loop, which iterates over each character in str2, has a time complexity of O(m). The second loop, which iterates over each character in str1, has a time complexity of O(nk), where k is the cost of erasing a character from a string. Since the cost of erasing a character from a string is linear in the length of the string, we can say that k = n, giving us a time complexity of O(n^2) for the second loop. Therefore, the overall time complexity of the function is O(m + n^2), or O(nm) when m = n.
void removeChars2(string &str1, string str2) {
    int alphabates[26] = {0};

    for(int i = 0; i < str2.length(); i++)
        alphabates[str2[i] - 'a']++;
    
    for(int i = 0; i < str1.length(); i++) {
        if(alphabates[str1[i] - 'a'] > 0) 
            str1.erase(str1.begin() + i--); // i-- ==> Because after erase, letters are shifting left and therefore we've to decrement i.
    }   
}

// Time Complexity: O(n * m)
void removeChars_bruteForce(string &str1, string str2) {
    for(int i = 0; i < str2.length(); i++) {
        for(int j = 0; j < str1.length(); j++) {
            if(str2[i] == str1[j]) {
                str1.erase(str1.begin() + j);
                j--; // We've to use j-- because after erase, letters are shifting left and therefore we've to decrement j.
            }   // Use inputs -> str1 = "ccompctr" and str2 = "cat" to see what happens when we don't decrement j.
        }
    }
}

int main() {

    string str1 = "computer", str2 = "cat";

    string ans = removeChars(str1, str2);
    cout << ans << endl;

    return 0;
}