#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if((nums[i] + nums[j] == target)) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }

int main() {
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(arr, target);
    cout << "[ ";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "]" << endl;
}