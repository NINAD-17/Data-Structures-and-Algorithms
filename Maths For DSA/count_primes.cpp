#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

// Using Sieve of Eratosthenes
// time complexity: O(n log log n). This is because the Sieve of Eratosthenes algorithm runs in this time complexity. The outer loop runs n times and the inner loop runs approximately n / i times, where i is the current prime number. The sum of n / i for all i from 2 to n is approximately n log log n.
// Space complexity: O(n)
int countPrimesUsingSOE(int num) {
    int count = 0;
    vector<bool> prime(num + 1, true);

    prime[0] = prime[1] = false; // As 0 and 1 are none prime number

    for(int i = 2; i < num; i++) {
        if(isPrime(i)) {
            count++;

            for(int j = 2*i; j < num; j = j + i) 
                prime[j] = false;
        }
    }

    return count;
}

// Brute Force Approach
// Time complexity: O(n^2) because we're calculating isPrime function for each number between 2 and num
int countPrimes(int num) {
    int count = 0;
    
    for(int i = 2; i < num; i++) {
        if(isPrime(i))
            count++;
    }

    return count;
}

int main() {
    int num;
    cin >> num;

    int totalPrimeNumbers = countPrimesUsingSOE(num);
    cout << "Number of prime numbers which are strictly less than " << num << " is " << totalPrimeNumbers << endl;

    return 0;
}