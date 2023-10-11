#include <iostream>
using namespace std;

// Time complexity: O(1)
int incl_excl_principle2(int n) {
    int divBy2 = n / 2;
    int divBy3 = n / 3;
    int divBy5 = n / 5;
    int divBy2n3 = n / (2 * 3);
    int divBy2n5 = n / (2 * 5);
    int divBy3n5 = n / (3 * 5);
    int divBy2n3n5 = n / (2 * 3 * 5);

    return divBy2 + divBy3 + divBy5 - divBy2n3 - divBy2n5 - divBy3n5 + divBy2n3n5;
}


// Time complexity: O(n)
int incl_excl_principle(int n) {
    int count = 0;

    // count numbers divisible by 2
    for(int i = 2; i <= n; i+=2) count++;

    // count numbers divisible by 3 
    for(int i = 3; i <= n; i+=3) count++;

    // count numbers divisible by 5
    for(int i = 5; i <= n; i+=5) count++;

    // count numbers divisible by 2 and 3 and then remove it from count
    for(int i = 6; i <= n; i+=6) count--;

    // count numbers divisible by 2 and 5 and then remove it from count
    for(int i = 10; i <= n; i+=10) count--;

    // count numbers divisible by 3 and 5 and then remove it from count
    for(int i = 15; i <= n; i+=15) count--;

    // count numbers divisible by 2 and 3 and 5
    for(int i = 30; i <= n; i+=30) count++;

    return count;
}

int main() {

    int n = 100;

    int count = incl_excl_principle(n);
    cout << "The number of positive integer less than " << n << " that are divisible by either 2, 3 or 5 is " << count  << endl;
    cout << "The number of positive integer less than " << n << " that are divisible by either 2, 3 or 5 is " << incl_excl_principle2(n) << endl;

    return 0;
}