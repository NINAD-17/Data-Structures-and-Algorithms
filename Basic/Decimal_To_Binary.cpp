#include <iostream>
#include <cmath>
using namespace std;

int usingDivBy2Method(int decNum) {
    int binary = 0, i = 0;
    
    while(decNum != 0) {
        int remainder = decNum % 2;
        binary += (pow(10, i) * remainder);
        i++;
        decNum /= 10;
    }

    return binary;
}

int decToBin(int decNum) {
    int binaryNumber = 0, i = 0;

    int powerOfTen = 1;
        for (int j = 0; j < i; j++) {
            powerOfTen *= 10;
        }

    while(decNum != 0) {
        int binDigit = decNum & 1;
        binaryNumber += (powerOfTen * binDigit);
        i++;
        decNum = decNum >> 1;
    }

    return binaryNumber;
}

int main() {

    int decNum;

    cout << "----- Convert Decimal Number into Binary -----\n";
    cout << "Enter a number: ";
    cin >> decNum;

    cout << "Binary of " << decNum << " is " << decToBin(decNum) << endl;
    return 0;
}