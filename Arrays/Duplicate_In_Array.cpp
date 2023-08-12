#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

// Using Unordered Map:
int findDuplicate_unMap(int *arr, int size) {
    unordered_map<int, int> freq;
    for(int i = 0; i < size; i++) {
        if(freq.count(arr[i]) > 0)
            return arr[i];
        freq[arr[i]]++;
    }
    return INT_MIN;
}

// Optimized approach: Note: But these approach only applicable when there is only one number is duplicate.
// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate2(int *arr, int n) {
    int ans = 0; 
    
    for(int i = 0; i < n; i++) 
        ans ^= arr[i];
    
    for(int j = 1; j < n; j++)
        ans ^= j;
    
    return ans;
}

// Brute force Approach: 
// time complexity: O(n^2)
// Space Complexity: O(1) 
int findDuplicate(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) 
                return arr[i];
        }
    }
    return INT_MIN;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {

    int arr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    int duplicateElement = findDuplicate2(arr, size);
    if(duplicateElement == 0 /* INT_MIN for findDuplicate() instead 0 */)
        cout << "No duplicate element is found" << endl;
    else    
        cout << "Duplicate element is " << duplicateElement << endl;
    return 0;
}