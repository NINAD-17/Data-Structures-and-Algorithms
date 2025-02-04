#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// MAX RECTANGLE IN BINARY MATRIX WITH ALL 1's
// time complexity:
// space complexity: 
int maxAreaOfRectangle(vector<int> &heights) {
    int totalBars = heights.size();

    // find next smallest element
    int next = nextSmallestElement(heights, totalBars);

    // find prev smallest element
    int prev = prevSmallestElement(heights, totalBars);

    // find max area
    int maxArea = 
}

int main() {

    vector<vector<int>> binMatrix = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    cout << "maximum area of rectangle in binary matrix is " << "" << endl;

    return 0;
}