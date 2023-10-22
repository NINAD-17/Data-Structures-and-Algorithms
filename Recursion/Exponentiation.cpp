#include <iostream>
using namespace std;

int powerCalculate_rec(int &baseNum, int exponent) {
    // Base Case
    if(exponent == 0)
        return 1;
    
    // Recursive relation
    return 2 * powerCalculate_rec(baseNum, --exponent);
}

// Time complexity: O(exponent)
int powerCalculate(int &baseNum, int &exponent) {
    int ans = 1;

    for(int i = 0; i < exponent; i++)
        ans *= baseNum;
    
    return ans;
}

int main() {
    int baseNum, exponent;

    cout << "Enter a base number: ";
    cin >> baseNum;

    cout << "Enter an exponent: ";
    cin >> exponent;

    cout << baseNum << " raised to " << exponent << " without using recursion is " << powerCalculate(baseNum, exponent) << endl;
    cout << baseNum << " raised to " << exponent << " by using recursion is " << powerCalculate_rec(baseNum, exponent) << endl;

    return 0;
}