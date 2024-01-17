#include <iostream>
#include <map>
#include <climits>
using namespace std;

// Time Complexity: O(n)

void printFreq(string str) {
    int alphabates[26] = {0};
    map<char, int> mp;

    for(int i = 0; i < str.length(); i++)
        alphabates[str[i] - 'a']++;

    for(int i = 0; i < str.length(); i++) {

        if(alphabates[str[i] - 'a'] == INT_MIN) 
            continue;
        
        cout << str[i] << alphabates[str[i] - 'a'] << " ";
        mp.insert({str[i], alphabates[str[i] - 'a']});
        alphabates[str[i] - 'a'] = INT_MIN;
    }
    
    cout << endl;
    for(auto it: mp) 
        cout << it.first << it.second << " ";
}

int main() {
    string str = "geeksforgeeks";

    printFreq(str);
    cout << endl;

    return 0;
}