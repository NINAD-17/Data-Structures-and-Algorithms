#include <bits/stdc++.h>
using namespace std;

// MERGE TWO BINARY MAX HEAPS

void heapify(vector<int> &arr, int size, int index) {
    int largestElementIndex = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if(leftChildIndex < size && arr[largestElementIndex] < arr[leftChildIndex])
        largestElementIndex = leftChildIndex;

    if(rightChildIndex < size && arr[largestElementIndex] < arr[rightChildIndex])
        largestElementIndex = rightChildIndex;

    if(largestElementIndex != index) {
        swap(arr[largestElementIndex], arr[index]);
        heapify(arr, size, largestElementIndex);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // step 1: merge both arrays into one
    vector<int> ans;
    // ans.push_back(-1); // if you used 1 counter indexing means 0th index contain -1.
    for(auto i: a)
        ans.push_back(i);

    for(auto i: b)
        ans.push_back(i);

    // step 2: build heap using merged array
    int size = ans.size();
    for(int i = (size/2) - 1; i >= 0; i--)
        heapify(ans, size, i);

    return ans;
}

int main() {

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = mergeHeaps(a, b, 4, 3);

    cout << "merged two max heap: ";
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}