#include <iostream>
using namespace std;

int findGCD(int num1, int num2) {
    if(num1 == 0) 
        return num2;

    if(num2 == 0)
        return num1;
    
    while(num1 != num2) {
        if(num1 > num2) 
            num1 = num1 - num2;
        else
            num2 = num2 - num1;
    }

    return num1;
}

int main() {
    int num1, num2;

    cout << "Enter number-1: "; cin >> num1;
    cout << "Enter number-2: "; cin >> num2;

    cout << "GCD of numbers " << num1 << " and " << num2 << " is " << findGCD(num1, num2) << endl;
    return 0;
}