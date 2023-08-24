#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Time Complexity: O(n)
void findSmallestAndSecondSmallest_2(int *arr, int n) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] < secondSmallest && arr[i] > smallest)
            secondSmallest = arr[i];
    }

    cout << "Smallest Element: " << smallest << endl;
    cout << "Second Smallest Element: " << secondSmallest << endl;
}

// Time Complexity: O(n log(n))
void findSmallestAndSecondSmallest(int *arr, int n) {
    sort(arr, arr + n);
    int secondSmallest = arr[1];

    if(arr[1] == arr[0]) {
        for(int i = 2; i < n; i++) {
            if(arr[i] != arr[1]) {
                secondSmallest = arr[i];
                break;
            }
        }
    }

    cout << "Smallest Element: " << arr[0] << endl;
    cout << "Second Smallest Element: " << secondSmallest << endl;
}

int main() {
    int arr[8] = {12, 25, 8, 55, 8, 33, 17, 11};
    int size = 8;

    findSmallestAndSecondSmallest_2(arr, size);
    return 0;
}