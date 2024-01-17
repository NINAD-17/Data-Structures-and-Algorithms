#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n^3)
// Space complexity: O(n^2)

vector<vector<int>> matrixMultiplication(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    vector<vector<int>> ans;
    ans.resize(matrix1.size());
    for(int i = 0; i < matrix1.size(); i++)
        ans[i].resize(matrix2[0].size());

    for(int row = 0; row < matrix1.size(); row++) {
        for(int col2 = 0; col2 < matrix2[0].size(); col2++) {
            for(int col1 = 0; col1 < matrix1[0].size(); col1++)
                ans[row][col2] += matrix1[row][col1] * matrix2[col1][col2];
        }
    }

    return ans;
}

void printVector(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;

    int rows1, cols1, rows2, cols2;

    cout << "Enter number of rows and cols for matrix 1: ";
    cin >> rows1 >> cols1;

    matrix1.resize(rows1);
    for(int row = 0; row < rows1; row++)
        matrix1[row].resize(cols1);

    cout << "Enter " << rows1 * cols1 << " elements: ";
    for(int row = 0; row < rows1; row++) {
        for(int col = 0; col < cols1; col++) 
            cin >> matrix1[row][col];
    }

    cout << "Enter number of rows and cols for matrix 2: ";
    cin >> rows2 >> cols2;

    matrix2.resize(rows2);
    for (int row = 0; row < rows2; row++)
        matrix2[row].resize(cols2);

    cout << "Enter " << rows2 * cols2 << " elements: ";
    for(int row = 0; row < rows2; row++) {
        for(int col = 0; col < cols2; col++) 
            cin >> matrix2[row][col];
    }

    cout << "Matrix1: \n" << endl;
    printVector(matrix1);

    cout << "\nMatrix2: \n" << endl;
    printVector(matrix2);

    cout << "\nMultiplication: \n" << endl;
    vector<vector<int>> ans = matrixMultiplication(matrix1, matrix2);
    printVector(ans);

    return 0;
}