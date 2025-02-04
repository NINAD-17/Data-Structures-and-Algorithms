#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st) {
    cout << "\nprinting stack: (top) ";
    while(!st.empty()) {
        cout << st.top() << " -> ";
        st.pop();
    }
    cout << "(bottom)" << endl << endl;
}

void printCharStack(stack<char> st) {
    cout << "\nprinting stack: (top) ";
    while(!st.empty()) {
        cout << st.top() << " -> ";
        st.pop();
    }
    cout << "(bottom)" << endl << endl;
}