#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(N + M)
// This is because the function intersectionOfTwoSortedArr uses two pointers to iterate through both arrays simultaneously, and in the worst case, it will iterate through all elements of both arrays.

void intersectionOfTwoSortedArr(int *arr1, int n, int *arr2, int m, int *intersection) {
    int i = 0, j = 0, k = 0;
    if(n == 0 || m == 0) {
        cout << "One array is empty!" << endl;
        return;
    }

    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            intersection[k++] = arr1[i];
            i++, j++;
        } else if(arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
}

int main() {
    int arr1[10] = {1, 2, 2, 2, 3, 4};
    int arr2[10] = {2, 2, 3, 3};
    int n = 6, m = 4;
    int intersection[10], i = 0;

    for(int i = 0; i < 10; i++)
        intersection[i] = INT_MIN;

    intersectionOfTwoSortedArr(arr1, n, arr2, m, intersection);

    cout << "Intersection of two sorted arrays: ";
    while(i < 10) {
        if(intersection[i] == INT_MIN) { // To know that all intersected elements are printed
            if(intersection[0] == INT_MIN) { // If any array is empty
                cout << "No intersection :(" << endl;
                break;
            }
            break;
        }
        cout << intersection[i] << " ";
        i++;
    }

    cout << endl;
    return 0;
}