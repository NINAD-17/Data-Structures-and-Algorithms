#include <iostream>
using namespace std;

// Time complexity: O(log(min(a, b)))
int findGCD(int num1, int num2) {
    if(num1 == 0)
        return num2;

    if(num2 == 0)   
        return num1;
    
    int shift;
    for(shift = 0; ((num1 | num2) & 1 == 0); shift++) {
        num1 >>= 1;
        num2 >>= 1;
    }

    while(num1 & 1 == 0)
        num1 >>= 1;
    
    do {
        while(num2 & 1 == 0)
            num2 >>= 1;

        if(num1 > num2) 
            swap(num1, num2);
        
        num2 = num2 - num1;
    } while(num2 != 0);

    return num1 << shift;
}

int findLCM(int num1, int num2) {
    int gcd = findGCD(num1, num2);
    int lcm = (num1 * num2) / gcd;

    return lcm;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "LCM of " << num1 << " and " << num2 << " is " << findLCM(num1, num2) << endl;
    return 0;
}