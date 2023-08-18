#include <iostream>
#include <array>
using namespace std;

int main() {
    
    int basic[3] = {1, 2, 3}; // Normal Array

    array<int, 4> arr = {1, 2, 3, 4}; // STL array

    int size = arr.size();

    for(int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    
    cout << "\nElement at 2nd index: " << arr.at(2) << endl;
    cout << "Is empty or not? " << arr.empty() << endl;

    cout << "First Element: " << arr.front() << endl;
    cout << "Last Element: " << arr.back() << endl;
}