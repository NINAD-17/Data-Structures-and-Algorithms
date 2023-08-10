#include <iostream>
using namespace std;

void printArr(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void updateArr(int *arr, int size) {
    arr[3] = 999;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before calling update function ---- \n";
    printArr(arr, 10);

    // Calling update function
    updateArr(arr, 10);

    cout << "After calling update function ---- \n";
    printArr(arr, 10);

    return 0;
}