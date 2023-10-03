#include <iostream>
#include <math.h>
using namespace std;

// Time complexity: O(sqrt(n))
bool isPrime(int num) {
    int count = 0;

    for(int i = 1; i * i <= num; i++) { // i <= sqrt(num) If you use this then time complexity is O(sqrt(n) * log(n)) Because in every iteration this sqrt function will call and it takes O(log n) time.
        if((num % i) == 0) {
            count++;

            if((num / i) != i)
                count++;
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--) {
        int num;
        cin >> num;

        if(isPrime(num)) 
            cout << "Yes";
        else
            cout << "No";
    }
}
