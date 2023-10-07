#include <iostream>
using namespace std;

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

    cout << "GCD of numbers " << num1 << " and " << num2 << " is " << findGCD_UsingModulus(num1, num2) << endl;
    return 0;
}