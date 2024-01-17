#include <iostream>
#include <math.h>
using namespace std;

int findNumOfDigits(int num) {
    int numOfDigits = 0;

    while(num != 0) {
        numOfDigits++;
        num /= 10;
    }

    return numOfDigits;
}

bool isArmstrong(int num) {
    int sumOfCubesOfDig = 0, inputNum = num;
    int totalDigits = findNumOfDigits(num);

    while(num != 0) {
        int lastDig = num % 10;
        sumOfCubesOfDig += pow(lastDig, totalDigits);
        num /= 10;
    }

    return (sumOfCubesOfDig == inputNum);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isArmstrong(num))
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";
    
    return 0;
}