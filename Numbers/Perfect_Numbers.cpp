#include <iostream>
using namespace std;

// Time Complexity: O(sqrt(n))

int sumOfDivisors(int num) {
    int sum = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i;
            if((i != 1) && i != (num / i)) 
                sum += num / i;
        }
    }
    return sum;
}

bool isPerfect(int num) {
    return (sumOfDivisors(num) == num);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isPerfect(num)) 
        cout << num << " is a perfect number." << endl;
    else
        cout << num << " is not a perfect number." << endl;

    return 0;
}
