#include <iostream> 
using namespace std;

long long modularExponentiation(long long baseNum, long long exponent, long long modulus) {
    long long result = 1;

    while(exponent != 0) {
        if(exponent & 1) // Odd
            result = (result * baseNum) % modulus;
        
        baseNum = (baseNum * baseNum) % modulus;
        exponent = exponent >> 1; // Divide by 2;
    }

    return result;
}

int main() {
    long long baseNum, exponent, modulus;

    cout << "Enter BaseNum: "; cin >> baseNum;
    cout << "Enter Exponent: "; cin >> exponent;
    cout << "Enter Modulus: "; cin >> modulus;

    cout << "Result of (" << baseNum << " ^ " << exponent << ") % " << modulus << " is " << modularExponentiation(baseNum, exponent, modulus) << endl;
    return 0;
}