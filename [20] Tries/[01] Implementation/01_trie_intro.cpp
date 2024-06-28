#include <iostream>
using namespace std;

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

        // behaviours

        // --> 1. insert a word
        // time and space complexity: O(l)
        // recursive logic for insertion:
        void insertUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) { // it means all chars from the word are inserted
                root -> isTerminal = true; // so make the last char as a terminal
                return ;
            }

            // assuming, word is in capital letter case
            int index = word[0] - 'A'; // we can get index as 0 - 25 so we can map it in array
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

        // insert
        void insertWord(string word) {
            insertUtil(root, word);
        }

        // --> 2. search a word
        // time and space complexity: O(l)
        bool searchUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) {
                return root -> isTerminal; // is the last char a terminal node or not
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // char is present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                // absent
                return false;
            }

            // recursive call
            return searchUtil(child, word.substr(1));

        }

        // search 
        bool searchWord(string word) {
            return searchUtil(root, word);
        }

        // --> 3. Delete a word
        void deleteUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) {
                if(root -> isTerminal) {
                    root -> isTerminal = false;
                    cout << "deleted " << endl;
                    delete root;
                    
                } else {
                    cout << "word not found :(" << endl;
                }
                return ;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                cout << "word not found" << endl;
                return;
            }

            deleteUtil(child, word.substr(1));
        }

        void deleteWord(string word) {
            deleteUtil(root, word);
        }
};

int main() {

    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "present or not: " << t -> searchWord("TIME") << endl;
    cout << "present or not: " << t->searchWord("TIM") << endl;

    t->deleteWord("ARM");
    cout << "present or not: " << t->searchWord("ARM") << endl;

    return 0;
}