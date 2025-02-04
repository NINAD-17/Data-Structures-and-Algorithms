#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string &str) {
    // odd condition
    if(str.length() % 2 != 0)
        return -1;

    // remove valid part
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        if(ch == '(') {
            st.push(ch);
        } else {
            // ch is a closed brace
            if(!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    // now the stack contains invalid expressions
        int a = 0;
        int b = 0;
        while(!st.empty()) {
            if(st.top() == '(') {
                b++;
            } else {
                a++;
            }
            st.pop();
        }

        int ans = (a + 1)/2 + (b + 1)/2;
        return ans;
}

int main() {

}