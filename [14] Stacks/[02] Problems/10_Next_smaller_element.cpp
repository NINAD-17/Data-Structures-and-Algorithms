#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// FIND NEXT SMALLER ELEMENT
// time complexity: O(n)
// space complexity: O(n)

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1); // 1st element of stack is -1

    vector<int> ans(n); // vector to store ans // vector is of size n

    // traverse vector from last element to first element
    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        
        // while top element of stack is greater than curr then pop
        while(st.top() >= curr) {
            st.pop();
        }

        // ans is top of stack
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

// PREVIOUS SMALLER ELEMENT 
vector<int> prevSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1); // 1st element of stack is -1

    vector<int> ans(n); // vector to store ans // vector is of size n

    // traverse vector from first element to last element
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        
        // while top element of stack is greater than curr then pop
        while(st.top() >= curr) {
            st.pop();
        }

        // ans is top of stack
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

void printArr(vector<int> &arr, int n) {
    cout << "--> [";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {

    vector<int> arr;
    
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans = nextSmallerElement(arr, arr.size());
    printArr(ans, ans.size());

    ans = prevSmallerElement(arr, arr.size());
    printArr(ans, ans.size());

    return 0;
}