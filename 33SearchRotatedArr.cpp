/**
 * nums is possibly rotated at an unknown pivot中心；旋转 index k (1 <= k < nums.length) 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            // promise target is in closed [left, right]
            int mid = left + ((right-left) >> 1 );
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums.back()) {
                if (nums[mid] < target && nums[mid] >= nums[0]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if (nums[mid] > target && nums[mid] <= nums.back()) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << solu.search(nums, 3) <<endl;
    return 0;
}