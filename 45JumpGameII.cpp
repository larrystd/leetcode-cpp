#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        size_t length = nums.size();
        vector<int> dp(length, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                dp[i+j] = min(dp[i+j], dp[i+1]);
                if (i+j == length-1) {
                    return dp[i+j];
                }
            }
        }
        return dp[length-1];
    }
};