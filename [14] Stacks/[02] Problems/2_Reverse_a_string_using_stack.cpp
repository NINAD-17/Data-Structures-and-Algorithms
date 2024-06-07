#include <iostream>
#include <stack>
using namespace std;

// REVERSE A STRING USING STACK
// time complexity: O(n)
// space complexity: O(n)

int main() {
    string str = "Taehyung";

    // create stack of `char`
    stack<char> s;

    // put all the char from string to stack
    for(int i = 0; i < str.length(); i++) 
        s.push(str[i]);
    
    string revString = "";

    /* Below logic will not work */
    /*
    int topOfStack = s.size();
    cout << topOfStack << endl;
    while(topOfStack != 0) {
        revString.push_back(s.top()); // here it will only push top element that is "g" everytime
        topOfStack--;
    }
    */
    
    while(!s.empty()) {
        revString += s.top(); // or use => revString.push_back(s.top())
        s.pop();
    }

    cout << revString << endl;
}