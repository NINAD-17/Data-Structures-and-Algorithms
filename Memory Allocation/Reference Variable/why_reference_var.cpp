#include <iostream>
using namespace std;

void passByReference(int &n) {
    n++; // Change directly in main function's n variable.
}

void passByValue(int n) {
    n++; // Change valid in only this function and it'll not change actual value of n which is in main function.
}

int main() {
    int n = 5;

    cout << "Before n: " << n << endl;
    cout << "-- Pass By Value --" << endl;
    passByValue(n);
    cout << "After n: " << n << endl << endl;

    cout << "Before n: " << n << endl;
    cout << "-- Pass By Reference --" << endl;
    passByReference(n);
    cout << "After n: " << n << endl << endl;

    return 0;
}