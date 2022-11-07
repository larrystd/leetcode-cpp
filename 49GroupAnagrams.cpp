#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> str_set;
        vector<vector<string>> anagrams_group;
        for (auto& str : strs) {
            string str_backup = str;
            sort(str_backup.begin(), str_backup.end());
            if (str_set.count(str_backup) == 0) {
                str_set[str_backup] = anagrams_group.size();
                anagrams_group.push_back({});
            }
            anagrams_group[str_set[str_backup]].emplace_back(str);
        }
        return anagrams_group;
    }
};

int main() {
    Solution solu;
    vector<string> strs = {"ddddddddddg","dgggggggggg"};
    vector<vector<string>> result = solu.groupAnagrams(strs);
    for (auto& l : result) {
        for (string& e : l) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}