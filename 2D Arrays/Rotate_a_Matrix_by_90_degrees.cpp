#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n * m) => The space complexity of this code is also O(n*m), as a new matrix of size n*m is created to store the rotated matrix.
vector<vector<int>> rotateBy90Deg(vector<vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    vector<vector<int>> v;
    v.resize(cols);

    for(int i = 0; i < cols; i++)
        v[i].resize(rows);

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++)
            v[j][(arr.size() - 1) - i] = arr[i][j];
    }

    return v;
}

void printVector(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr;
    int rows, cols;

    cout << "Enter total number of rows & cols: \nRows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    arr.resize(rows);
    for(int i = 0; i < rows; i++)
        arr[i].resize(cols);
    
    cout << "Enter " << rows * cols << " elements: ";
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) 
            cin >> arr[row][col];
    }

    cout << "Your Matrix: " << endl;
    printVector(arr);

    vector<vector<int>> v = rotateBy90Deg(arr);
    cout << "\nRotated Matrix: \n";
    printVector(v);

    return 0;
}