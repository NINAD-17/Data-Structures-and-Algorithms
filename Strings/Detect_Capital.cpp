#include <iostream>
using namespace std;

// Time complexity for both function is O(n)

bool isCorrect2(string str) {
    int strSize = str.length();
    int count = 0;

    for(int i = 0; i < strSize; i++) {
        if(isupper(str[i]))
            count++;
    }

    // Check if,
    // 1. count is zero means all are lowercase
    // 2. count is equal to size of string means all chars are in uppercase
    // 3. if count is only 1 and that 1 capital letter is first
    return count == 0 || count == strSize || (count == 1 && isupper(str[0]));
}

bool isCapital(char ch) {
    if(ch >= 'A' && ch <= 'Z')
        return true;
    else
        return false;
}

bool isCorrect(string str) {
    bool isPrevCapital = false;

    if(isCapital(str[0]))
        isPrevCapital = true;
    
    for(int i = 1; i < str.length(); i++) {
        if(isCapital(str[i]) && !isPrevCapital)
            return false;
        
        if(!isCapital(str[i]) && isPrevCapital) {
            if(i == 1)
                isPrevCapital = false;
            else    
                return false;
        }
    }

    return true;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if(isCorrect(str)) 
        cout << "Given string have correct syntax" << endl;
    else    
        cout << "Given string have not correct syntax" << endl;

    return 0;
}