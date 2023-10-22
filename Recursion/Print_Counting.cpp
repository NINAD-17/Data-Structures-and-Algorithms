#include <iostream>
using namespace std;

void printCountingIncr(int num) {
    // Base Case
    if(num == 0)
        return;

    // Recursive Relation
    printCountingIncr(num - 1);

    // Processing
    cout << num << " ";
}

void printCountingDec(int num) {
    // Base Case
    if(num == 0)
        return;

    // Processing
    cout << num << " ";

    // Recursive Relation
    printCountingDec(num - 1);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "In Decreasing Order: ";
    printCountingDec(num);

    cout << "\nIn Increasing Order: ";
    printCountingIncr(num);

    return 0;
}