#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {0}; // Initialized with 0;
    printArr(arr, 10);

    int arr2[100] = {1}; // It will only initialize first place with 1;
    printArr(arr2, 10);

    int arr3[100] = {0};
    for(int i = 0; i < 100; i++) {
        arr3[i] = 1; // Here we manually initialized all elements with 1;
    }
    printArr(arr3, 10);


    // Types of array
    bool boolArr[10] = {true, false};
    float floatArr[10];
    double doubleArr[10];

    return 0;
}