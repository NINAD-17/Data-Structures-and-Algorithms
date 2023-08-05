#include <iostream>
#include <math.h>
using namespace std;

// Small Code
int compOfBase10Int(int base10Int) {
    int ans = 0, mask = 0;
    int temp = base10Int;

    while(temp != 0) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    ans = (~base10Int) & mask;
    return ans;
}

// Lengthy code written by me
int complimentOfBase10Int(int base10Int) {
    int count = 0, ans = 0, i = 0;
    int complimentOfInt = ~base10Int;

    while(base10Int != 0) {
        count++;
        base10Int >>= 1;
    }
    cout << count << " " << base10Int << endl;

    while(count != 0) {
        int bit = complimentOfInt & 1;
        ans += pow(10, i++) * bit;
        complimentOfInt >>= 1;
        count--;
    }

    return ans;
}

int main() {

    int base10Int;

    cout << "Enter a number: ";
    cin >> base10Int;

    cout << "Compliment of " << base10Int << " is " << complimentOfBase10Int(base10Int) << endl;
    cout << "Compliment of " << base10Int << " is " << compOfBase10Int(base10Int) << endl;

    return 0;
}