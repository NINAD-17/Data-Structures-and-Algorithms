#include <iostream>
using namespace std;

int peakIndexInMountainArray(int *arr, int n) {
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

int main() {
    int arr[10], size;

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    int peakInt = peakIndexInMountainArray(arr, size);
    cout << "Peak index in Mountain Array is " << peakInt << endl;

    return 0;
}