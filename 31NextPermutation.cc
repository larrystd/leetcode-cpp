#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1) {
            return;
        }
        int seg = 0;
        bool islast = true;
        for (seg = length-1; seg>=1; --seg) {
            if (nums[seg] > nums[seg-1]) {
                islast = false;
                break;
            }
        }
        if (islast) {
            sort(nums.begin(), nums.end(), less<int>());
            return;
        }
        int right = length-1;
        while (nums[right] <= nums[seg-1]) {
            right--;
        }
        swap(nums[seg-1], nums[right]);
        sort(nums.begin()+seg, nums.end(), less<int>());
    }
};

int main() {
    vector<int> nums{3,2,1};
    Solution solu;
    solu.nextPermutation(nums);
    for (int num : nums) {
        cout << num <<"\n";
    }
    return 0;
}
