#include <iostream>
#include <algorithm>
using namespace std;

// Mean = (sum of all elements) / (number of elements)
// Median = The median of a sorted array of size N is defined as the middle element when N is odd and average of middle two elements when N is even.

// Time Complexity is O(n log n) because we used sort in median function.

double findMean(int *arr, int n) {
    int sum = 0; 
    for(int i = 0; i < n; i++) // TC = O(n)
        sum += arr[i];
    return (double)sum / n; // Cast sum to double before performing division otherwise it will give you o/p in integer
}

// Time Complexity = O(n log n)
double findMedian(int *arr, int n) {
    sort(arr, arr + n);
    int mid = (n - 1)/ 2;

    if((n % 2) != 0){
        return arr[mid];
    }
    else {
        double median = (arr[mid] + (arr[mid + 1])) / 2.0; // If you use 2 instead of 2.0 then it will divide that num with int 2 and o/p will also generate in int
        return median;
    }
}

int main() {
    int arr[10] = {1, 3, 4, 2, 6, 5, 8, 7};
    int n = 8;

    cout << "Mean: " << findMean(arr, n) << "\nMedian: " << findMedian(arr, n) << endl;
    return 0;
}