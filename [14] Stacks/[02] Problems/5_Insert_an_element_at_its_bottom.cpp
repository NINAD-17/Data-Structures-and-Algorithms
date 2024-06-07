#include <iostream>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK
// time complexity: O(n)
// space complexity: O(n)

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

int main() {

    stack<int> st;

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    printStack(st);

    int element = 12;
    insertAtBottom(st, element);

    printStack(st);

    return 0;
}