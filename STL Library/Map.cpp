#include <iostream>
#include <map>
using namespace std;

// time complextiy of insert, find, erase is O(log(n))
// Because this map is implemented by red black tree or balance tree
// Unordered map is implement using hash table -> time complexity O(1)

void printMap(map<int, string> m) {
    for (auto value : m)
        cout << value.first << " " << value.second << endl;
    cout << endl;
}

int main() {

    map<int, string> m;

    m[5] = "Jimin";
    m[4] = "Hoseok";
    m.insert({7, "Junkook"});
    m.insert({6, "Taehyung"}); // Other method to insert

    printMap(m);

    cout << "Finding 6 -> " << m.count(6) << endl;

    m.erase(6);
    cout << "After Erasing: ";
    printMap(m);

    // Find
    auto it = m.find(5);
    for(auto i = it; i != m.end(); i++)
        cout << (*i).first << " " << (*i).second << endl;
    cout << endl;

    m.clear(); // To remove all elements from map container
    printMap(m);

    return 0;
}