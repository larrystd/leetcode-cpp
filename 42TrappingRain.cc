#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> height_stack;
        int left_max = height[0];
        int trapped_water = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > height[i-1] && left_max > height[i-1]) {
                int j = i -1;
                int border_height = min(left_max,height[i]);
                while (j>=0 && height[j]<border_height) {
                    trapped_water += (border_height-height[j]);
                    height[j] = border_height;
                    j--;
                }
            }
            left_max = max(left_max, height[i]);
        }
        return trapped_water;
    }
};

int main() {
    vector<int> height{4,2,4};
    Solution solu;
    cout << solu.trap(height) << endl;

    return 0;
}