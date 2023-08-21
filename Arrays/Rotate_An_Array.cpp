#include <iostream>
using namespace std;

// Time Complexity: O(n)

void rotateArr(int *arr, int n, int rotateBy, int *ans) {
    for(int i = 0; i < n; i++)
        ans[(i + rotateBy) % n] = arr[i];
}

void printArr(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[10] = {1, 7, 9, 11}, ans[10];
    int n = 4, rotateBy = 2;

    cout << "Before Rotation: ";
    printArr(arr, n);

    rotateArr(arr, n, rotateBy, ans);

    cout << "After Rotation: ";
    printArr(ans, n);

    return 0;
}