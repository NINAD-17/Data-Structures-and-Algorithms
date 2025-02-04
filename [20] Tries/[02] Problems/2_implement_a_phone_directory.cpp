#include <bits/stdc++.h>
using namespace std;

// IMPLEMENT A PHONE DIRECTORY

class TrieNode {
    public: 
        char data; // char to store in node
        TrieNode* children[26]; // to point A-Z char nodes
        bool isTerminal; // to know about terminal node

        // constructor
        TrieNode(char data) {
            this -> data = data;

            for(int i = 0; i < 26; i++) {
                children[i] = NULL; // initially all childrens are NULL
            }

            isTerminal = false;
        }
};

class Trie {
    public: 
        TrieNode* root; // for root node

        // constructor
        Trie() {
            root = new TrieNode('\0'); // root node contains null char
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
                root -> children[index] = child; 
            }

            // recursive call for next char of the word
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
            if(curr -> isTerminal) {
                temp.push_back(prefix);
            }

            for(char ch = 'a'; ch <= 'z'; ch++) {
                TrieNode* next = curr -> children[ch - 'a'];
                if(next != NULL) {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string str) {
            TrieNode* prev = root;
            vector<vector<string>> output; // answer to return
            string prefix = "";

            for(int i = 0; i < str.length(); i++) {
                char last_ch = str[i];
                prefix.push_back(last_ch);

                // check for last char
                TrieNode* curr = prev -> children[last_ch - 'a'];

                // if not found
                if(curr == NULL)
                    break;

                // if found
                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                output.push_back(temp);
                temp.clear();
                prev = curr;
            }

            return output;
        }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    // creation of tries
    Trie* t = new Trie();

    // insert all contacts in trie
    for(int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t -> insertWord(str);
    }

    return t -> getSuggestions(queryStr);
}

int main() {

    return 0;
}