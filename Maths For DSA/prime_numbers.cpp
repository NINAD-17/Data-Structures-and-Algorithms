#include <iostream>
using namespace std;

// time complexity: O(n)
bool isPrime(int num) {
    if(num <= 1) // Negetive number can't be a prime number.
        return false;

    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cin >> num;

    if(isPrime(num))
        cout << num << " is a prime number." << endl;
    else    
        cout << num << " is not a prime number." << endl;
    
    return 0;
}