#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int maxFreqNum(vector<int> &arr, int n) {
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++) {
        if(maxFreq == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main() {

    vector<int> arr = {1, 3, 2, 1, 3, 3};

    cout << maxFreqNum(arr, 6) << endl;

    return 0;
}