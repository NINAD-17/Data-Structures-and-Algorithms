#include <iostream>
#include <queue>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// QUEUE REVERSAL 

// ---- using stack ----
// time complexity: O(n)
// space complexity: O(n)
void reverseQueueUsingStack(queue<int> &q) {
    // create a stack
    stack<int> st;

    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

// ---- using recursion ----
// time complexity: O(n)
// space complexity: O(n)
// note: above approach (using stack) may use less space than the recursive approach because it doesn’t require multiple levels of recursion on the call stack.
void reverseUsingRec(queue<int> &q, queue<int> &ans) {
    // base case
    if(q.empty()) 
        return;
    
    // store the front element 
    int front = q.front();

    // pop the front element
    q.pop();
    reverseUsingRec(q, ans);

    // while returning push front in ans queue
    ans.push(front);
}

int main() {

    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    printQueue(q);

    reverseQueueUsingStack(q);
    printQueue(q);

    // queue<int> ans;
    // reverseUsingRec(q, ans);
    // printQueue(ans);

    return 0;
}