#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void sieveOfErastothenes(int limit, vector<int> &prime) {
    vector<bool> mark(limit + 1, true);
    mark[0] = mark[1] = false;

    for(int i = 2; i <= limit; i++) {
        if(mark[i]) {
            for(int j = i * i; j < limit; j += i)
                mark[j] = false;
        }
    }

    for(int i = 2; i < limit; i++) {
        if(mark[i]) {
            prime.push_back(i);
            cout << i << " ";
        }
    }
}

void segmentedSieve(int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    prime.reserve(limit);
    sieveOfErastothenes(limit, prime);

    int low = limit;
    int high = 2 * limit;

    while(low < n) {
        if(high >= n)
            high = n;
    }

    for(int i = 0; i < prime.size(); i++) {
        if(prime[i])
            cout << prime[i] << " ";
    }

    cout << endl;
}

int main() {
    int n = 50;

    cout << "Prime numbers smaller than " << n << " are: ";
    segmentedSieve(n);

    return 0;
}