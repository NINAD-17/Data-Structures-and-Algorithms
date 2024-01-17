#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> d) {
    for(int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
}

int main() {

    // Create Deque
    deque<int> d;

    // Add elements
    d.push_back(1);
    d.push_front(2); // Other option
    printDeque(d); // 2 1

    // Remove elements
    d.pop_back();
    printDeque(d); // 2

    d.push_back(3); // 2 3
    printDeque(d);
    d.pop_front(); // 3
    printDeque(d);


    d.push_front(2);
    d.push_front(1);
    d.push_back(4);
    printDeque(d);

    // Find element
    cout << "First Element -> " << d.at(1) << endl;
    cout << "Front element -> " << d.front() << endl;
    cout << "Back element -> " << d.back() << endl;

    cout << "Is empty? " << d.empty() << endl;


    // Erase -> you've to give range of elements to delete
    d.erase(d.begin(), d.begin() + 1); // to delete first element


    // Size and maxSize here they're similar to vector's size and capacity respectively
    // size => num of elements present
    // max size => memory allocated to you deque
    printDeque(d);
    cout << "Size => " << d.size() << endl;
    cout << "Max-size => " << d.max_size() << endl;

    return 0;
}