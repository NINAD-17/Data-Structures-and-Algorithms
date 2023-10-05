#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Global Declaration
const int N = 1000000;
int sieve[N + 1];
void createSieve() {
    for(int i = 2; i <= N; i++) 
        sieve[i] = true;
    
    for(int i = 2; i <= N; i++) {
        if(sieve[i] == 1) {
            for(int j = i * i; j <= N; j+=i) 
                sieve[j] = false;
        }
    }
}

// Generating all the primes till sqrt of R
vector<int> generatePrimes(int N) {
    vector<int> ds;
    for(int i = 2; i <= N; i++) {
        if(sieve[i] == true) 
            ds.push_back(i);
    }
    return ds;
}

int main() {
    createSieve(); // TC: O(10^6)

    int testcases;
    cout << "Enter total number of testcases: ";
    cin >> testcases;

    while(testcases--) { // TC: O(testcases)
        int l, r;
        cout << "Enter a range in between you want prime numbers: \nleft -> ";
        cin >> l;
        cout << "Right -> ";
        cin >> r;

        // Step 1: Generate all primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        // Step 2: Create a dummy arr of size ((R - L) + 1) & mark that with 1
        int dummy[r - l + 1];
        for(int i = 0; i < (r - l + 1); i++)
            dummy[i] = 1;

        // Step 3: Mark all multiples of primes as false
        for(auto pr: primes) {
            int firstMultiple = (l/pr) * pr;
            if(firstMultiple < l) firstMultiple += pr;

            for(int j = max(firstMultiple, pr*pr); j <= r; j+=pr)
                dummy[j - l] = 0; // To find dummy index dummy[j - l]. Ex -> 110 - 110 = 0 index
        }

        for(int i = l; i <= r; i++) {
            if(dummy[i - l] == 1)
                cout << i << " ";
        }

        cout << endl;
    }
}