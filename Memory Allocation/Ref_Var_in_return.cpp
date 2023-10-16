#include <iostream>
using namespace std;

int& update(int n) {
    int a = 10;
    int &ans = a; // Storing value of a i.e 10 in ans variable.
    return ans; // returning ans variable as a reference.
}

int main() {
    int n = 5;

    int a = update(n);
    cout << a << endl;

    return 0;
}