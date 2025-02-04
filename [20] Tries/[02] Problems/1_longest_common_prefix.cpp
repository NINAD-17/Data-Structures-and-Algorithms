#include <bits/stdc++.h>
using namespace std;

// LONGEST COMMON PREFIX

// normal approach
// time complexity: O(m * n) here, m is the length of first string and 'n' are the rest strings
// space complexity: O(1)
string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    // for traversing all characters of first string
    for(int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];

        bool isMatched = true;

        // to comparing ch with rest of the strings
        for(int j = 0; j < n; j++) {
            // not matched
            if(arr[j].size() < i || ch != arr[j][i]) {
                isMatched = false;
                break;
            }
        }

        if(isMatched == false)
            break;
        else // matched in all strings
            ans.push_back(ch);
    }

    return ans;
}

// using tries: worst solution than above
// time and space complexity: O(m * n)
class TrieNode {
    public: 
        char data;
        TrieNode* children[26];
        int childCount; // to store child counts
        bool isTerminal;

        // constructor
        TrieNode(char data) {
            this -> data = data;

            for(int i = 0; i < 26; i++)
                children[i] = NULL;

            this -> childCount = 0;
            this -> isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        // constructor
        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) { // it means all chars from the word are inserted
                root -> isTerminal = true; // so make the last char as a terminal
                return ;
            }

            // assuming, word is in capital letter case
            int index = word[0] - 'a'; // we can get index as 0 - 25 so we can map it in array
            TrieNode* child;

            // children or word[0] is present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                // absent: create new char node 
                child = new TrieNode(word[0]);
                root -> childCount++;
                root -> children[index] = child; 
            }

            // recursive call for next char of the word
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        // lcp
        void lcp(string str, string &ans) {
            for(int i = 0; i < str.length(); i++) {
                char ch = str[i];

                if(root -> childCount == 1) {
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root -> children[index];
                } else
                    break;

                if(root -> isTerminal)
                    break;
            }
        }
};

string longestCommonPrefix_Tries(vector<string> &arr, int n) {
    Trie* t = new Trie();

    for(int i = 0; i < n; i++) {
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> lcp(first, ans);
    return ans;
}

int main() {

    vector<string> strings = {"coding", "codezen", "coding ninjas", "coders"};

    cout << longestCommonPrefix(strings, strings.size()) << endl;
    cout << longestCommonPrefix_Tries(strings, strings.size()) << endl;

    return 0;
}