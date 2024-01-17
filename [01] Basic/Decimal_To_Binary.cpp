#include <iostream>
#include <math.h>
using namespace std;

// Time complexity for both functions is O(log(n))
// Space complexit is O(1)

// Using division by 2 method
int usingDivBy2Method(int decNum) {
    int binary = 0, i = 0;
    
    while(decNum != 0) {
        int remainder = decNum % 2;
        binary += (pow(10, i) * remainder);
        i++;
        decNum /= 2;
    }

    return binary;
}

// Using AND operator
int decToBin(int decNum) {
    int binaryNumber = 0, i = 0;

    while(decNum != 0) {
        int binDigit = decNum & 1;
        binaryNumber += (pow(10, i) * binDigit);
        i++;
        decNum = decNum >> 1;
    }

    return binaryNumber;
}

int negetiveDecToBin(int num) {
    cout << "Binary of " << num << " is " << decToBin(num) << endl;
}

int main() {

    int decNum;

    cout << "----- Convert Decimal Number into Binary -----\n";
    cout << "Enter a number: ";
    cin >> decNum;

    cout << negetiveDecToBin(decNum) << endl;
    cout << "Binary of " << decNum << " is " << decToBin(decNum) << endl;
    return 0;
}