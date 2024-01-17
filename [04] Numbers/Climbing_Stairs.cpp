#include <iostream>
using namespace std;
    
int combination(int n, int k) {
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - (k - i);
        result /= i;
    }
    return result;
}

int climbStairs(int n) {
    int result = 0;
    for (int i = 0; i <= n / 2; i++) {
        result += combination(n - i, i);
    }
    return result;
}

int main() {

    int numOfStairs;

    cout << "Enter total number of stairs: ";
    cin >> numOfStairs;

    cout << "Total ways to climb to the top is " << climbStairs(numOfStairs) << endl;
    return 0;
}