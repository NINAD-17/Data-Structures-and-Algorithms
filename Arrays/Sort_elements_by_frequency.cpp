#include <iostream>
#include <map>
using namespace std;

void sortElementsByFreq(int *arr, int n) {
    map<int, int> mp;
    int freqCnt = 1;

    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
}

int main() {
    int arr[8] = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = 8;


}