#include <iostream>
#include <math.h>
using namespace std;

// Time Complexity:  O(log(n))
// Space complexity: O(1)

int binToDec(int binaryNo) {
    int ans = 0, i = 0;

    while(binaryNo != 0) {
        int digit = binaryNo % 10;
        ans += pow(2, i++) * digit;
        binaryNo /= 10;
    }

    return ans;
}

int main() {

    int binaryNo;

    cout << "Enter a binary number: ";
    cin >> binaryNo;

    cout << "Decimal representation of binary number " << binaryNo << " is " << binToDec(binaryNo) << endl;
    return 0;
}