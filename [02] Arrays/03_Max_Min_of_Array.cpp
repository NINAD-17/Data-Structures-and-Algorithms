#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(n)

int findMinMax(int *arr, int size) {
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < size; i++) {
        if(arr[i] < min) 
            min = arr[i];
        
        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum number is: " << min << endl;
    cout << "Maximum number is: " << max << endl;
}

int main() {
    int inputNum, arr[100] = {0};

    cout << "Enter size of Array (less than 100): ";
    cin >> inputNum;

    cout << "Enter " << inputNum << " array elements: " << endl;
    for(int i = 0; i < inputNum; i++) {
        cin >> arr[i];
    }

    findMinMax(arr, inputNum);
    return 0;
}