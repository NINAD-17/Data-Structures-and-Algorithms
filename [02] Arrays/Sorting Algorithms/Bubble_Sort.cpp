#include <iostream>
using namespace std;

// Time Complexity: O(N^2)

void swapElements(int *element1, int *element2) {
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

int bubbleSort(int *arr, int size) {
    for(int i = 1; i < size; i++) { // Rounds (n - 1)
        bool swapped = false;
        for(int j = 0; j < size - i; j++) { // Sorting j & j + 1
            if(arr[j] > arr[j + 1]) {
                swapElements(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

int main() {
    int arr[10], size;

    cout << "Enter a size of an array: ";
    cin >> size;

    cout << "Enter " << size << " elements of an array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    bubbleSort(arr, size);
    cout << "\nBubble Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}