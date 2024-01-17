#include <iostream>
using namespace std;

void sort_0_1_twoptr(int *arr, int n) {
    int st = 0, en = n - 1;

    while(st < en) {
        if(arr[st] == 1 && arr[en] == 0)
            swap(arr[st++], arr[en--]);
        else if(arr[st] == 0)
            st++; 
        else if(arr[en] == 1)
            en--;
    }
}

// Brute Force Approach
// Time Complexity: 
void sort_0_1(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] == 0)
            continue;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] == 0) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = {0, 1, 1, 0, 0, 1};
    int n = 6;

    sort_0_1_twoptr(arr, n);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}