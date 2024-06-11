#include <iostream>
#include <queue>
#include <vector>
#include "../lib/print.cpp"
using namespace std;

// FIND FIRST INTEGER IN EVERY WINDOW OF SIZE K

// --- sliding window approach ---
// time complexity: O(n)
// space complexity: O(n)
vector<long long int> firstNegegiveIntegerInEachWindow(long long int *arr, long long int n, long long int k) {
    // create a deque to store negetive number's indexes from that window of size k
    deque<int> dq;

    // create a vector (ans) to store all the first negetive elements from each window
    vector<long long int> ans;

    // for 1st window of size k that is 0 to k
    for(int i = 0; i < k; i++) {
        // push all the negetive number's indexes in dq (if present)
        if(arr[i] < 0) 
            dq.push_back(i);
    }

    // store ans of 1st k sized window
    if(!dq.empty()) // means -ve element is present in the block
        ans.push_back(arr[dq.front()]);
    else 
        dq.push_back(0); // no negetive element present in the block so push 0

    // process the remaining elements
    for(int i = k; i < n; i++) {
        // now remove any negetive element's index present in deque which is not in range.
        // means remove front element from dq if it's not in range because we've added new element.
        if(!dq.empty() && i - dq.front() >= k)
            dq.pop_front(); // remove

        // addition: if new element is -ve then add index of it in deque
        if(arr[i] < 0) 
            dq.push_back(i);

        // store ans of curr window
        if(!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

int main() {

    long long int arr[5] = {-8, 2, 3, -6, 10};
    int k = 2; // size of each window

    vector<long long int> ans = firstNegegiveIntegerInEachWindow(arr, 5, k);


    // printing ans
    cout << "first negetive element in each window: [";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "]" << endl;

    return 0;
}