#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets_;
    vector<vector<int>> subsets(vector<int>& nums) {
        subsets_.push_back({});
        for (int i = 0; i < nums.size(); ++i) {
            findsets(nums, i);
        }
        return subsets_;
    }

    void findsets(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            return;
        }
        int n = subsets_.size();
        for (int i = 0; i < n; i++) {
            auto item = subsets_[i];
            item.push_back(nums[idx]);
            subsets_.emplace_back(item);
        }
    }
};