#include <iostream>
using namespace std;

int exponentiation_rec(int num1, int num2) {
    if(num2 == 0)
        return 1;
    if(num2 == 1)
        return num1;

    int ans = exponentiation_rec(num1, num2/2);

    if(num2 & 1) { // Bitwise operations are generally faster than arithmetic operations Ex - (n % 2 == 0). Read from readme.md
        return num1 * ans * ans;
    } else 
        return ans * ans;
}

// Not a good solution, Use Fast Exponentiation method instead --> /Maths \For \DSA/fast_exponentiation.cpp
int exponentiation(int num1, int num2) {
    int ans = 1;
    for(int i = 0; i < num2; i++) 
        ans *= num1;
    
    return ans;
}

int main() {
    int num1, num2;

    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    cout << num1 << " raised to " << num2 << " is " << exponentiation_rec(num1, num2) << endl;
    return 0;
}