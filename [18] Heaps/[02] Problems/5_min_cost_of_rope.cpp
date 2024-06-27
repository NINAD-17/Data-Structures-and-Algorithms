#include <bits/stdc++.h>
using namespace std;

// MIN COST OF ROPES

// time complexity: O(n log n)
// space complexity: O(n)
long long minCost(long long arr[], long long n) {
    // create a min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // insert elements of array in minHeap (priority queue)
    for(int i = 0; i < n; i++)
        pq.push(arr[i]);

    int cost = 0;

    while(pq.size() > 1) {
        long long a = pq.top(); // 1st smallest element
        pq.pop();

        long long b = pq.top(); // 2nd smallest element
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main() {

    long long arr[4] = {4, 3, 2, 6};
    // 4 3+2 6 ==> 4 5 6
    // 4+5 6 ==> 9 6
    // 9+6 ==> 15
    // therefore, 5 + 9 + 15 = 29

    cout << "min cost of rope is " << minCost(arr, 4) << endl;

    return 0;
}