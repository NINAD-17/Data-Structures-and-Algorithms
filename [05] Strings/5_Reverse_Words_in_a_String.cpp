#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(n)
// The += operator is used to append each reversed word to the ans string. 
// In C++, this operation can take up to O(n) time in the worst case, 
// as it may involve creating a new string and copying all characters from both the ans string and the reversed word. 
// However, since this operation is performed once for each word and not for each character, its cost is amortized over all operations, 
// and it does not change the overall time complexity of O(n).

string reverseString(string temp) {
    int st = 0, en = temp.size() - 1;
    
    while(st < en) 
        swap(temp[st++], temp[en--]);
    
    return temp;
}

string reverseWords(string str) {
    string temp = "", ans = "";

    for(int i = 0; i < str.length(); i++) {   // for(int i = 0; i <= str.length(); i++) 

        if(str[i] == ' ') {  // str[i] == ' ' || str[i] == '\0' Read more about this condition in readme.md as it's not good code
            temp = reverseString(temp);
            ans += temp + " ";
            temp = "";
            continue;
        }

        temp += str[i];
    }

    // For last word of sentence you need to manually reverse it and attach to answer
    temp = reverseString(temp);
    ans += temp;

    return ans;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << str << endl;

    string ans = reverseWords(str);
    cout << "Reversed words in a sentence: " << ans << endl;

    return 0;
}