#include <iostream>
#include <algorithm>
using namespace std;

// Time complexity of both: O(log(n))

int main() {

    int arr[10];
    int n, k;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> k;

    cout << "Your array: ";
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;


    // Lower Bound
    int *ptr = lower_bound(arr, arr + n, k);    
    if(ptr == arr + n) {
        cout << "Not Found :(" << endl;
        return 0;
    }
    cout << "Lower Bound: " << (*ptr) << endl;

    // Upper Bound
    int *ptr2 = upper_bound(arr, arr + n, k);
    if(ptr2 == arr + n) {
        cout << "Not Found :(" << endl;
        return 0;
    }
    cout << "Upper Bound: " << (*ptr2) << endl;

    return 0;
}