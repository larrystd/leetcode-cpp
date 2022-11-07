/**
 * double pointer
 * easy to implement
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        while (l < r) {
            max_area = max(min(height[l], height[r]) * (r - l), max_area);
            if (height[l] < height[r]) {  // when l < r, only a channce that l++ would better than the case
                l++;
            }else {
                r--;
            }
        }
        return max_area;
    }
};