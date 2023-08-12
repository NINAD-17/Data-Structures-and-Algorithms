#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
void pairSum(int *arr, int n, int sum, int *pairsArr) {
    int k = 0;

    // If you want to sort this array by 1st element in that pair
    sort(arr, arr + n); // If you use sort then time complexity: O(n^2 + n log(n))

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                if(arr[i] <= arr[j]) {
                    pairsArr[k] = arr[i];
                    pairsArr[k + 1] = arr[j];
                } else {
                    pairsArr[k] = arr[j];
                    pairsArr[k + 1] = arr[i];
                }
                k += 2;
            }
        }
    }
}

int main() {
    int arr[10] = {5, 3, 2, 4, 1}, pairsArr[10];
    int n = 5, reqSum = 5;

    for(int i = 0; i < 10; i++) 
        pairsArr[i] = INT_MIN;
    
    pairSum(arr, n, reqSum, pairsArr);
    if(pairsArr[0] == INT_MIN)
        cout << "No pair found :(" << endl;
    else {
        for(int i = 0; i < 10; i+=2) {
            if(pairsArr[i] == INT_MIN)
                return 0;
            cout << "Pair-" << i + 1 << " -> " << pairsArr[i] << ", " << pairsArr[i + 1] << endl;
        }
    }

    cout << endl;
    return 0;
}