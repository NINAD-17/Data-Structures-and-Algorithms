#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Optimized approach:
// Time Complexity: This approach has a time complexity of O(n log n) due to the sorting step.
bool areUniqueWithOccurrences(int *arr, int size) {
    // Sort Array
    sort(arr, arr + size);

    int occuranceArr[100] = {0};
    int count = 1, k = 0;

    for(int i = 1; i < size; i++) {
        if(arr[i] == arr[i - 1])
            count++;
        else {
            occuranceArr[k++] = count;
            count = 1;
        }
    }
    occuranceArr[k++] = count; // For last element

    sort(occuranceArr, occuranceArr + k);
    for(int i = 1; i < k; i++) {
        if(occuranceArr[i] == occuranceArr[i - 1])
            return false;
    }

    return true;
}

// Worst Approach
// Time Complexity: O(n^2)  ---- because the function uses two nested for loops to count the number of occurrences of each element in the input array and to check if the number of occurrences of each element is unique.
// Space complexity: O(n) ----  because the function uses an additional occurrencesArr array of size n to store the number of occurrences of each element in the input array.
bool isUniqueArrayByOccaurrences(int *arr, int size) {
    int count = 0, k = 0, current = INT_MIN, tempSize = 0;
    int occurrencesArr[100] = {0}, uniqueNo[100] = {0};
    
    sort(arr, arr + size);

    for(int i = 0; i < size; i++) {
        if(current == arr[i]) 
            continue;

        for(int j = i; j < size; j++) {
            if(arr[i] == arr[j])
                count++;
            else    
                break;
        }
        uniqueNo[k] = arr[i];
        occurrencesArr[k++] = count;
        tempSize = k;
        count = 0;
        current = arr[i]; // update
    }

    for(int i = 0; i < tempSize; i++) {
        for(int j = i + 1; j < tempSize; j++) {
            if(occurrencesArr[i] == occurrencesArr[j])
                return false;
        }
    }

    // Print
    cout << "Array element ----> Occuarances" << endl; 
    for(int i = 0; i < k; i++) {
        cout << uniqueNo[i] << " --------------> " << occurrencesArr[i] << endl;
    }
    return true;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {
    int arr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    if(areUniqueWithOccurrences(arr, size)) 
        cout << "Array element has unique number of occurances." << endl;
    else 
        cout << "Array elements hasn't unique number of occurances." << endl;

    return 0;
}