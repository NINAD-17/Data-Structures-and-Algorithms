#include <iostream>
using namespace std;

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// Time Complexity: The time complexity of the removeAllSubstrings function is O(n * m), 
// where n is the length of the input string str and m is the length of the substring part.
// This is because, in the worst case, the function needs to search for the substring part in the input string str for each character in str, which takes O(n) time.
// The find function takes O(m) time to search for the substring part in the input string str. The erase function takes O(n) time to remove the substring from the input string.
// Therefore, the overall time complexity of the function is O(n * m)

// Find function returns 1st index of than substring
void removeAllSubstrings(string &str, string part) {
    while(str.length() != 0 && str.find(part) < str.length()) {
        cout << str << endl;
        str.erase(str.find(part), part.length());
    }
}

int main() {
    string str = "daabcbaabcbc", part = "abc";

    removeAllSubstrings(str, part);
    cout << str << endl;

    return 0;
}