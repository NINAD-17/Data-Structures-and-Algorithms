#include <iostream>
using namespace std;

// Time complexity: O(n)
void sort_0_1_2(int *arr, int n) {
    int count_0 = 0, count_1 = 0, count_2 = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0)
            count_0++;
        else if(arr[i] == 1)
            count_1++;
        else count_2++;

        arr[i] = 2;
    }

    cout << "Counts: " << count_0 << " " << count_1 << " " << count_2 << endl;

    int i = 0;

    while(count_0 > 0) {
        arr[i++] = 0;
        count_0--;
    }

    while(count_1 > 0) {
        arr[i++] = 1;
        count_1--;
    }

    while(count_2 > 0) {
        arr[i++] = 2;
        count_2--;
    }
}

int main() {
    int arr[10] = { 0, 1, 2, 1, 2, 1, 2 };
    int n = 7;

    sort_0_1_2(arr, n);

    // Output
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}