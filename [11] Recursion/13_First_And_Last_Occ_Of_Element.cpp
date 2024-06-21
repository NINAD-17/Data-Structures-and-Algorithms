#include <iostream>
using namespace std;

// Time Complexity: O(log(n))
// Space Complexity: O(log(n)) // because each recursive call adds a layer to the call stack. The maximum size of the call stack will be equal to the maximum depth of recursion, which is log n in the case of binary search.

int findFirstOcc(int *arr, int st, int en, int k, int ans) {
    // Base Case
    if(st > en) {
        cout << "base case hit" << endl;
        return ans; // No element found
    }
    
    int mid = st + (en - st) / 2;
    cout << "\nmid: " << mid << endl;
    cout << "ans: " << ans << endl;

    if(arr[mid] == k) {
        ans = mid;
        cout << "ans updated: " << ans << endl << endl;
        return findFirstOcc(arr, st, mid - 1, k, ans);
    }
    else if(arr[mid] > k)
        return findFirstOcc(arr, st, mid - 1, k, ans);
    else 
        return findFirstOcc(arr, mid + 1, en, k, ans);

}

int findLastOcc(int *arr, int st, int en, int k, int ans) {
    // base case
    if(st > en) 
        return ans;

    int mid = st + (en - st) / 2;

    if(arr[mid] == k) {
        ans = mid;
        return findLastOcc(arr, mid + 1, en, k, ans);
    } else if(arr[mid] > k)
        return findLastOcc(arr, st, mid - 1, k, ans);
    else
        return findLastOcc(arr, mid + 1, en, k, ans);
}

int main() {
    int arr[10] = {1, 2, 2, 2, 3, 4, 4, 4, 4, 6};
    int size = 10;
    int k = 4;
    int ans = -1;

    cout << "\nFirst occurance of " << k << " is " << findFirstOcc(arr, 0, 9, k, ans) << endl;
    cout << "Last occurance of " << k << " is " << findLastOcc(arr, 0, 9, k, -1) << endl;
    return 0;
}