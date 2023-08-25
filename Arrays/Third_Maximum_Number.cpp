#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

// Using Set
// Time/space complexity: O(n)
int thirdMaxUsingSet(int *arr, int n) {
    set<int> s; // To only store unique numbers in sorted order.
    for(int i = 0; i < n; i++)
        s.insert(arr[i]);
    
    if(s.size() >= 3) {
        int thirdIndexFromLast = s.size() - 3;
        auto thirdMax = next(s.begin(), thirdIndexFromLast); // next function to advance the begin iterator of the set s by Third_index_from_last positions. The begin iterator points to the first element in the set, and advancing it by Third_index_from_last positions means it now points to the third element from the end of the set. This is because the elements in a set are stored in ascending order, so the third element from the end is also the third maximum value in the set.
        return *thirdMax;
    }

    return *(--s.end()); // If the vector does not contain at least three distinct values, the function returns the maximum value in the vector. therefore we're 1st decrementing s.end() to reach last position.
    // The * operator is used to dereference a pointer or iterator, which means it returns the value stored at the memory location pointed to by the pointer or iterator.
}

// Time Complexity: O(n log(n))
void thirdDistinctMax(int *arr, int n) {
    sort(arr, arr + n, greater<int>());

    int fDistinctMax = arr[0];
    int sDistinctMax = arr[1];
    int tDistinctMax = arr[2];

    if(arr[1] == arr[0]) {
        for(int i = 2; i < n; i++) {
            if(arr[i] != arr[0]) {
                sDistinctMax = arr[i];
                break;
            }
        }
    }

    if(arr[2] == arr[1] || arr[2] == arr[0]) {
        for(int i = 2; i < n; i++) {
            if(arr[i] != arr[0] && arr[i] != arr[1]) {
                tDistinctMax = arr[i];
                break;
            }
        }
    }

    cout << "The first distinct maximum is " << fDistinctMax << "." << endl;
    cout << "The second distinct maximum is " << sDistinctMax << "." << endl;
    cout << "The third distinct maximum is " << tDistinctMax << "." << endl;
}

int main() {
    int arr[10] = {2,2,3,1};
    int n = 4;

    thirdDistinctMax(arr, n);
    cout << "Third Max using set: " << thirdMaxUsingSet(arr, n) << endl; 
    return 0;
}