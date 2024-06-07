#include <iostream>
#include <stack>
using namespace std;

int main() {

    // creation of stack
    stack<int> s;

    // push operation: to insert element
    s.push(2);
    s.push(3);

    // pop operation: to remove top element
    s.pop(); 

    // top operation: to check top of stack
    cout << "printing top of stack element: " << s.top() << endl;

    // s.pop();
    // empty operation: to check if stack is empty or not
    if(s.empty())
        cout << "stack is empty" << endl;
    else    
        cout << "stack isn't empty" << endl;

    // size: to check size of stack
    cout << "size of stack is " << s.size() << endl;

    return 0;
}