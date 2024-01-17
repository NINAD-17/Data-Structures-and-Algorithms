#include <iostream>
#include <math.h>
using namespace std;

int decimalToOctal(int decNum) {
    int octalNum = 0, i = 0;

    while(decNum != 0) {
        int octalDigit = decNum % 8;
        octalNum += pow(10, i++) * octalDigit;
        decNum = decNum / 8;
    }

    return octalNum;
}

int main() {

    int decNum;
    cout << "Enter a number: ";
    cin >> decNum;

    cout << "Octal representation of " << decNum << " is " << decimalToOctal(decNum) << endl;
    return 0;
}