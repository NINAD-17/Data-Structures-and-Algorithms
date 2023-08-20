#include <iostream>
#include <set>
using namespace std;

void printSet(set<int> s) {
    cout << "Set -> ";
    for(int value: s)
        cout << value << " ";
    cout << endl;
}

int main() {

    set<int> s;

    // Add elements // Time complexity of insert is O(log(n))
    s.insert(8);
    s.insert(4);
    s.insert(1);
    s.insert(9);
    s.insert(8);
    s.insert(4);
    s.insert(1);
    s.insert(9);

    printSet(s);


    // Erase ----
    // s.erase(s.begin() + 2); // This will not work -> for explaination go to readme.md (set)

    // Instead use this
    s.erase(next(s.begin(), 2));
    printSet(s);


    // Count
    cout << "Is 5 is present? " << s.count(5) << endl;
    cout << "Is 4 is present? " << s.count(4) << endl;


    // Find
    set<int> :: iterator itr = s.find(4);
    cout << "Iterator value of 5: " << *itr << endl;


    // Set in decreasing order
    set <int, greater<int>> s_dec;

    s_dec.insert(1);
    s_dec.insert(2);
    s_dec.insert(3);
    s_dec.insert(4);

    for(auto value: s_dec)
        cout << value << " ";
    cout << endl;

    return 0;
}