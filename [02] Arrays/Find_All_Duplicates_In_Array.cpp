#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

void findAllDuplicates(int *arr, int size, int* ansArr) {
    int k = 0;
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] == INT_MIN)
            continue;
        
        int it = 0;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                if(it == 0)
                    ansArr[k++] = arr[i++];
                else   
                    it++;
                arr[j] = INT_MIN;
            } 
        }
        it = 0;
    }
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {

    int arr[10], ansArr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    for(int i = 0; i < size; i++) 
        ansArr[i] = INT_MIN;
    
    findAllDuplicates(arr, size, ansArr);

    if(ansArr[0] == INT_MIN)
        cout << "No duplicate element is found" << endl;
    else {
        cout << "Duplicate Elements are: ";
        for(int i = 0; i < size; i++) {
            if(ansArr[i] == INT_MIN)
                break;
            cout << ansArr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}