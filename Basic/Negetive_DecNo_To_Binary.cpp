#include <iostream>
using namespace std;

int decToBin(int num) {
    int binary = 0, i = 0;
}

int negetiveNumToBinary(int num) {
    int flipBits = ~num;
    return flipBits;
}

int main() {

    int negetiveNum;

    cout << "Enter a negetive decimal number: ";
    cin >> negetiveNum;

    cout << "Binary of " << negetiveNum << " is " << negetiveNumToBinary(negetiveNum) << endl;
    return 0;
}