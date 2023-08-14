#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(log(n))
int findFirstOcc(int *arr, int n, int key) {
    int st = 0, en = n - 1, index = INT_MIN;

    while(st <= en) {
        int mid = st + (en - st)/2;
        if(arr[mid] == key) {
            index = mid;
            en = mid - 1;
        }
        else if(arr[mid] < key)
            st = mid + 1;
        else    
            en = mid - 1;
    }

    return index;
}

int findLastOcc(int *arr, int n, int key) {
    int st = 0, en = n - 1, index = INT_MIN;

    while(st <= en) {
        int mid = st + (en - st)/2;
        if(arr[mid] == key) {
            index = mid;
            st = mid + 1;
        }
        else if(arr[mid] < key)
            st = mid + 1;
        else    
            en = mid - 1;
    }

    return index;
}

int findFirstAndLastOcc(int *arr, int size, int key, int *fandlOcc) {
    fandlOcc[0] = findFirstOcc(arr, size, key);
    fandlOcc[1] = findLastOcc(arr, size, key);
}

int main() {
    int arr[10], fandlOcc[2], size, key;

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter an element to search: ";
    cin >> key;

    findFirstAndLastOcc(arr, size, key, fandlOcc);
    if(fandlOcc[0] == INT_MIN)
        cout << "No element matched with " << key << endl;
    else 
        cout << "First Occ: " << fandlOcc[0] << "\nLast Occ: " << fandlOcc[1] << endl; 
    
    return 0;
}