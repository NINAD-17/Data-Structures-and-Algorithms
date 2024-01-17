#include <iostream>
#include <utility>
using namespace std;

int main() {

    pair<int, string> p;

    // Make pair
    p = make_pair(2, "abc");
    cout << p.first << " " << p.second << endl;

    // Here adding new pair values to same p pair. Therefore values (2, "abc") update to (2, "def");
    p = {2, "def"}; // alternate for make_pair()
    cout << p.first << " " << p.second << endl;


    // Copy pair to new pair
    pair<int, string> p1 = p;
    cout << p1.first << " " << p1.second << endl;


    // Pair array: Instead you can use 'vector of pairs'
    pair<int, int> pArr[10];
    pArr[0] = {1, 2};
    pArr[1] = {3, 4};
    pArr[2] = {5, 6};

    for(int i = 0; i < 3; i++)
        cout << pArr[i].first << " " << pArr[i].second << " " << endl;

    return 0;
}