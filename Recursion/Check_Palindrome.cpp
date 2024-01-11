#include <iostream>
using namespace std;

bool isPalindrome_rec_2(string str, int i) {
    if(i >= str.length()/2)
        return true;
    
    if(str[i] == str[str.length() - 1 - i])
        isPalindrome_rec_2(str, ++i);
    else    
        return false;
}

// Using recursion
bool isPalindrome_rec(string str, int st, int en) {
    // Base Case
    if(st >= en)
        return true;

    if(str[st] == str[en])
        isPalindrome_rec(str, ++st, --en); // Pre-Increment and Pre-decrement is important here.
    else
        return false;
}

// Without using recursion
bool isPalindrome(string str) {
    int st = 0, en = str.length() - 1;

    while(st < en) {
        if(str[st] == str[en])
            st++, en--;
        else 
            return false;
    }

    return true;
}

int main() {
    string str;

    cout << "Enter a string: " << endl;
    cin >> str;

    if(isPalindrome_rec_2(str, 0))
        cout << "Given string is a palindrome." << endl;
    else 
        cout << "Given string is not a palindrome." << endl;
}