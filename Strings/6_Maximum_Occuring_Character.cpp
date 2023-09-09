#include <iostream>
using namespace std;

// Problem: https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

char maxOccChar(string str) {
    int alphabates[26] = {0};
    int charNum = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            charNum = str[i] - 'a';
        else    
            charNum = str[i] - 'A';
        
        alphabates[charNum]++;
    }

    int max = -1, ansChar = -1;
    for(int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            charNum = str[i] - 'a';
        else
            charNum = str[i] - 'A';

        if(max < alphabates[charNum]) {
            max = alphabates[charNum];
            ansChar = charNum;
        }
    }

    return charNum + 'a';
}

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Maximum Occuring character: " << maxOccChar(str) << endl;
    return 0;
}