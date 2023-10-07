#include <iostream>
using namespace std;

// Time Complexity: O(log(min(a, b)))
// Space complexity: O(n)
int findGCD_UsingBinaryGCDAlgo(int num1, int num2) {
    if(num1 == 0)
        return num2;
    
    if(num2 == 0)
        return num1;
    
    int shift;
    for(shift = 0; (num1 | num2) & 1 == 0; shift++) {
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

// 


// Time Complexity: O(log(min(num1, num2)))
// Space Complexity : O(1) 
int findGCD_UsingModulus(int num1, int num2) {
    while(num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return num1;
}

// Time Complexity: O(max(num1, num2))
// Space Complexity: O(1)
int findGCD_UsingSubstraction(int num1, int num2) {
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

// Time Complexity: O(min(num1, num2))
// Space Complexity: O(1)
int findGCD_BruteForce(int num1, int num2) {
    int ans = 1;

    for(int i = 0; i <= min(num1, num2); i++) {
        if((num1 % i) == 0 && (num2 % i) == 0)
            ans = i;
    }

    return ans;
}

int main() {
    int num1, num2;

    cout << "Enter number-1: "; cin >> num1;
    cout << "Enter number-2: "; cin >> num2;

    cout << "GCD of numbers " << num1 << " and " << num2 << " is " << findGCD_UsingBinaryGCDAlgo(num1, num2) << endl;
    return 0;
}