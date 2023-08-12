#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Using hash tables is a more optimized way to solve this problem after you learn the concept of hash tables
// ? Pending ---


// We can optimize brute force approach by using two pointers approach
// Time Complexity: O(n^2 + n log(n))
void tripletSum_twoPt(int *arr, int n, int reqSum, int *pairsArr) {
    int k = 0;

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;
        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == reqSum) {
                pairsArr[k] = arr[i];
                pairsArr[k + 1] = arr[left];
                pairsArr[k + 2] = arr[right];
                k += 3;
                left++;
                right--;
            } else if(sum < reqSum) {
                left++;
            } else {
                right--;
            }
        }
    }
} 

// Brute Force Approach
// Time Complexity: O(n^3)
void tripletSum(int *arr, int n, int sum, int *pairsArr) {
    int k = 0;

    // If you want to sort this array by 1st element in that pair
    sort(arr, arr + n); // If you use sort then time complexity: O(n^3 + n log(n))

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int l = j + 1; l < n; l++) {
                if(arr[i] + arr[j] + arr[l] == sum) {
                    pairsArr[k] = arr[i];
                    pairsArr[k + 1] = arr[j];
                    pairsArr[k + 2] = arr[l];
                    k += 3;
                }
            }
        }
    }
}

int main() {
    int arr[10] = {0, 3, 2, 4, 1}, pairsArr[10];
    int n = 5, reqSum = 5;

    for(int i = 0; i < 10; i++) 
        pairsArr[i] = INT_MIN;
    
    tripletSum_twoPt(arr, n, reqSum, pairsArr);
    if(pairsArr[0] == INT_MIN)
        cout << "No pair found :(" << endl;
    else {
        int k = 1;
        for(int i = 0; i < 10; i+=3) {
            if(pairsArr[i] == INT_MIN)
                return 0;
            cout << "Pair-" << k++ << " -> " << pairsArr[i] << ", " << pairsArr[i + 1] << ", " << pairsArr[i + 2] << endl;
        }
    }

    cout << endl;
    return 0;
}