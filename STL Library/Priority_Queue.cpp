#include <iostream>
#include <queue>
using namespace std;

int main() {

    // Max Heap: Whenever we'll fetch the element out, then that will always be the greatest element.
    priority_queue<int> maxi;

    // Min Heap: Whenever we'll fetch the element out, then that will always be the smallest element.
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(4);
    maxi.push(3);
    maxi.push(0);
    maxi.push(8);
    maxi.push(2);

    // Print maxi
    int n = maxi.size();
    for(int i = 0; i < n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;



    mini.push(1);
    mini.push(4);
    mini.push(3);
    mini.push(0);
    mini.push(8);
    mini.push(2);

    // Print maxi
    int m = mini.size();
    for(int i = 0; i < m; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    return 0;
}