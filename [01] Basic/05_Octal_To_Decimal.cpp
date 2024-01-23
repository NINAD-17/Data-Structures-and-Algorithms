#include <iostream>
#include <math.h>
using namespace std;

// Example:
// Octal Num: 156 ---> Dec-110; Octal Num: 322 ---> Dec-210

int octalToDec(int octalNum) {
    int decNum = 0, i = 0;

    while(octalNum != 0) {
        int lastDig = octalNum % 10;
        decNum += pow(8, i++) * lastDig;
        octalNum /= 10;
    }

    return decNum;
}

int main() {
    int num;

    cout << "Enter a number: " << endl;
    cin >> num;

    cout << "Decimal representation of Octal No. " << num << " is " << octalToDec(num) << endl;
    return 0;
}