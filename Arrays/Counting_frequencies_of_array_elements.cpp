#include <iostream>
#include <climits>
using namespace std;

// Using Array: Time Complexity: O(n^2)
int countFreq(int *arr, int n, int ans[10][2]) {
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == INT_MIN)
            continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = INT_MIN;
            }
        }
        ans[k][0] = arr[i];
        ans[k++][1] = count;
    }

    return k;
}

int main() {

    int arr[10] = {10, 20, 20, 10, 10, 20, 5, 20};
    int size = 8;
    int ans[10][2];

    int sizeOfAns = countFreq(arr, size, ans);

    for(int i = 0; i < sizeOfAns; i++) {
        cout << ans[i][0] << " --> " << ans[i][1] << endl;
    }

    return 0;
}