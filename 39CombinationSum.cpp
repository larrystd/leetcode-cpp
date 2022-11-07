/**
 * In backtrack algorithm, push element in stack means add a new level in recusive tree
 * So down pushing stack time means decrease level of recusive tree, i.e., pruning
 * In this problem, sort candidates along greater would achieve it
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combination_set;
    int target_;
    vector<int> candidates_;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        target_ = target;
        candidates_ = candidates;
        sort(candidates_.begin(), candidates_.end(), greater<int>());
        vector<int> combination;
        findCombination(combination, 0, 0);
        return combination_set;
    }

    void findCombination(vector<int>& combination, int curSum, int idx) {
        if (target_ < curSum) {
            return;
        }
        if (target_ == curSum) {
            combination_set.emplace_back(combination);
            return;
        }
        for (int i = idx; i < candidates_.size(); ++i) {
            combination.push_back(candidates_[i]);
            findCombination(combination, curSum+candidates_[i], i);
            combination.pop_back();
        }
    }
};

int main() {
    Solution solu;
    vector<int> candidates = {3};
    int target = 2;
    vector<vector<int>> result = solu.combinationSum(candidates,target);
    for (auto& l : result) {
        for (int e : l) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}