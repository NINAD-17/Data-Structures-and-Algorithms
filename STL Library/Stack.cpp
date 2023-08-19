#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<string> st;

    // Add elements
    st.push("Hello");
    st.push("STL");
    st.push("Library");

    cout << "Top element: " << st.top() << endl;

    // Delete element
    st.pop();
    cout << "Top element: " << st.top() << endl;

    cout << "Size of stack: " << st.size() << endl;

    cout << "is empty? " << st.empty() << endl;


    return 0;
}