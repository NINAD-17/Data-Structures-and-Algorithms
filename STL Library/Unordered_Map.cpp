#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    vector<string> v = {"Galaxy", "Samsung", "Fold", "Galaxy", "Fold", "Galaxy"};

    unordered_map<string, int> uo_m;

    // Find frequency of string using unordered map
    // Time complexity: O(n)
    for(auto value: v) {
        cout << value << " ";
        uo_m[value]++;
    }
    cout << endl;

    for(auto value: uo_m)
        cout << value.first << " " << value.second << endl;
    cout << endl;    

    // ----------------------------------------------------------------//
    // Find frequency of string using map
    // Time complexity: O(n log(n))
    map<string, int> m;

    for(auto value: v) 
        m[value]++;
    
    for(auto value: m)
        cout << value.first << " " << value.second << endl;

    return 0;
}