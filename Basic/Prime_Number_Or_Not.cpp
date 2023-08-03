#include <iostream>
using namespace std;

// Time complexity of this code is O(n)
// isPrime() function check checks if num is divisible by any integer from 2 to num-1 
// using a for loop, which takes linear time in the worst case.

bool isPrime(int num) {
    
    for(int i = 2; i < num; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

int main() {

    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isPrime(num)) cout << "Given number is a Prime Number." << endl;
    else cout << "Given number is not a Prime Number" << endl;

    return 0;
}