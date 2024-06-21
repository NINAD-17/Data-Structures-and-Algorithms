#include <iostream>
using namespace std;

// Time complexity: O(n)

int factorial_rec_generalOrder(int num, int ans) {
    if(num == 1)
        return ans;
    
    ans *= num;
    cout << ans << " "; // It's order is 5 20 60 120 and then it will return 120

    return factorial_rec_generalOrder(num - 1, ans);
}

int factorial_rec(int num) {
    // Base case
    if(num == 0)
        return 1;

    // it's order is 5 4 3 2 1 and then 1 2 6 24 120
    cout << num << " ";
    
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

    cout << "Factorial of " << num << " without using recursion is " << factorial(num) << endl << endl;
    cout << "Factorial of " << num << " using recursion is " << factorial_rec(num) << endl << endl;
    cout << "Factorial of " << num << " using recursion (general order) is " << factorial_rec_generalOrder(num, 1) << endl << endl;

    return 0;
}