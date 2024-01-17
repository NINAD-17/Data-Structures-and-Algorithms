#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log n)
bool containDuplicates_sort(int *arr, int size) {
    sort(arr, arr + size); // Time Complexity: O(n log n)

    for(int i = 0; i < size - 1; i++) {
        if(arr[i] == arr[i + 1]) 
            return true;
    }

    return false;
}

// Brute Force solution
// Time Complexity: O(n^2)
bool containDuplicates(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) 
                return true;
        }
    }

    return false;
}

int main() {
    int arr[10] = {1,1,1,3,3,4,3,2,4,2};
    int size = 10;

    if(containDuplicates_sort(arr, size))
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    
    return 0;
}