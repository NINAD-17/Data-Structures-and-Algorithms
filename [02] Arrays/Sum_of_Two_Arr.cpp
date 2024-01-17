#include <iostream>
#include <algorithm>
using namespace std;

int addNumbers(int *num1, int n, int *num2, int m, int *ans) {
    int i = n - 1, j = m - 1, k = 0, carry = 0;

    while(i >= 0 && j >= 0) {
        int sum = num1[i--] + num2[j--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(i >= 0) {
        int sum = num1[i--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(j >= 0) {
        int sum = num2[j--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(carry) {
        int sum = carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    return k;
}

int addNumberArr(int *num1, int n, int *num2, int m, int *ans) {
    int i = n - 1, j = m - 1, k = max(n, m), carry = 0;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if(i >= 0) 
            sum += num1[i--];
        
        if(j >= 0)
            sum += num2[j--];

        ans[k--] = sum % 10;
        carry = sum / 10;
    }

    return max(n, m) - k;
} 

void printNum(int *num, int n) {
    for(int i = 0; i < n; i++)
        cout << num[i];
    cout << endl;
}

void inputNum(int *num, int n) {
    for(int i = 0; i < n; i++)
        cin >> num[i];
}

int main() {
    int num1[10], num2[10], num1Size, num2Size, ans[10];

    cout << "Enter total digits of number 1: ";
    cin >> num1Size;

    cout << "Enter total digits of number 2: ";
    cin >> num2Size;

    cout << "Enter number 1: ";
    inputNum(num1, num1Size);

    cout << "Enter number 2: ";
    inputNum(num2, num2Size);

    int sizeOfAns = addNumbers(num1, num1Size, num2, num2Size, ans);
    cout << "Addition of both numbers is ";
    printNum(ans, sizeOfAns);

    return 0;
}