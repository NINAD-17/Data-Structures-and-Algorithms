#include <iostream>
using namespace std;

int incl_excl_principle(int n) {
    int count = 0;

    // count numbers divisible by 2
    for(int i = 2; i < n; i+=2) count++;

    // count numbers divisible by 3 
    for(int i = 3; i < n; i+=3) count++;

    // count numbers divisible by 5
    for(int i = 5; i < n; i+=5) count++;

    // count numbers divisible by 2 and 3 and then remove it from count
    for(int i = 6; i < n; i+=6) count--;

    // count numbers divisible by 2 and 5 and then remove it from count
    for(int i = 10; i < n; i+=10) count--;

    // count numbers divisible by 3 and 5 and then remove it from count
    for(int i = 15; i < n; i+=15) count--;

    // count numbers divisible by 2 and 3 and 5
    for(int i = 30; i < n; i+=30) count++;

    return count;
}

int main() {

    int n = 100;

    int count = incl_excl_principle(n);
    cout << "The number of positive integer less than " << n << " that are divisible by either 2, 3 or 5 is " << count  << endl;

    return 0;
}