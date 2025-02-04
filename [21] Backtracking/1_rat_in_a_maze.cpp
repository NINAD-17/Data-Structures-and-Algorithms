#include <bits/stdc++.h>
using namespace std;

// RAT IN A MAZE
// time complexity: O(4 ^(n*n))
// space complexity: O(m * n)

// conditions - 
//      - 1. lexicographical: Down, Left, Right, Up (DLRU)
//      - 2. is safe to go: DLRU?
//              - curr pos should be 1
//              - block to be visited should not be visited
//              - block to be visited must be in the maze

bool isSafe(int new_x, int new_y, vector<vector<bool>> &visited, vector<vector<int>> &maze, int size) {
    if((new_x >= 0 && new_x < size) && (new_y >= 0 && new_y < size) && (visited[new_x][new_y] != 1) && (maze[new_x][new_y] == 1))
        return true;
    else 
        return false;
}

void solve(int x, int y, vector<vector<int>> &maze, int size, vector<string> &ans, vector<vector<bool>> &visited, string path) {
    // base case
    if(x == size - 1 && y == size - 1) {
        ans.push_back(path);
        return ;
    }

    // 4 movement: DLRU (lexicographically)
    visited[x][y] = 1;

    // Down - D
    if(isSafe(x + 1, y, visited, maze, size)) {
        path += "D";
        solve(x + 1, y, maze, size, ans, visited, path);
    }

    // Left - L
    if(isSafe(x, y - 1, visited, maze, size)) {
        path += "L";
        solve(x, y - 1, maze, size, ans, visited, path);
    }

    // Right - R
    if(isSafe(x, y + 1, visited, maze, size)) {
        path += "R";
        solve(x, y + 1, maze, size, ans, visited, path);
    }

    // Up - U
    if(isSafe(x - 1, y, visited, maze, size)) {
        path += "U";
        solve(x - 1, y, maze, size, ans, visited, path);
    }
    
    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &maze, int size) {
    vector<string> ans; // to store all possible paths
    vector<vector<bool>> visited(size, vector<bool> (size, 0)); // create visited 2D array similar to maze
    string path = ""; // one path

    if(maze[0][0] == 0)
        return ans;

    solve(0, 0, maze, size, ans, visited, path);
    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
                            
    int size = 4;
    vector<string> ans = searchMaze(maze, size);

    for(int i = 0; i < ans.size(); i++)
        cout << i + 1 << ") " << ans[i] << endl;
    cout << endl;

    return 0;
}