#include <iostream>
using namespace std;

// Time Complexity: O(n);
void swapAlternate(int *arr, int size) {
    int i = 0;
    while(i < size - 1) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        i += 2;
    }
}

void printArr(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {
    int arr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    swapAlternate(arr, size);
    printArr(arr, size);

    return 0;
}