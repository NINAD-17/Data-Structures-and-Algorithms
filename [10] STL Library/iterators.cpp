#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4};

    // Print using Iterator
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Automatically guess data type
    vector<int> v1 = {0, 1, 2, 3};
    for(auto it = v1.begin(); it != v1.end(); it++)
        cout << (*it) << " ";
    cout << endl;

    // Another method: Range based loops
    vector<int> v2 = {5, 6, 7, 8, 9};
    for(int value: v2) 
        cout << value << " ";
    cout << endl;


    // Example 2:
    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {4, 5}};
    for(auto value: v_p) // here auto = pair<int, int>
        cout << value.first << " " << value.second << endl;

    // Another method to cout first and second
    vector<pair<int, int>> :: iterator j;
    for(j = v_p.begin(); j != v_p.end(); j++) {
        cout << (*j).first << " " << (*j).second << endl; 
        // OR
        cout << j -> first << " " << j -> second << endl;
    }

    return 0;
}