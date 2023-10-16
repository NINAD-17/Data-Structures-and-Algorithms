#include <iostream>
using namespace std;

int main() {
    int i = 5;

    int &j = i; // Create Ref Variable

    cout << "Value of i: " << i << endl;
    cout << "Value of j: " << j << endl << endl;

    i++;
    cout << "Value of i: " << i << endl;
    cout << "Value of j: " << j << endl << endl;

    j++;
    cout << "Value of i: " << i << endl;
    cout << "Value of j: " << j << endl << endl;

    return 0;
}