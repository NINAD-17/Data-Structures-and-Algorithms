#include <iostream>
using namespace std;

// time Complexity: O(n)

int linearSearch(int *arr, int size, int key) {
    for(int i = 0; i < size; i++) {
        if(key == arr[i])
            return i;
    }
    return -1;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {
    int arr[100] = {0};
    int size, key;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    cout << "Enter a number to search: "; 
    cin >> key;

    int foundAt = linearSearch(arr, size, key);

    if(foundAt != -1)
        cout << "Number is found at array index: " << foundAt << endl;
    else    
        cout << "Number is not found :(" << endl;  

    return 0;
}