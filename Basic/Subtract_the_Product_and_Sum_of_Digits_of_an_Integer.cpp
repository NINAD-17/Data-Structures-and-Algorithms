#include <iostream>
using namespace std;

// Time Complexity: O(log(n))
// The number of iterations of the loop is equal to the number of digits in n. Since n is represented in base 10, it has log(n) digits. Therefore, the while loop runs for log(n) iterations, and its overall time complexity is O(log(n))
// All operations inside function takes constant time.

// Space Complexity: O(1)
// O(1), since it uses a constant amount of additional space to store the variables sum, prod, and lastDigit.

int subtractProductAndSum(int n) {
        int sum = 0, prod = 1;
        
        while(n != 0) {
            int lastDigit = n % 10;
            sum += lastDigit;
            prod *= lastDigit;
            n /= 10;
        }

        return (prod - sum);
}

int main() {

    int num; 

    cout << "Enter any number: ";
    cin >> num;

    cout << "Difference between product and sum of number's digit is " << subtractProductAndSum(num) << endl;
}