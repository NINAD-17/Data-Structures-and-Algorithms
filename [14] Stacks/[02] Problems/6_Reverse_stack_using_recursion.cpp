#include <iostream>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// REVERSE STACK USING RECURSION
// time complexity: O(n^2) because we're first making recursive calls till stack isn't empty and inside this function we're calling insertAtBottom which is again recursively calling till stack is not empty
// space complexity: O(n)  In the worst-case scenario, depth of the recursive call stack is n for reverseStack and n for insertAtBottom, leading to a total space complexity of O(n).

void insertAtBottom(stack<int> &st, int element) {
    // base case
    if(st.empty()) {
        st.push(element);
        return;
    }

    int currElement = st.top();
    st.pop();

    insertAtBottom(st, element);
    st.push(currElement);
}

void reverseStack(stack<int> &st) {
    // base case
    if(st.empty()) {
        return;
    }

    int currElement = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, currElement);
}

int main() {

    stack<int> st;

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    st.push(6);
    printStack(st);

    reverseStack(st);
    printStack(st);

    return 0;
}