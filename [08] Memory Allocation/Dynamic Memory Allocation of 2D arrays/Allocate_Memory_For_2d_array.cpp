#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of cols: "; cin >> cols;
    
    /** Creation **/
    // Creating multiple rows (Or it's just an array but assuming each element of this array as a starting point of new array or a row)
    int **arr = new int*[rows];

    // For each element of that array, assign new array of size 'cols'
    for(int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    // Taking input
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }  
    
    // Output
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Releasing memory
    // Step 1: First we've deallocate memory taken by each elements array.
    for(int i = 0; i < rows; i++) 
        delete []arr[i];
    
    // Step 2: Release memory of `arr`
    delete []arr;

    return 0;
}