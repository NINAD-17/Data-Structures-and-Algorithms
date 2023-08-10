#include <iostream>
using namespace std;

// Time Complexity: O(n)

int findUniqueElement(int *arr, int size) {
    int uniqueElement = 0;
    for(int i = 0; i < size; i++) {
        uniqueElement ^= arr[i];
    }
    return uniqueElement;
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

    cout << "Unique element in this array is: " << findUniqueElement(arr, size) << endl;
    return 0;
}