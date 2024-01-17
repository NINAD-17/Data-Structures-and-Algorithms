#include <iostream>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

int selectionSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[10], size;

    cout << "Enter a size of an array: ";
    cin >> size;

    cout << "Enter " << size << " elements of an array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    selectionSort(arr, size);
    cout << "\nSelection Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}