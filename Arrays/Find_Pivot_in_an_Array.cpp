#include <iostream>
using namespace std;

// time complexity: O(log(n))
int findPivot_greater(int *arr, int n) {
    int st = 0, en = n - 1;

    while(st < en) {
        int mid = st + (en - st) / 2;
        if(arr[mid] < arr[mid + 1]) 
            st = mid + 1;
        else    
            en = mid;
    }

    return st;
}

int findPivot_smaller(int *arr, int n) {
    int st = 0, en = n - 1;

    while(st < en) {
        int mid = st + (en - st)/2;
        if(arr[mid] >= arr[0])
            st = mid + 1;
        else 
            en = mid;
    }

    return st;
}

int main() {
    int arr[10], size;

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " number of elements: ";
    for(int i = 0; i < size; i++) 
        cin >> arr[i];

    cout << "Pivot (If we consider smallest number as a pivot) is " << findPivot_smaller(arr, size) << endl;
    cout << "Pivot (If we consider smallest number as a pivot) is " << findPivot_greater(arr, size) << endl;

    return 0;
}