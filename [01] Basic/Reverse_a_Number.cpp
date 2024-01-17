#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

// Note: INT_MAX and INT_MIN check
// This check is necessary because if ans is outside the range of values that can be 
// stored in an int, the subsequent calculation of ans = ans * 10 + lastDigit could result 
//in an incorrect value due to integer overflow or underflow.

int reverseANum(int num) {
    int ans = 0, i = 0;

    while(num != 0) {
        int lastDigit = num % 10;
        if(ans >= INT_MAX/10 || ans <= INT_MIN/10) {
            cout << "Error: Integer overflow or underflow occurred" << endl;
            return 0;
        } 
        ans = ans * 10 + lastDigit;
        num /= 10;
    }

    return ans;
}

int main() {
    
    int num;  

    cout << "NOTE: If calculation reach value greater than or smaller than INT limit then it will give you an error!" << endl; 
    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "INT_MAX: " << INT_MAX << endl;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Reversed number: " << reverseANum(num) << endl;
    return 0;
}