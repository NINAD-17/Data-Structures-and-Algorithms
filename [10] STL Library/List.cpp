#include <iostream>
#include <list>
using namespace std;

void printList(list<int> l) {
    for(list<int>::iterator i = l.begin(); i != l.end(); i++) 
        cout << *i << " ";
    cout << endl;
    // Or you can just use
    // for(int i: l) cout << i << " ";
}

int main() {

    list<int> l;

    // Add elements
    l.push_back(1);
    l.push_front(2);

    // Printing List
    printList(l);

    // erase
    l.erase(l.begin()); // O(n) time complexity
    cout << "After erase: ";
    printList(l);


    // Copy a list
    list<int> l_copy(l);
    printList(l_copy);

    // initialize elements with 100
    list<int> l_initialize(5, 100);
    printList(l_initialize);
    
    return 0;
}