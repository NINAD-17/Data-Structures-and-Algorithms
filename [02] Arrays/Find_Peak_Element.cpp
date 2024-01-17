#include <iostream>
using namespace std;

int findPeak(int *arr, int n, int *allPeakElements) {
    int peakElement, k = 0;

    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            peakElement = arr[i];
            allPeakElements[k++] = peakElement;
        }
    }

    return k;
}

int main() {
    int arr[7] = {1,2,1,3,5,6,4}, allPeakElements[7];
    int n = 7;

    int peakElementsNo = findPeak(arr, n, allPeakElements);
    if(peakElementsNo == 0) {
        cout << "No peak elements found :(" << endl;
        return 0;
    }

    cout << "All peak elements: ";
    for(int i = 0; i < peakElementsNo; i++)
        cout << allPeakElements[i] << " ";
    cout << endl;
}