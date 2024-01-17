#include <iostream>
using namespace std;

// Time Complexity: O(sqrt(n))
int sumOfFactors(int num) {
    int sum = 0;

    for(int i = 1; i * i <= num; i++) {
        if((num % i) == 0) {
            sum += i;

            if((num / i) != i)
                sum += (num / i);
        }
    }

    return sum;
}

int main() {
    int num;
    cin >> num;

    cout << "Sum of factors of " << num << " is " << sumOfFactors(num) << endl;
    return 0;
}