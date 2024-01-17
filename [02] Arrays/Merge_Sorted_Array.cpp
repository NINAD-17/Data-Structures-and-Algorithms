#include <iostream>
using namespace std;

// The time complexity of this function is O(n+m), where n is the size of the first array and m is the size of the second array.
// The space complexity of this function is O(1), as it does not use any additional memory.

void mergeTwoSortedArr_inNums1(int *nums1, int n, int *nums2, int m) {
    int i = n - 1, j = m - 1, k = (n + m) - 1;

    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--]; 
        else 
            nums1[k--] = nums2[j--];
    }

    while(j >= 0)
        nums1[k--] = nums2[j--];
}

// The time complexity of the mergeTwoSortedArr_BruteForce function is O(n+m), where n is the size of the first array and m is the size of the second array. This is because the function iterates over both arrays once, comparing and merging their elements into the answer array.
// The space complexity of the function is O(n+m), where n is the size of the first array and m is the size of the second array. This is because an additional array of size n+m is used to store the merged result.

void mergeTwoSortedArr_BruteForce(int *nums1, int n, int *nums2, int m, int *ans) {
    int i = 0, j = 0, k = 0;

    while(i < n && j < m) {
        if(nums1[i] == nums2[j]) {
            ans[k++] = nums1[i++];
            ans[k++] = nums2[j++];
        } else if(nums1[i] < nums2[j]) {
            ans[k++] = nums1[i++];
        } else {
            ans[k++] = nums2[j++];
        }
    }

    while(i < n)
        ans[k++] = nums1[i++];

    while(j < m)
        ans[k++] = nums2[j++];
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0}, nums2[3] = {2, 5, 6}, ans[6];
    int nums1Size = 3, nums2Size = 3, ansSize = 6;

    mergeTwoSortedArr_BruteForce(nums1, nums1Size, nums2, nums2Size, ans);

    for(int i = 0; i < ansSize; i++) 
        cout << ans[i] << " ";
    cout << endl;

    // Q. The final sorted array should not be returned by the function, but instead be stored inside the array nums1
    mergeTwoSortedArr_inNums1(nums1, nums1Size, nums2, nums2Size);

    for(int i = 0; i < nums1Size + nums2Size; i++)
        cout << nums1[i] << " ";
    cout << endl;

    return 0;
}