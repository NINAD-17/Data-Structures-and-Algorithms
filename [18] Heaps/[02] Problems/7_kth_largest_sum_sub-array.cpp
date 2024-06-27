#include <bits/stdc++.h>
using namespace std;

// K-TH LARGEST SUM SUBARRAY

// optimized approach using min heap
// time complexity: O(n^2 * log k)
// space complexity: O(k)
int getKthLargest(vector<int> &arr, int k) {
    // create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    int size = arr.size();
    for(int i = 0; i < size; i++) {
        int sum = 0;
        for(int j = i; j < size; j++) {
            sum += arr[j];

            if(pq.size() < k) {
                pq.push(sum);
            } else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

// brute force
// time complexity: O(n^2 log n)
// space complexity: O(n^2)
int findKthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> sums;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            sums.push_back(sum);
        }
    }

    sort(sums.begin(), sums.end());

    for(auto i: sums)
        cout << i << " ";
    cout << endl;

    return sums[sums.size() - k];
}

int main() {
    vector<int> arr = {1, 2, 3};
    int k = 2;

    cout << k << "th largest is " << findKthLargest(arr, k) << endl;

    return 0;
}