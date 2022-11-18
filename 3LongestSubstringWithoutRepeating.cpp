#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char> charset;
       int l = 0, r = 0;
       int longest_length = 0;
       while(r < s.size()) {
            if (charset.count(s[r]) != 0) {
                while(s[l] != s[r]) {
                    charset.erase(s[l]);
                    ++l;
                }
                charset.erase(s[l]);
                ++l;
            }
            charset.insert(s[r]);
            longest_length = max(longest_length, r-l+1);
            ++r;
       }
       return longest_length;
    }
};

int main() {
    string s = "a";
    Solution solu;
    cout << solu.lengthOfLongestSubstring(s) <<endl;
    return 0;
}