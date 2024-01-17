#include <iostream>
using namespace std;

// Time Complexity: O(n)

void moveZeros_optimal(int *arr, int n) {
    int lastNonZeroIndex = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0)
            arr[lastNonZeroIndex++] = arr[i];
    }
    // After last iteration, the first three elements of the array have been updated to {2, 1, 3}, while the remaining elements are unchanged {3, 0, 0}. This results in an intermediate output of {2, 1, 3, 3, 0, 0}

    for(int i = lastNonZeroIndex; i < n; i++)
        arr[i] = 0;
}


// Time Complexity: O(n^2)

void moveZeros(int *arr, int n) {
    int i = 0, j = 0;

    while(i < n - 1) {
        j = i + 1;
        if(arr[i] != 0)
            i++;
        else {   
            while(arr[j] == 0) {
                if(j == n)
                    return;
                else
                    j++;
            }
            swap(arr[i++], arr[j]);
        }
    }
}

int main() {
    int arr[10] = {2, 0, 1, 3, 0, 0};
    int n = 6;

    // moveZeros(arr, n);
    moveZeros_optimal(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}