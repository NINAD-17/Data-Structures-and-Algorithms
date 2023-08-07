#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

// Time Complexity: O(log(n))
// Space Complexity: O(1)

char assignLetterToHexaDecDigit(int digit) {
    // char arr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    // int lastDig = digit % 10;
    // return arr[lastDig];

    return char(digit - 10 + 'A'); // Time complexity: O(1), since it performs a simple arithmetic operation.
}

string decToHexadecimal(int decNum) {
    string hexaDecNum = "";

    while(decNum != 0) {
        int remainder = decNum % 16;

        if(remainder >= 10)
            hexaDecNum += assignLetterToHexaDecDigit(remainder);
        else 
            hexaDecNum += to_string(remainder);

        decNum /= 16;
    }

    reverse(hexaDecNum.begin(), hexaDecNum.end());
    return hexaDecNum;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Decimal Number " << num << " to Hexadecimal: " << decToHexadecimal(num) << endl;
    return 0;
}