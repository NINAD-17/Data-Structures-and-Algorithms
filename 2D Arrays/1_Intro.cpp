#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int row, int col, int target) {
    // Read reason of why we must have to include column size in parameters on readme.md
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            if(arr[row][col] == target)
                return true;
        }
    }
    return false;
}

int main() {

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // 3 * 4 = 12 elements
    int arr2[3][4] = {{5, 7, 8, 9}, {1, 2, 3, 4}, {6, 10, 12, 11}}; // To put specific values in specific columns and rows

    int arr[10][10];

    // Take Input
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            cout << "Enter an element for Row = " << row << " && Col = " << col << " --> ";
            cin >> arr[row][col];
        }
    }

    // Output
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(col == 2)
                cout << "| " << arr[row][col] << " |";
            else
                cout << "| " << arr[row][col] << " ";
        }
        cout << endl;
    }

    // Search an element
    int target;
    cout << "Enter an element to search: ";
    cin >> target;

    if(isPresent(arr1, 3, 4, target))
        cout << "Element found :)" << endl;
    else 
        cout << "Element is not found :(" << endl;

    return 0;
}