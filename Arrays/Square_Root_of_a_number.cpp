#include <iostream>
using namespace std;

// Time complexity:
// The function findSqrt uses a binary search algorithm to find the square root of the input number, 
// which has a time complexity of O(log(n)). The function morePrecision uses a loop that runs p times, 
// where p is the precision, and has a time complexity of O(p).
// Therefore, the overall time complexity of this code is O(log(n) + p)

// Get More precise sqrt
double morePrecision(int num, int precision, int tempSoln) {
    double factor = 1;
    double ans = tempSoln;

    for(int i = 0; i < precision; i++) {
        factor /= 10;

        for(double j = ans; j * j < num; j += factor) 
            ans = j;
    }

    return ans;
}

// Here we're using long long because,
// if mid > INT range then our program will not work.
long long int findSqrt(int num) {
    int st = 0, en = num;
    long long int ans = -1;

    while(st <= en) {
        long long int mid = st + (en - st) / 2;
        if(mid * mid == num) 
            return mid;
        else if(mid * mid < num) {
            ans = mid;
            st = mid + 1;
        }
        else 
            en = mid - 1;
    }

    return ans * -1;
}

int main() {
    int num, precision;
    double morePreciseAns;

    cout << "Enter a number: ";
    cin >> num;

    int ans = findSqrt(num);
    if(ans < 0) {
        cout << "Given number has no perfect square root :(" << endl;
        cout << "How many decimal places you want in more precise ans? -> ";
        cin >> precision;
        cout << "Square root of " << num << " is " << morePrecision(num, precision, (ans * -1)) << endl;
    } else 
        cout << "Square root of " << num << " is " << ans << endl;

    return 0;
}