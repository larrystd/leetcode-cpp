// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuted_list;
    vector<int> visited;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited.assign(n, 0);
        vector<int> cur;
        trackback(nums, cur);
        return permuted_list;
    }

    void trackback(vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            permuted_list.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) {
                continue;
            }
            cur.push_back(nums[i]);
            visited[i] = 1;
            trackback(nums,cur);
            visited[i] = 0;
            cur.pop_back();
        }
    }
};