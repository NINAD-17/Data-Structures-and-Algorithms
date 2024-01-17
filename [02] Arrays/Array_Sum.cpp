#include <iostream>
using namespace std;

int arraySum(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {2, 7, 1, -4, 11};

    cout << "Sum of array elements is: " << arraySum(arr, 5) << endl;
    return 0;
}