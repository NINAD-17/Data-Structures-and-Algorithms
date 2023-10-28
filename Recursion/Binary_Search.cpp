#include <iostream>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(log n)

int binarySearchRecursion(int *arr, int st, int en, int key) {
    // Base Case
    if(st > en)
        return -1;
    
    // Processing
    int mid = st + (en - st) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binarySearchRecursion(arr, mid + 1, en, key);
    else
        return binarySearchRecursion(arr, st, mid - 1, key);
}

int binarySearch(int *arr, int n, int key) {
    int st = 0;
    int en = n - 1;

    return binarySearchRecursion(arr, st, en, key);
}

int main() {
    int arr[10];
    int n, key;

    cout << "Enter size of array (less than 10): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    cout << "Enter a number to search: ";
    cin >> key;

    int isFound = binarySearch(arr, n, key);

    if(isFound != 0)
        cout << key << " found at index " << isFound << endl;
    else
        cout << key << " is not found :(" << endl;

    return 0;
}