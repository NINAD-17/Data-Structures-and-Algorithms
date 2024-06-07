#include <iostream>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// SORT A STACK
// time complexity: O(n^2)
// space complexity: O(n)

void sortedInsert(stack<int> &st, int element) {
    // base case: until you don't get st.top smaller than element (or empty), go further in stack by poping top element when you get small top element than our element then push that element on top of stack and then move all the elements on top as it is.
    if(st.empty() || st.top() < element) {
        st.push(element);
        return;
    }

    int currElement = st.top();
    st.pop();

    sortedInsert(st, element);
    st.push(currElement);
}

void sortStack(stack<int> &st) {
    // base case
    if(st.empty()) 
        return;
    
    int currElement = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, currElement);
}

int main() {

    stack<int> st;

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    st.push(2);
    st.push(3);
    printStack(st);

    sortStack(st);
    printStack(st);

    return 0;
}