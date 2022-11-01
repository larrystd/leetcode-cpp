#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> num_of_generate;
    vector<string> generateParenthesis(int n) {
        string current("");
        recursiveGenerate(0, 0, n, current);
        return num_of_generate;
    }

    void recursiveGenerate(int leftnum, int rightnum, int n, string& current) {
        if (rightnum == leftnum && leftnum == n) {
            num_of_generate.emplace_back(current);
            return;
        }
        if (leftnum > n || rightnum > n)
            return;
        if (rightnum > leftnum)
            return;
        if (leftnum == rightnum) {
            current.push_back('(');
            recursiveGenerate(leftnum+1, rightnum, n, current);
            current.pop_back();
        } else {
            current.push_back('(');
            recursiveGenerate(leftnum+1, rightnum, n, current);
            current.pop_back();
            current.push_back(')');
            recursiveGenerate(leftnum, rightnum+1, n, current);
            current.pop_back();
        }
    }
};

int main() {
    Solution solu;
    auto items = solu.generateParenthesis(2);
    for (auto item : items) {
        cout << item << "\n";
    }
    return 0;
}