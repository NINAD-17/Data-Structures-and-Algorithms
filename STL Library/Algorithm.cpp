#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVect(vector<int> v) {
    for(int value: v) 
        cout << value << " ";
    cout << endl;
}

int main() {

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "Finding 6: " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Finding 8: " << binary_search(v.begin(), v.end(), 8) << endl;

    int a = 6, b = 8;
    cout << "Max: " << max(a, b) << "\nMin: " << min(a, b) << endl;

    swap(a, b);
    cout << "a: " << a << "\nb: " << b << endl; 

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "Reversed String: " << s << endl;

    cout << "Before rotate: ";
    printVect(v);
    
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After rotate: ";
    printVect(v);

    sort(v.begin(), v.end());
    cout << "Sorted Vector: ";
    printVect(v);

    return 0;
}