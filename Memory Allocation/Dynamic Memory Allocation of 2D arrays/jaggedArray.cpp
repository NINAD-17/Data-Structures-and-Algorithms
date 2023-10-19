#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    // Keep track of number of columns in each row
    int *count = new int[rows];

    // create a 2D array with number of rows.
    int **arr = new int*[rows];

    for(int i = 0; i < rows; i++) {
        int cols;

        // Get number of columns for each row
        cout << "Enter number of columns for row-" << i + 1 << ": ";
        cin >> cols;

        // Store number of columns in each row
        count[i] = cols;

        // Allocate columns for each row
        arr[i] = new int[cols];

        cout << "Enter " << cols << " elements: ";
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Output
    cout << "\n--------- Jagged Array --------- \n";
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < count[i]; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Deallocate memory
    for(int i = 0; i < rows; i++) 
        delete []arr[i];
    
    delete []arr;
    delete []count;

    return 0;
}