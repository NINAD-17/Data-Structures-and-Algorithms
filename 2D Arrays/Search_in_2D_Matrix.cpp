#include <iostream>
#include <vector>
using namespace std;

bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int st = 0, en = ((rows * cols) - 1);

    while(st < en) {
        int mid = st + (en - st) / 2;
        int element = matrix[mid/cols][mid%rows];
        if(element == target)
            return true;
        else if(element < target) 
            st = mid + 1;
        else 
            en = mid - 1;
    }

    return false;
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
    int rows, cols, target;

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

    cout << "Search an element: ";
    cin >> target;

    if(searchIn2DMatrix(arr, target))
        cout << "Element found" << endl;
    else 
        cout << "Element not found" << endl;
    
    return 0;
}