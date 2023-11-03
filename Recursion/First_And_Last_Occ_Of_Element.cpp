#include <iostream>
using namespace std;

int findFirstOcc(int *arr, int st, int en) {
    // Base Case
    if(st > en)
        return -1; // No element found
    
    int mid = st + (en - st) / 2;
}

int main() {
    int arr[10];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " numbers of array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    

}