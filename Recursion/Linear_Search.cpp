#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
// Read more on readme.md

int linearSearch(int *arr, int n, int key, int index) {
    // Base Case
    if(n == 0)
        return -1;

    if(arr[0] == key)
        return index;
    
    // Recursive Relation
    return linearSearch(arr + 1, n - 1, key, index + 1);
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

    int isFound = linearSearch(arr, n, key, 0);

    if(isFound != -1)
        cout << key << " found at index " << isFound << endl;
    else
        cout << key << " is not found :(" << endl;

    return 0;
}