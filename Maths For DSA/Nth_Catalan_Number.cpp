#include <iostream>
#include <vector>
using namespace std;

// This program uses dynamic programming concept
// Note: I don't learn dynamic programming yet. So I've took this code from internet. For future reference.

// Time Complexity: O(n^2)
// Space complexity: O(n)
unsigned long int catalanNo(unsigned int num) {
    vector<unsigned long int> res(num + 1);

    res[0] = res[1] = 1;

    for(int i = 2; i <= num; i++) {
        res[i] = 0;
        for(int j = 0; j < i; j++) 
            res[i] += res[j] * res[i - j - 1];
    }

    return res[num];
}

int main() {
    int num;

    cout << "Enter how many catalan number you want from 0? ";
    cin >> num;

    for(int i = 0; i < num; i++) 
        cout << catalanNo(i) << " ";
    cout << endl;

    return 0;
}