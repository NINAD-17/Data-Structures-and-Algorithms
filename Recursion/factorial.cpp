#include <iostream>
using namespace std;

int factorial_rec(int num) {
    // Base case
    if(num == 0)
        return 1;
    
    return num * factorial_rec(num - 1);
}

// Time complexity: O(num)
int factorial(int num) {
    int ans = 1;

    while(num != 1)
        ans *= num--;
    
    return ans;
}

int main() {
    int num; 

    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial of " << num << " without using recursion is " << factorial(num) << endl;
    cout << "Factorial of " << num << " using recursion is " << factorial_rec(num) << endl;

    return 0;
}